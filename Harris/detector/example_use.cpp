// =============================================================================
//  example_use.cpp —— 演示"只引入 cube_pose.hpp 就能调识别/测距"的用法
//
//  编译（和库一起）：
//    g++ -O3 example_use.cpp cube_pose.cpp $(pkg-config --cflags --libs opencv4) -o example_use
//  运行：
//    ./example_use synth_test/s1.png
// =============================================================================
#include "cube_pose.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    string imgPath = argc > 1 ? argv[1] : "synth_test/s1.png";

    cv::Mat frame = cv::imread(imgPath);
    if (frame.empty()) { cerr << "读不到图片: " << imgPath << endl; return 1; }

    // ---------------------------------------------------------------------
    // 1) 创建识别器并读 YAML 参数（不读也行，用结构体默认值）
    // ---------------------------------------------------------------------
    cubepose::CubePoseDetector detector;
    if (detector.loadConfig("cube_pose.yaml"))
        cout << "[1] 已从 cube_pose.yaml 读入参数\n";
    else
        cout << "[1] 未找到 cube_pose.yaml，用默认参数\n";

    // 也可以直接在代码里改：
    cubepose::CubePoseParams p = detector.params();
    p.cubeSize = 0.05;          // 实物边长(m) —— 不填对绝对尺度就错
    p.fx = 1000; p.fy = 1000;   // 内参（实际项目请用棋盘格标定值）
    p.cx = frame.cols * 0.5;
    p.cy = frame.rows * 0.5;
    p.buildDebugImage = true;   // 想要可视化结果就打开
    detector.setParams(p);

    // ---------------------------------------------------------------------
    // 2) 识别。ROI 可给可不给：
    //    - 有 YOLO 就用它的检测框，又快又稳（推荐）
    //    - 没有就传 cv::Rect()，程序会全图搜索 + 自动选候选区域
    // ---------------------------------------------------------------------
    cv::Rect yoloBox;                    // = YOLO 输出的框；这里留空表示没有
    cubepose::CubePoseResult r = detector.detect(frame, yoloBox);
    if (!r.ok) { cout << "[2] 识别失败: " << r.msg << endl; return 2; }
    cout << "[2] 识别成功: " << r.msg << "  顶点数=" << r.nVerts
         << "  重投影RMS=" << fixed << setprecision(3) << r.reprojRms << "px"
         << "  距离=" << r.centerDist << "m\n";

    // ---------------------------------------------------------------------
    // 3) 测距（最常用的三个量）
    // ---------------------------------------------------------------------
    cout << "[3] 相机 -> 立方体中心      : " << r.centerDist * 1000 << " mm\n";
    cout << "    相机 -> 朝上那个平面     : "
         << (r.findFace("up") ? r.findFace("up")->distToPlane() * 1000 : -1) << " mm\n";
    cv::Point3d c = r.center;
    cout << "    立方体中心坐标(x,y,z)   : (" << c.x << ", " << c.y << ", " << c.z << ") m\n";

    // ---------------------------------------------------------------------
    // 4) 角点的物理位置（相机坐标系，单位 m）
    //    角点号 j：bit0->x 正负, bit1->y 正负, bit2->z 正负；j>=4 的 4 个角是顶面四角
    // ---------------------------------------------------------------------
    cout << "[4] 8 个角点物理位置（相机系, mm）:\n";
    for (size_t j = 0; j < r.cornersCam.size(); ++j)
        printf("    corner#%zu = (%7.2f, %7.2f, %7.2f)   距相机 %7.2f\n", j,
               r.cornersCam[j].x * 1000, r.cornersCam[j].y * 1000, r.cornersCam[j].z * 1000,
               cv::norm(r.cornersCam[j]) * 1000);

    cout << "    检测到的每个图像顶点对应的角点号与物理位置:\n";
    for (size_t i = 0; i < r.verts.size(); ++i)
        printf("      像素(%.1f, %.1f) -> 角点#%d -> (%.2f, %.2f, %.2f) mm\n",
               r.verts[i].x, r.verts[i].y, r.vertexCornerId[i],
               r.vertexPos3D[i].x * 1000, r.vertexPos3D[i].y * 1000, r.vertexPos3D[i].z * 1000);

    cout << "    近角(离相机最近) = (" << r.nearCorner.x * 1000 << ", "
         << r.nearCorner.y * 1000 << ", " << r.nearCorner.z * 1000 << ") mm\n";
    cout << "    被自身挡住的角   = (" << r.hiddenCorner.x * 1000 << ", "
         << r.hiddenCorner.y * 1000 << ", " << r.hiddenCorner.z * 1000 << ") mm\n";

    // ---------------------------------------------------------------------
    // 5) 平面信息
    // ---------------------------------------------------------------------
    cout << "[5] 可见面（平面方程 n·X = d，X 为相机系坐标）:\n";
    for (const auto& f : r.faces)
        printf("    %-4s n=(%6.3f,%6.3f,%6.3f)  d=%8.4f m  相机到平面=%6.1f mm\n",
               f.name.c_str(), f.n[0], f.n[1], f.n[2], f.d, f.distToPlane() * 1000);

    // ---------------------------------------------------------------------
    // 6) 把任意像素投到某个平面上 -> 得到那个点的物理坐标（"测距"的另一种用法）
    // ---------------------------------------------------------------------
    cv::Point2d px(frame.cols * 0.5, frame.rows * 0.5);   // 比如图像正中心
    cv::Point3d hit;
    if (r.pixelToTopPlane(px, hit))
        printf("[6] 像素(%.0f,%.0f) 投到顶面 -> (%.1f, %.1f, %.1f) mm，距相机 %.1f mm\n",
               px.x, px.y, hit.x * 1000, hit.y * 1000, hit.z * 1000, cv::norm(hit) * 1000);
    else
        cout << "[6] 该像素的光线没有打到顶面\n";

    // ---------------------------------------------------------------------
    // 7) 想看结果就存下来（也可以直接 r.debugImage 拿去 imshow）
    // ---------------------------------------------------------------------
    if (!r.debugImage.empty()) {
        cv::imwrite("example_debug.png", r.debugImage);
        cout << "[7] 调试图已保存: example_debug.png\n";
    }
    return 0;
}
