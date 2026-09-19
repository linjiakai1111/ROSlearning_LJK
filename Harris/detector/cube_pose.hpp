// =============================================================================
//  cube_pose.hpp —— 单目立方体识别 / 测距 / 平面提取  公共接口
//
//  算法一句话：用"立方体投影必然是凸六边形"这一事实，
//    在 YOLO 给的 ROI（可选）里分割出立方体轮廓 -> 取凸包 -> 把凸包拆成若干
//    直线段 -> 相邻直线求交得到 6 个亚像素、且天然有序的顶点 ->
//    与已知边长的立方体模型做 PnP 解算 -> 得到 6DoF 位姿、平面方程、角点物理坐标。
//
//  典型用法：
//    #include "cube_pose.hpp"
//    cubepose::CubePoseDetector det;          // 会自动读 cube_pose.yaml（若存在）
//    det.loadConfig("cube_pose.yaml");
//
//    cv::Mat frame = ...;                     // BGR
//    auto r = det.detect(frame);              // 不给 ROI = 全图自动搜索
//    auto r = det.detect(frame, roi);         // 给 ROI = 只在框内找（YOLO 用这个）
//    if (r.ok) {
//        double d = r.centerDist;             // 相机到立方体中心的距离(m)
//        cv::Point3d p = r.vertexPos3D[0];    // 第 0 个角点的物理位置(m, 相机系)
//        cv::Point3d c = r.cornersCam[7];     // 8 个角点里第 7 号（模型角点号）
//        for (auto& f : r.faces)              // 3 个可见面：法向 + 平面方程
//            printf("%s n=(%.3f,%.3f,%.3f) n·X=%.4f 距离=%.4f\n",
//                   f.name.c_str(), f.n[0], f.n[1], f.n[2], f.d, f.distToPlane());
//        cv::Point3d hit;
//        if (r.pixelToTopPlane(cv::Point2d(u, v), hit))   // 像素投到"朝上的面"上
//            printf("该像素对应平面上 %.3f, %.3f, %.3f m\n", hit.x, hit.y, hit.z);
//    }
//
//  编译（库 + 命令行工具）：
//    g++ -O3 -march=native -c cube_pose.cpp $(pkg-config --cflags opencv4) -o cube_pose.o
//    g++ -O3 -march=native -c cube_pose_main.cpp $(pkg-config --cflags opencv4) -o cube_pose_main.o
//    g++ cube_pose.o cube_pose_main.o $(pkg-config --libs opencv4) -o cube_pose
// =============================================================================

#ifndef CUBE_POSE_HPP
#define CUBE_POSE_HPP

#include <opencv2/core.hpp>
#include <string>
#include <vector>

namespace cubepose {

// -----------------------------------------------------------------------------
// 参数（全部可通过 YAML 文件配置，见 cube_pose.yaml）
// -----------------------------------------------------------------------------
struct CubePoseParams {
    // ---- 立方体本身 ----
    double cubeSize = 0.05;      // 实物边长(m)。【必须按实物改】它决定距离/平面的绝对尺度
    double tiltDeg  = 20.0;      // 相机向下俯仰角(度)。只用于判断"哪个面朝上"

    // ---- ROI ----
    cv::Rect roi;                // 可直接在这里给 ROI；等价于 detect(frame, roi)
    double roiPad   = 0.15;      // ROI 自动外扩比例。YOLO 框通常贴得很紧，
                                 // 不加外扩会把立方体轮廓切掉，导致顶点数不对
    bool   autoRoi  = true;      // 未传 ROI 时：全图 + 多分割候选自动搜索

    // ---- 分割（找出立方体区域）----
    int    segMode  = 0;         // 0=自动选优 1=Otsu 2=自适应阈值 3=Canny+闭运算 4=Lab色差
    bool   invert   = false;     // 只对 segMode=1 有意义：目标比背景暗时置 1
    double minAreaRatio = 0.02;  // 轮廓面积/ROI面积 下限，滤掉小噪点

    // ---- 轮廓 -> 直线段 ----
    double splitTol = 1.2;       // 直线拆分残差阈值(px)：越小越敏感，越大越"懒得拆"
    int    minRunLen = 12;       // 直线段最短长度(px)
    double mergeAngleDeg = 12.0; // 相邻直线段方向差小于该值就合并(度)

    // ---- 亚像素 ----
    bool   subpix = true;        // 用灰度梯度把边界精化到亚像素
    double subpixRange = 2.5;    // 沿法向搜索范围(px)

    // ---- 相机内参 ----
    // 建议用棋盘格标定后填这里（或填 calibFile）。
    // 不填会按 fx≈W/(2·tan30°) 粗估，此时"绝对距离"不可信。
    double fx = 0, fy = 0, cx = 0, cy = 0;
    std::string calibFile;       // 也可以读 OpenCV 标定结果文件(camera_matrix / fx,fy,cx,cy)

    // ---- 调试 ----
    bool   buildDebugImage = false; // 是否生成 result.debugImage（叠加了掩膜/顶点/可见面）
    std::string debugPath;          // 非空则 detect() 额外把调试图写到该路径
    bool   verbose = false;         // 打印各分割候选与拟合过程的诊断信息

    bool loadFromYaml(const std::string& path);   // 读配置，成功返回 true
    bool saveToYaml(const std::string& path) const; // 写一份带注释的配置模板
};

// -----------------------------------------------------------------------------
// 一个可见面（平面）
//   平面方程： n·X = d        （X 为相机系坐标，单位 m）
//   n 是立方体"朝外"的单位法向；可见面的 n 指向相机，所以 d < 0，
//   因此"相机到该平面的距离" = |d| = distToPlane()
// -----------------------------------------------------------------------------
struct CubePoseFace {
    std::string name;                      // "up"（朝上）/ "+x","-x","+y","-y" / "face"
    cv::Vec3d   n{0, 0, 0};                // 单位外法向（相机系）
    double      d = 0;                     // 平面方程 n·X = d
    cv::Point3d center{0, 0, 0};           // 面心（相机系, m）
    std::vector<cv::Point2d> imgCorners;   // 该面在图像上的 4 个角点(全图坐标)
    double distToPlane() const { return d < 0 ? -d : d; }
};

// -----------------------------------------------------------------------------
// 识别结果
// -----------------------------------------------------------------------------
struct CubePoseResult {
    bool        ok = false;                // 是否成功
    std::string msg;                       // 说明（含胜出的假设编号，便于排查）
    int         nVerts = 0;                // 检出的轮廓顶点数（正常立方体三面可见 = 6）
    std::vector<cv::Point2d> verts;        // 有序的亚像素轮廓顶点（全图坐标, px）
    bool        isCube = false;            // true=六边形(三面可见)  false=单面(4 顶点, 正对相机)

    // ---- 位姿：模型系 = 立方体中心为原点、边长 cubeSize ----
    //   +z = 朝上那个面的外法向；+x = 朝图像右侧那个侧面的外法向（三个轴都是立方体的棱方向）
    cv::Mat   rvec, tvec;                  // 旋转向量(3x1) / 平移(3x1, = 立方体中心)
    cv::Vec3d center{0, 0, 0};             // 立方体中心（相机系, m）
    double    centerDist = -1;             // = |center|，相机到立方体中心的距离(m)
    cv::Vec3d topNormal{0, 0, 0};          // 朝上面的外法向（相机系）
    double    yawDeg = 0;                  // 偏航角(度)：图像右方向在顶面的投影 与 +x 棱的夹角

    // ---- 平面（3 个可见面；单面情况只有 1 个）----
    std::vector<CubePoseFace> faces;
    // 三个可见面各自的图像角点（画"内部 Y 型棱"用，与 faces 顺序一致）
    std::vector<std::vector<cv::Point2d>> visibleFaces;
    int       topFace = -1;                // 判断为"朝上"的那个面在 faces 里的下标
    const CubePoseFace* findFace(const std::string& name) const {
        for (const auto& f : faces) if (f.name == name) return &f;
        return nullptr;
    }

    // ---- 角点物理位置（相机系, m）----
    // 角点编号 j = 0..7，按位定义：j&1 -> x 正负, j&2 -> y 正负, j&4 -> z 正负
    // 于是在"规范化模型系"里： j>=4 的 4 个点是顶面（朝上的面）的 4 个角。
    std::vector<cv::Point3d> cornersCam;   // 8 个角点的物理位置（下标即角点号）
    std::vector<int>         vertexCornerId; // verts[i] 对应的角点号(0..7)
    std::vector<cv::Point3d> vertexPos3D;  // verts[i] 对应的物理位置(m)
    cv::Point3d nearCorner{0, 0, 0};       // 离相机最近、三个可见面共用的角点
    cv::Point3d hiddenCorner{0, 0, 0};     // 被立方体自身挡住的那个角点

    cv::Mat K;                             // 本次实际使用的内参(3x3 CV_64F)

    // ---- 质量指标（用于判断这一次结果可不可信）----
    double reprojRms = -1;                 // 6 个顶点与立方体模型的重投影 RMS(px)，越小越好
    double edgeSupport = -1;               // 拟合多边形压在实际图像边缘上的比例(0~1)
    double hullSolidity = -1;              // 轮廓面积/凸包面积，立方体应接近 1
    double axisOrthoErr = -1;              // 三个可见面法向的正交性误差，应接近 0
    double canonConsist = -1;              // 可见面法向与规范化坐标轴的最大夹角(度)，应接近 0
    std::vector<std::pair<int, double>> hypRms;  // 每个候选假设的总分（排查用）

    // ---- 调试 ----
    cv::Mat mask;                          // 胜出的分割掩膜（ROI 尺寸）
    cv::Mat debugImage;                    // 调试图（需 params.buildDebugImage=true）
    double tSeg = 0, tFit = 0, tPnp = 0, tTotal = 0;   // 各阶段耗时(ms)
    double solveScore = 1e18;

    // ---- 便捷工具：把图像上的像素投到某个平面上，得到物理坐标 ----
    bool pixelToPlane(const cv::Point2d& pixel, const CubePoseFace& f, cv::Point3d& out) const;
    bool pixelToPlane(const cv::Point2d& pixel, int faceIndex, cv::Point3d& out) const;
    bool pixelToTopPlane(const cv::Point2d& pixel, cv::Point3d& out) const;  // 投到"朝上的面"
};

// -----------------------------------------------------------------------------
// 识别器。可复用（内部保存跨帧的"假设粘滞"状态，利于实时跟踪）
// -----------------------------------------------------------------------------
class CubePoseDetector {
public:
    explicit CubePoseDetector(const CubePoseParams& p = CubePoseParams()) : params_(p) {}

    void setParams(const CubePoseParams& p) { params_ = p; }
    const CubePoseParams& params() const { return params_; }

    // 读取 YAML 配置。若 path 为空，会尝试读当前目录的 cube_pose.yaml
    bool loadConfig(const std::string& yamlPath = std::string());

    // 主接口。roi 为空(cv::Rect())时按 params.autoRoi 决定是否全图搜索
    CubePoseResult detect(const cv::Mat& bgr, const cv::Rect& roi = cv::Rect());

    // 只要距离(m)：识别失败返回 -1
    double distance(const cv::Mat& bgr, const cv::Rect& roi = cv::Rect());

    // 换目标/丢失目标时清掉跨帧状态
    void reset() { sticky_ = -1; }

private:
    CubePoseParams params_;
    int sticky_ = -1;
};

// -----------------------------------------------------------------------------
// 通用工具：像素 + 平面 -> 3D 点（相机光线与平面求交）
//   K     : 3x3 内参
//   pixel : 像素坐标（与 K 同一坐标系，即全图坐标）
//   n, d  : 平面方程 n·X = d
//   返回 false 表示该像素的光线与平面不相交在相机前方
// -----------------------------------------------------------------------------
bool rayPlaneIntersect(const cv::Mat& K, const cv::Point2d& pixel,
                       const cv::Vec3d& n, double d, cv::Point3d& out);

} // namespace cubepose

#endif // CUBE_POSE_HPP
