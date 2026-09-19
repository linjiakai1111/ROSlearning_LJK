// =============================================================================
//  gen_synth.cpp —— 生成"带真值"的合成立方体图，用于严格验证 cube_pose.cpp
//  场景刻意模仿真实条件：立方体边界对比强，但每个面内部有黑色毛笔字形花纹
//  （部分花纹故意贴到棱边上），背景是带噪声的渐变。
//  编译： g++ -O2 gen_synth.cpp $(pkg-config --cflags --libs opencv4) -o gen_synth
//  用法： ./gen_synth <seed> [outprefix]
//  输出： <prefix>.png  场景图
//         <prefix>.txt  真值（内参/边长/位姿/6 个轮廓顶点/3 个可见面）
//         <prefix>_gt.png 真值叠加图（人工检查用）
// =============================================================================
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace cv;
using namespace std;

static const int SS = 4;   // 超采样倍数

int main(int argc, char** argv) {
    int seed = argc > 1 ? atoi(argv[1]) : 1;
    string prefix = argc > 2 ? argv[2] : ("synth" + to_string(seed));
    RNG rng(seed);

    int W = 1280, H = 720;
    double fx = 1000, fy = 1000, cx = W/2.0, cy = H/2.0;
    double s = 0.05;

    Mat K = (Mat_<double>(3,3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);

    // 立方体顶点（中心在原点）：bit0=x, bit1=y, bit2=z
    vector<Point3d> V;
    for (int i = 0; i < 8; ++i)
        V.push_back(Point3d((i&1?0.5:-0.5)*s, (i&2?0.5:-0.5)*s, (i&4?0.5:-0.5)*s));

    // 随机位姿：保证三个面可见（欧拉角都在 15~40 度之间）
    auto u = [&](double a, double b) { return a + (b-a) * rng.uniform(0.0, 1.0); };
    double ax = u(15, 40) * CV_PI/180 * (rng.uniform(0,1) < 0.5 ? -1 : 1);
    double ay = u(15, 40) * CV_PI/180 * (rng.uniform(0,1) < 0.5 ? -1 : 1);
    double az = u(0, 90)  * CV_PI/180;
    Mat Rx = (Mat_<double>(3,3) << 1,0,0, 0,cos(ax),-sin(ax), 0,sin(ax),cos(ax));
    Mat Ry = (Mat_<double>(3,3) << cos(ay),0,sin(ay), 0,1,0, -sin(ay),0,cos(ay));
    Mat Rz = (Mat_<double>(3,3) << cos(az),-sin(az),0, sin(az),cos(az),0, 0,0,1);
    Mat R = Rz * Ry * Rx;
    Mat rvec; Rodrigues(R, rvec);
    double tz = u(0.28, 0.42);
    Mat tvec = (Mat_<double>(3,1) << u(-0.04,0.04), u(-0.03,0.03), tz);

    // 投影
    vector<Point2d> img;
    projectPoints(V, rvec, tvec, K, Mat(), img);

    // 顶点可见性：其三个相邻面都正面朝向相机 -> near；都背面 -> hidden
    static const int faceV[6][4] = {
        {0,2,6,4}, {1,3,7,5},   // -x, +x
        {0,1,5,4}, {2,3,7,6},   // -y, +y
        {0,1,3,2}, {4,5,7,6}    // -z, +z
    };
    static const Point3d faceN[6] = {
        Point3d(-1,0,0), Point3d(1,0,0), Point3d(0,-1,0),
        Point3d(0,1,0), Point3d(0,0,-1), Point3d(0,0,1)
    };
    vector<Point3d> Vc;   // 相机系顶点
    for (auto& p : V) {
        Mat pc = R * (Mat_<double>(3,1) << p.x, p.y, p.z) + tvec;
        Vc.push_back(Point3d(pc.at<double>(0), pc.at<double>(1), pc.at<double>(2)));
    }
    vector<int> visFaces;
    for (int f = 0; f < 6; ++f) {
        Point3d cen(0,0,0);
        for (int k = 0; k < 4; ++k) cen += Vc[faceV[f][k]];
        cen *= 0.25;
        Mat nc = R * (Mat_<double>(3,1) << faceN[f].x, faceN[f].y, faceN[f].z);
        Point3d n(nc.at<double>(0), nc.at<double>(1), nc.at<double>(2));
        if (n.dot(cen) < 0) visFaces.push_back(f);   // 外法向朝相机 -> 可见
    }
    if (visFaces.size() != 3) { cerr << "位姿退化（可见面数=" << visFaces.size() << "），换 seed\n"; return 1; }

    int nearV = -1, hiddenV = -1;
    for (int v = 0; v < 8; ++v) {
        int front = 0, back = 0;
        for (int f = 0; f < 6; ++f) {
            bool in = false;
            for (int k = 0; k < 4; ++k) if (faceV[f][k] == v) in = true;
            if (!in) continue;
            Point3d cen(0,0,0);
            for (int k = 0; k < 4; ++k) cen += Vc[faceV[f][k]];
            cen *= 0.25;
            Mat nc = R * (Mat_<double>(3,1) << faceN[f].x, faceN[f].y, faceN[f].z);
            Point3d n(nc.at<double>(0), nc.at<double>(1), nc.at<double>(2));
            if (n.dot(cen) < 0) front++; else back++;
        }
        if (front == 3) nearV = v;
        if (back == 3)  hiddenV = v;
    }
    if (nearV < 0 || hiddenV < 0) { cerr << "无法确定 near/hidden 顶点\n"; return 1; }

    // 6 个轮廓顶点 = 除 near/hidden 之外的 6 个
    vector<int> hex;
    for (int v = 0; v < 8; ++v) if (v != nearV && v != hiddenV) hex.push_back(v);
    if (hex.size() != 6) { cerr << "轮廓顶点数异常\n"; return 1; }

    // ---------------- 4x 超采样渲染（边缘定位精度远好于 0.1px）----------------
    int W2 = W * SS, H2 = H * SS;
    Mat bg(H2, W2, CV_8UC3);
    for (int y = 0; y < H2; ++y) {
        int v = (int)(60 + 60.0 * y / H2);
        bg.row(y).setTo(Scalar(v*0.90, v*0.95, v));
    }
    for (int i = 0; i < 6; ++i) {
        Point c((int)(rng.uniform(0, W) * SS), (int)(rng.uniform(0, H) * SS));
        int rr = (int)(rng.uniform(60, 200) * SS);
        circle(bg, c, rr, Scalar(rng.uniform(40,120), rng.uniform(40,120), rng.uniform(40,120)), FILLED);
    }
    GaussianBlur(bg, bg, Size(63, 63), 0);
    Mat scene = bg.clone();

    double faceLevel[3] = {u(175,220), u(155,200), u(140,185)};
    for (size_t i = 0; i < visFaces.size(); ++i) {
        int f = visFaces[i];
        vector<Point> poly;
        for (int k = 0; k < 4; ++k)
            poly.push_back(Point((int)std::lround(img[faceV[f][k]].x * SS),
                                 (int)std::lround(img[faceV[f][k]].y * SS)));
        double L = faceLevel[i];
        fillConvexPoly(scene, poly, Scalar(L*0.95, L, L*1.02), LINE_AA);

        Mat faceMask = Mat::zeros(scene.size(), CV_8UC1);
        fillConvexPoly(faceMask, poly, Scalar(255), LINE_AA);

        Mat layer = Mat::zeros(scene.size(), CV_8UC3);
        Point2f p0(img[faceV[f][0]].x*SS, img[faceV[f][0]].y*SS);
        Point2f q0(img[faceV[f][1]].x*SS, img[faceV[f][1]].y*SS);
        Point2f p1(img[faceV[f][2]].x*SS, img[faceV[f][2]].y*SS);
        auto rndIn = [&]() {
            double a = rng.uniform(0.0, 1.0), b = rng.uniform(0.0, 1.0);
            if (a + b > 1) { a = 1-a; b = 1-b; }
            return p0 + (q0 - p0) * (float)a + (p1 - p0) * (float)b;
        };
        int nStroke = rng.uniform(2, 5);
        for (int k = 0; k < nStroke; ++k) {
            vector<Point> pl;
            int nn = rng.uniform(3, 6);
            for (int j = 0; j < nn; ++j) {
                Point2f rp = rndIn();
                pl.push_back(Point((int)rp.x, (int)rp.y));
            }
            polylines(layer, pl, false, Scalar(10,10,10), (int)(rng.uniform(3,8) * SS), LINE_AA);
        }
        if (rng.uniform(0,1) < 0.6) {   // 贴边花纹：故意压到棱上
            vector<Point> se{Point((int)(img[faceV[f][0]].x*SS), (int)(img[faceV[f][0]].y*SS)),
                             Point((int)(img[faceV[f][1]].x*SS), (int)(img[faceV[f][1]].y*SS))};
            polylines(layer, se, false, Scalar(10,10,10), (int)(rng.uniform(3,6) * SS), LINE_AA);
        }
        layer.copyTo(scene, faceMask);
    }
    {
        Mat small; resize(scene, small, Size(W, H), 0, 0, INTER_AREA); scene = small;
    }
    {
        Mat n2(H, W, CV_8UC3);
        randu(n2, Scalar(0,0,0), Scalar(12,12,12));
        scene -= n2 * 0.5;
    }

    imwrite(prefix + ".png", scene);
    vector<int> jp(2); jp[0] = IMWRITE_JPEG_QUALITY; jp[1] = 88;
    imwrite(prefix + ".jpg", scene, jp);

    // 真值叠加图
    Mat ov = scene.clone();
    for (int i = 0; i < 6; ++i) {
        Point2d a = img[hex[i]], b = img[hex[(i+1)%6]];
        line(ov, a, b, Scalar(0,255,0), 2, LINE_AA);
    }
    for (int i = 0; i < 6; ++i) circle(ov, img[hex[i]], 5, Scalar(0,0,255), -1);
    circle(ov, img[nearV], 6, Scalar(0,255,255), -1);
    circle(ov, img[hiddenV], 6, Scalar(255,0,255), -1);
    imwrite(prefix + "_gt.png", ov);

    // 真值文本
    ofstream fo(prefix + ".txt");
    fo << setprecision(12);
    fo << "width " << W << "\nheight " << H << "\n";
    fo << "fx " << fx << "\nfy " << fy << "\ncx " << cx << "\ncy " << cy << "\n";
    fo << "cubeSize " << s << "\n";
    fo << "rvec " << rvec.at<double>(0) << " " << rvec.at<double>(1) << " " << rvec.at<double>(2) << "\n";
    fo << "tvec " << tvec.at<double>(0) << " " << tvec.at<double>(1) << " " << tvec.at<double>(2) << "\n";
    fo << "nearImg " << img[nearV].x << " " << img[nearV].y << "\n";
    fo << "hiddenImg " << img[hiddenV].x << " " << img[hiddenV].y << "\n";
    for (int i = 0; i < 6; ++i)
        fo << "hex " << img[hex[i]].x << " " << img[hex[i]].y << "\n";
    for (int j = 0; j < 8; ++j)      // 8 个角点的相机系真值位置(m)
        fo << "corner3d " << Vc[j].x << " " << Vc[j].y << " " << Vc[j].z << "\n";
    for (int f : visFaces) {
        Point3d cen(0,0,0);
        for (int k = 0; k < 4; ++k) cen += Vc[faceV[f][k]];
        cen *= 0.25;
        Mat nc = R * (Mat_<double>(3,1) << faceN[f].x, faceN[f].y, faceN[f].z);
        Point3d n(nc.at<double>(0), nc.at<double>(1), nc.at<double>(2));
        n *= 1.0 / std::sqrt(n.dot(n));
        fo << "faceN " << n.x << " " << n.y << " " << n.z << " "
           << "d " << n.dot(cen) << "\n";
    }
    fo.close();

    cout << "生成 " << prefix << ".png/.jpg/.txt/_gt.png  可见面数=" << visFaces.size()
         << " near=" << nearV << " hidden=" << hiddenV << endl;
    for (int i = 0; i < 6; ++i)
        cout << "  hex" << i << " = (" << std::lround(img[hex[i]].x) << ", " << std::lround(img[hex[i]].y) << ")\n";
    return 0;
}
