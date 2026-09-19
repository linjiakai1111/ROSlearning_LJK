// =============================================================================
//  cube_pose_main.cpp —— 命令行外壳（真正的算法都在 cube_pose.cpp / cube_pose.hpp）
//
//  参数优先级：命令行 > YAML配置文件 > 代码默认值
//
//  常用：
//    ./cube_pose --config cube_pose.yaml image.jpg            # 用 yaml 里的参数跑一张图
//    ./cube_pose --config cube_pose.yaml image.jpg --roi 100,100,300,300
//    ./cube_pose --config cube_pose.yaml --camera 0           # 接相机
//    ./cube_pose --dump-yaml cube_pose.yaml                   # 生成带注释的配置模板
//
//  编译：
//    g++ -O3 -march=native cube_pose_main.cpp cube_pose.cpp $(pkg-config --cflags --libs opencv4) -o cube_pose
// =============================================================================
#include "cube_pose.hpp"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

static void usage(const char* exe) {
    cout << "用法: " << exe << " [图片|视频] [选项]\n"
         << "  --config FILE    YAML 配置文件（推荐；先读它，下面的选项可覆盖）\n"
         << "  --dump-yaml FILE 把当前参数写成带注释的 YAML 模板然后退出\n"
         << "  --camera N       打开相机 N / --gst STR 自定义 GStreamer 管线\n"
         << "  --size S         立方体边长(m)\n"
         << "  --tilt D         相机俯仰角(度)\n"
         << "  --roi x,y,w,h    YOLO 检测框（不给则全图自动搜索）\n"
         << "  --pad P          ROI 外扩比例\n"
         << "  --seg N          1=Otsu 2=自适应 3=Canny 4=Lab，0=自动\n"
         << "  --split T / --mergeAng D   直线拟合阈值\n"
         << "  --no-subpix      关亚像素精化\n"
         << "  --fx --fy --cx --cy / --calib file   内参\n"
         << "  --debug FILE     保存调试图\n"
         << "  --dumpSeg        打印分割/拟合诊断\n"
         << "  --nogui          不弹窗   --frames N  --repeat N\n";
}

int main(int argc, char** argv) {
    cubepose::CubePoseParams P;

    // 先扫一遍 --config，让 YAML 作为基线
    string cfgPath;
    for (int i = 1; i < argc; ++i) {
        string a = argv[i];
        if (a == "--config" && i + 1 < argc) cfgPath = argv[i+1];
    }
    if (!cfgPath.empty()) {
        if (!P.loadFromYaml(cfgPath))
            cerr << "[cube_pose] 无法读取配置: " << cfgPath << "（继续用默认值/命令行）\n";
        else
            cout << "[cube_pose] 已加载配置: " << cfgPath << endl;
    } else {
        // 没指定就尝试当前目录默认名
        try {
            FileStorage probe("cube_pose.yaml", FileStorage::READ);
            if (probe.isOpened()) {
                probe.release();
                if (P.loadFromYaml("cube_pose.yaml"))
                    cout << "[cube_pose] 已自动加载 cube_pose.yaml\n";
            }
        } catch (const cv::Exception&) { /* 文件不合法则忽略，用默认值 */ }
        // 注意：不填 cubeSize 也能跑，但绝对尺度会错，所以这里只做提示
    }

    string source = "cube01.jpg";
    int camera = -1, maxFrames = 0, repeat = 0;
    string gst, debugPath, calibFile, dumpYaml;
    bool noGui = false, wantRoi = false;
    Rect roi;
    long long segMsSum = 0; int nFrames = 0;

    for (int i = 1; i < argc; ++i) {
        string a = argv[i];
        auto need = [&](const char* nm)->string {
            if (i + 1 >= argc) { cerr << "缺少参数: " << nm << endl; exit(1); }
            return string(argv[++i]);
        };
        if      (a == "--config")   (void)need("--config");
        else if (a == "--dump-yaml") dumpYaml = need("--dump-yaml");
        else if (a == "--camera")   camera = stoi(need("--camera"));
        else if (a == "--gst")      gst = need("--gst");
        else if (a == "--size")     P.cubeSize = stod(need("--size"));
        else if (a == "--tilt")     P.tiltDeg = stod(need("--tilt"));
        else if (a == "--pad")      P.roiPad = stod(need("--pad"));
        else if (a == "--seg")      P.segMode = stoi(need("--seg"));
        else if (a == "--split")    P.splitTol = stod(need("--split"));
        else if (a == "--mergeAng") P.mergeAngleDeg = stod(need("--mergeAng"));
        else if (a == "--minRun")   P.minRunLen = stoi(need("--minRun"));
        else if (a == "--subpixR")  P.subpixRange = stod(need("--subpixR"));
        else if (a == "--no-subpix")P.subpix = false;
        else if (a == "--fx")       P.fx = stod(need("--fx"));
        else if (a == "--fy")       P.fy = stod(need("--fy"));
        else if (a == "--cx")       P.cx = stod(need("--cx"));
        else if (a == "--cy")       P.cy = stod(need("--cy"));
        else if (a == "--calib")    P.calibFile = need("--calib");
        else if (a == "--debug")    debugPath = need("--debug");
        else if (a == "--dumpSeg")  P.verbose = true;
        else if (a == "--nogui")    noGui = true;
        else if (a == "--frames")   maxFrames = stoi(need("--frames"));
        else if (a == "--repeat")   repeat = stoi(need("--repeat"));
        else if (a == "--invert")   P.invert = true;
        else if (a == "--no-autoroi") P.autoRoi = false;
        else if (a == "--help" || a == "-h") { usage(argv[0]); return 0; }
        else if (a == "--roi") {
            string s = need("--roi");
            for (auto& ch : s) if (ch == ',') ch = ' ';
            istringstream is(s);
            is >> roi.x >> roi.y >> roi.width >> roi.height;
            wantRoi = (roi.width > 0 && roi.height > 0);
        }
        else if (!a.empty() && a[0] == '-') { cerr << "未知选项: " << a << endl; usage(argv[0]); return 1; }
        else source = a;
    }

    if (!debugPath.empty()) P.debugPath = debugPath;
    if (!P.debugPath.empty()) P.buildDebugImage = true;
    if (P.buildDebugImage) P.buildDebugImage = true;

    if (!dumpYaml.empty()) {
        if (P.saveToYaml(dumpYaml)) cout << "已写出配置模板: " << dumpYaml << endl;
        else                       cerr << "写入失败: " << dumpYaml << endl;
        return 0;
    }

    // ---- 打开数据源 ----
    VideoCapture cap;
    bool isStream = false;
    Mat first;
    if (camera >= 0) {
        if (!gst.empty()) cap.open(gst, CAP_GSTREAMER);
        else              cap.open(camera);
        if (!cap.isOpened()) { cerr << "无法打开相机 " << camera << endl; return 1; }
        isStream = true;
        cap >> first;
    } else {
        string low = source;
        for (auto& c : low) c = (char)tolower(c);
        bool isVideo = low.size() > 4 && (low.substr(low.size()-4) == ".mp4" ||
                                          low.substr(low.size()-4) == ".avi" ||
                                          low.substr(low.size()-4) == ".mkv");
        if (isVideo) {
            cap.open(source);
            if (!cap.isOpened()) { cerr << "无法打开视频 " << source << endl; return 1; }
            isStream = true;
            cap >> first;
        } else {
            first = imread(source);
            if (first.empty()) { cerr << "无法读取图片 " << source << endl; return 1; }
        }
    }
    if (first.empty()) { cerr << "空帧" << endl; return 1; }

    cubepose::CubePoseDetector det(P);
    cout << "图像 " << first.cols << "x" << first.rows
         << "  cubeSize=" << P.cubeSize << "m tilt=" << P.tiltDeg << "deg"
         << "  seg=" << (P.segMode ? to_string(P.segMode) : string("auto"))
         << (wantRoi ? "  ROI=给定" : "  ROI=自动") << endl;

    int idx = 0;
    Mat frame = first;
    while (true) {
        cubepose::CubePoseResult R = wantRoi ? det.detect(frame, roi) : det.detect(frame);

        cout << "---- frame " << idx << " ----" << endl;
        cout << "  顶点数=" << R.nVerts << "  solidity=" << fixed << setprecision(3) << R.hullSolidity
             << "  " << R.msg << endl;
        for (size_t i = 0; i < R.verts.size(); ++i)
            cout << "   v" << i << "=(" << setprecision(2) << R.verts[i].x << "," << R.verts[i].y << ")"
                 << (i < R.vertexCornerId.size()
                     ? "  -> 角点#" + to_string(R.vertexCornerId[i]) : string("")) << endl;
        if (R.ok) {
            cout << fixed << setprecision(6);
            cout << "  重投影RMS=" << R.reprojRms << "px  中心距离=" << R.centerDist << "m"
                 << "  轮廓边支持=" << R.edgeSupport << "  正交误差=" << R.axisOrthoErr
                 << "  规范化一致性=" << R.canonConsist << endl;
            cout << "  立方体中心 t=[" << R.center[0] << ", " << R.center[1] << ", " << R.center[2] << "] m\n"
                 << "  朝上法向=[" << R.topNormal[0] << ", " << R.topNormal[1] << ", " << R.topNormal[2]
                 << "]  偏航=" << R.yawDeg << "度\n";
            for (auto& f : R.faces)
                cout << "   平面[" << f.name << "] n=[" << f.n[0] << ", " << f.n[1] << ", " << f.n[2]
                     << "]  n·X=" << f.d << "  相机到平面=" << f.distToPlane() << "m"
                     << "  面心距=" << std::sqrt(f.center.dot(f.center)) << "m" << endl;
            cout << "  角点物理位置(相机系, m)  编号 j：bit0=x, bit1=y, bit2=z；j>=4 为顶面四角\n";
            for (size_t j = 0; j < R.cornersCam.size(); ++j)
                cout << "   corner#" << j << " = [" << R.cornersCam[j].x << ", " << R.cornersCam[j].y
                     << ", " << R.cornersCam[j].z << "]" << endl;
            cout << "  近角=[" << R.nearCorner.x << ", " << R.nearCorner.y << ", " << R.nearCorner.z
                 << "]  被遮挡角=[" << R.hiddenCorner.x << ", " << R.hiddenCorner.y << ", "
                 << R.hiddenCorner.z << "]" << endl;
            cout << setprecision(3) << "  假设(总分):";
            for (auto& h : R.hypRms) cout << " " << h.first << ":" << setprecision(2) << h.second;
            cout << endl;
        }
        cout << "  耗时(ms): seg=" << setprecision(2) << R.tSeg << " fit=" << R.tFit
             << " pnp=" << R.tPnp << " total=" << R.tTotal << endl;

        segMsSum += (long long)R.tTotal; nFrames++;

        if (!R.debugImage.empty()) {
            if (!P.debugPath.empty()) { imwrite(P.debugPath, R.debugImage); cout << "  调试图: " << P.debugPath << endl; }
            if (!noGui) imshow("cube_pose", R.debugImage);
        } else if (!noGui) {
            imshow("cube_pose", frame);
        }
        if (!noGui) {
            int k = waitKey(isStream ? 1 : 0);
            if (k == 27) break;
        }

        if (!isStream && idx + 1 < repeat) { idx++; continue; }
        if (!isStream) break;
        idx++;
        if (maxFrames > 0 && idx >= maxFrames) break;
        if (!cap.read(frame) || frame.empty()) break;
    }
    if (nFrames > 0)
        cout << "平均每帧 " << (double)segMsSum / nFrames << " ms（" << nFrames << " 帧）" << endl;
    return 0;
}
