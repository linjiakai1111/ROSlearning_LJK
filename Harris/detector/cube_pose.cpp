// =============================================================================
//  cube_pose.cpp —— 实现。公共接口/用法见 cube_pose.hpp
// =============================================================================
#include "cube_pose.hpp"

#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace cv;
using namespace std;

namespace cubepose {
namespace {

// 内部沿用原来的短名字，避免大改已验证过的实现
typedef CubePoseParams Params;
typedef CubePoseFace   Face;
typedef CubePoseResult Result;

// 相机俯仰角（由 params.tiltDeg 在 detect() 时赋给全局，供内部函数使用）
static double g_tiltDeg = 20.0;
static inline double upVectorTilt() { return g_tiltDeg * CV_PI / 180.0; }
static double minLenThreshold(double tol) { return std::max(6.0, tol * 8.0); }

struct State { int sticky = -1; };  // 实时用：记住上一帧胜出的假设，下一帧先试它

// ----------------------------------------------------------------------------
// 基础工具
// ----------------------------------------------------------------------------
static inline double bilinear(const Mat& f, double x, double y) {
    int x0 = (int)std::floor(x), y0 = (int)std::floor(y);
    if (x0 < 0 || y0 < 0 || x0 + 1 >= f.cols || y0 + 1 >= f.rows) return 0.0;
    double ax = x - x0, ay = y - y0;
    const float* r0 = f.ptr<float>(y0);
    const float* r1 = f.ptr<float>(y0 + 1);
    return (1-ax)*(1-ay)*r0[x0] + ax*(1-ay)*r0[x0+1] + (1-ax)*ay*r1[x0] + ax*ay*r1[x0+1];
}

// 总最小二乘直线（手写 2x2 特征分解，不依赖 Eigen）
static void tlsLine(const vector<Point2d>& pts, Vec2d& dir, Point2d& c) {
    double mx = 0, my = 0;
    for (const auto& p : pts) { mx += p.x; my += p.y; }
    mx /= (double)pts.size(); my /= (double)pts.size();
    double sxx = 0, syy = 0, sxy = 0;
    for (const auto& p : pts) {
        double dx = p.x - mx, dy = p.y - my;
        sxx += dx*dx; syy += dy*dy; sxy += dx*dy;
    }
    double tr = sxx + syy;
    double disc = std::sqrt(std::max(0.0, tr*tr*0.25 - (sxx*syy - sxy*sxy)));
    double lmax = tr*0.5 + disc;
    Vec2d v(sxy, lmax - sxx);
    double n = std::sqrt(v[0]*v[0] + v[1]*v[1]);
    if (n < 1e-12) v = (sxx >= syy) ? Vec2d(1,0) : Vec2d(0,1);
    else           v /= n;
    dir = v; c = Point2d(mx, my);
}

static inline double ptLineDist(const Point2d& p, const Point2d& c, const Vec2d& d) {
    return std::fabs((p.x - c.x) * d[1] - (p.y - c.y) * d[0]);
}

static bool intersectLines(const Point2d& p1, const Vec2d& d1,
                           const Point2d& p2, const Vec2d& d2, Point2d& out) {
    double den = d1[0]*d2[1] - d1[1]*d2[0];
    if (std::fabs(den) < 1e-9) return false;
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    double t = (dx*d2[1] - dy*d2[0]) / den;
    out = Point2d(p1.x + t*d1[0], p1.y + t*d1[1]);
    return true;
}

// ----------------------------------------------------------------------------
// 直线段
// ----------------------------------------------------------------------------
struct Run {
    vector<Point2d> pts;
    Point2d c;  Vec2d d;
    double len = 0, rms = 0, angle = 0;
};

static void finalizeRun(Run& r) {
    tlsLine(r.pts, r.d, r.c);
    double mn = 1e18, mx = -1e18;
    for (const auto& p : r.pts) {
        double t = (p.x - r.c.x)*r.d[0] + (p.y - r.c.y)*r.d[1];
        mn = std::min(mn, t); mx = std::max(mx, t);
    }
    r.len = mx - mn;
    double s = 0;
    for (const auto& p : r.pts) { double e = ptLineDist(p, r.c, r.d); s += e*e; }
    r.rms = std::sqrt(s / (double)r.pts.size());
    r.angle = std::atan2(r.d[1], r.d[0]) * 180.0 / CV_PI;
    if (r.angle >  90) r.angle -= 180;
    if (r.angle <= -90) r.angle += 180;
}

static void splitOpen(const vector<Point2d>& pts, int a, int b, double tol,
                      vector<Run>& out, int depth) {
    int n = b - a + 1;
    if (n < 3 || depth > 24) {
        if (n >= 2) { Run r; r.pts.assign(pts.begin()+a, pts.begin()+b+1); finalizeRun(r); out.push_back(r); }
        return;
    }
    vector<Point2d> sub(pts.begin()+a, pts.begin()+b+1);
    Vec2d d; Point2d c; tlsLine(sub, d, c);
    // 关键：只在"内部"点里找最大偏差点。
    // 端点 a/b 是相邻两条边的交界（角点），它们的偏差大只说明"这条弧的末端是角"，
    // 不说明这条弧不直。早期版本把端点也算进去，于是遇到 L 形点集时
    // 最大偏差恰好落在端点 -> 直接 emit -> 得到残差几百像素的"伪直线段"。
    double worst = -1; int wi = -1;
    for (int i = a + 1; i <= b - 1; ++i) {
        double e = ptLineDist(pts[i], c, d);
        if (e > worst) { worst = e; wi = i; }
    }
    if (worst <= tol || wi <= a || wi >= b) {
        Run r; r.pts = sub; finalizeRun(r); out.push_back(r);
        return;
    }
    splitOpen(pts, a, wi, tol, out, depth+1);
    splitOpen(pts, wi, b, tol, out, depth+1);
}

// 闭合凸多边形 -> 若干直线段（按环序排列）
static vector<Run> hullToRuns(const vector<Point2d>& hull, double tol,
                              int minRunLen, double mergeAngleDeg) {
    int n = (int)hull.size();
    vector<Run> runs;
    if (n < 3) return runs;

    Vec2d d; Point2d c; tlsLine(hull, d, c);
    double worst = -1; int seed = 0;
    for (int i = 0; i < n; ++i) {
        double e = ptLineDist(hull[i], c, d);
        if (e > worst) { worst = e; seed = i; }
    }
    vector<Point2d> open;
    open.reserve(n+1);
    for (int i = 0; i <= n; ++i) open.push_back(hull[(seed + i) % n]);

    vector<Run> tmp;
    splitOpen(open, 0, n, tol, tmp, 0);
    // 注意：open[0] == open[n] == seed（seed 通常是某个角点），
    // 所以 tmp 已经是"绕一圈"的完整分割，首尾两段是两条不同的边，
    // 千万不能合并（早期版本在这里合并导致 runs=1，顶点全错）。
    runs = tmp;

    // 合并相邻且方向相近的段。
    // 关键：必须"保序"放回！早期版本把合并结果 push 到数组末尾，
    // 直接破坏了环序（顶点顺序变成 hex3,hex0,hex1,hex2,hex5,hex4 这种非环绕序列），
    // 于是 6 个点虽然位置都对，却没有任何标注能与它们对应上，位姿必然错。
    for (int pass = 0; pass < 8; ++pass) {
        int n2 = (int)runs.size();
        if (n2 <= 3) break;
        int bi = -1, bj = -1;
        double bd = mergeAngleDeg;
        for (int i = 0; i < n2; ++i) {
            int j = (i + 1) % n2;
            if (j == i) continue;
            double da = std::fabs(runs[i].angle - runs[j].angle);
            if (da > 90) da = 180 - da;
            if (da < bd) { bd = da; bi = i; bj = j; }
        }
        if (bi < 0) break;
        Run m = runs[bi];
        m.pts.insert(m.pts.end(), runs[bj].pts.begin(), runs[bj].pts.end());
        finalizeRun(m);
        vector<Run> nr;
        if (bj == 0) {                       // 末段 + 首段 -> 合并后放到末尾
            for (int k = 1; k < n2 - 1; ++k) nr.push_back(runs[k]);
            nr.push_back(m);
        } else {
            for (int k = 0; k < n2; ++k) {
                if (k == bi) nr.push_back(m);
                else if (k != bj) nr.push_back(runs[k]);
            }
        }
        runs.swap(nr);
    }

    // 丢掉过短的段（分割噪声），至少保留 4 条；删除同样保持环序
    while (runs.size() > 4) {
        size_t mi = 0;
        for (size_t i = 1; i < runs.size(); ++i) if (runs[i].len < runs[mi].len) mi = i;
        if (runs[mi].len >= minLenThreshold(tol)) break;
        runs.erase(runs.begin() + mi);
    }

    (void)minRunLen;
    return runs;
}

// ----------------------------------------------------------------------------
// 分割策略
// ----------------------------------------------------------------------------
static Mat cleanMask(const Mat& raw, const Size& ksz) {
    Mat m, k = getStructuringElement(MORPH_ELLIPSE, ksz);
    morphologyEx(raw, m, MORPH_CLOSE, k);
    morphologyEx(m, m, MORPH_OPEN, k);
    return m;
}

static bool bestContour(const Mat& mask, double minAreaRatio, vector<Point>& contour) {
    vector<vector<Point>> cs;
    findContours(mask, cs, RETR_EXTERNAL, CHAIN_APPROX_NONE);
    double best = -1;
    for (auto& c : cs) {
        double a = std::fabs(contourArea(c));
        if (a > best) { best = a; contour = c; }
    }
    if (contour.empty()) return false;
    return best / (double)(mask.rows * mask.cols) >= minAreaRatio;
}

struct SegCand { Mat mask; double score = -1; double area = 0, solid = 0; bool border = false; Rect bbox; string name; };

// 把 8U 图降采样成 ASCII，便于在没有图像查看条件时判断分割对错
static void asciiDump(const Mat& m8, const string& tag, int cols = 64) {
    Mat g8;
    if (m8.channels() == 3) cvtColor(m8, g8, COLOR_BGR2GRAY); else g8 = m8;
    int rows = std::max(1, (int)std::lround(cols * (double)g8.rows / g8.cols / 2.0));
    Mat small; resize(g8, small, Size(cols, rows), 0, 0, INTER_AREA);
    const char* ramp = " .:-=+*#%@";
    cout << "  [ASCII " << tag << "] " << m8.cols << "x" << m8.rows << endl;
    for (int y = 0; y < rows; ++y) {
        string line = "  |";
        for (int x = 0; x < cols; ++x) {
            int v = small.at<uchar>(y, x);
            line += ramp[std::min(9, (v * 10) / 256)];
        }
        line += "|";
        cout << line << endl;
    }
}

static vector<SegCand> segmentAll(const Mat& bgr, const Params& P, const Mat& gray) {
    vector<SegCand> out;
    int ks = std::max(3, (std::min(bgr.rows, bgr.cols) / 40) | 1);
    Size ksz(ks, ks);

    // 1) Otsu 两个极性
    {
        Mat g; GaussianBlur(gray, g, Size(5,5), 0);
        Mat th; threshold(g, th, 0, 255, THRESH_BINARY | THRESH_OTSU);
        out.push_back({cleanMask(th, ksz), -1, 0, 0, false, Rect(), "otsu"});
        if (!P.invert) out.push_back({cleanMask(255 - th, ksz), -1, 0, 0, false, Rect(), "otsu-inv"});
    }
    // 2) 自适应阈值
    {
        int bs = std::max(11, (std::min(bgr.rows, bgr.cols) / 8) | 1);
        Mat th; adaptiveThreshold(gray, th, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, bs, 4);
        out.push_back({cleanMask(th, ksz), -1, 0, 0, false, Rect(), "adaptive"});
        out.push_back({cleanMask(255 - th, ksz), -1, 0, 0, false, Rect(), "adaptive-inv"});
    }
    // 3) Canny + 闭运算 + 填充（纯靠边界，不靠颜色）
    {
        Mat e, g; GaussianBlur(gray, g, Size(5,5), 0);
        Canny(g, e, 40, 120);
        Mat k = getStructuringElement(MORPH_ELLIPSE, Size(5,5));
        dilate(e, e, k);
        Mat m; morphologyEx(e, m, MORPH_CLOSE, getStructuringElement(MORPH_ELLIPSE, Size(15,15)));
        vector<Point> c; Mat filled = Mat::zeros(m.size(), CV_8UC1);
        if (bestContour(m, P.minAreaRatio * 0.5, c)) {
            vector<vector<Point>> vc{c};
            drawContours(filled, vc, -1, Scalar(255), FILLED);
        }
        out.push_back({filled, -1, 0, 0, false, Rect(), "canny"});
    }
    // 4) Lab 色差（背景色从 ROI 边框估计）—— 全向量化，避免逐像素 C++ 循环
    {
        Mat lab; cvtColor(bgr, lab, COLOR_BGR2Lab);
        int bw = std::max(2, std::min(lab.rows, lab.cols) / 20);
        Mat ring = Mat::ones(lab.size(), CV_8UC1) * 255;
        rectangle(ring, Rect(bw, bw, lab.cols - 2*bw, lab.rows - 2*bw), Scalar(0), FILLED);
        Scalar bg = mean(lab, ring);
        Mat d8; absdiff(lab, Scalar(bg[0], bg[1], bg[2]), d8);
        Mat d1; d8.convertTo(d1, CV_32F);
        Mat flat = d1.reshape(1, (int)d1.total());
        Mat s; reduce(flat, s, 1, REDUCE_SUM, CV_32F);
        s = s.reshape(1, lab.rows);
        Scalar ms = mean(s);
        Mat th; threshold(s, th, ms[0]*1.8, 255, THRESH_BINARY);
        th.convertTo(th, CV_8UC1);
        out.push_back({cleanMask(th, ksz), -1, 0, 0, false, Rect(), "lab"});
    }
    return out;
}

// ----------------------------------------------------------------------------
// 亚像素边界精化（沿法向找 |梯度| 极值）
// ----------------------------------------------------------------------------
static bool refineRun(Run& r, const Mat& gxF, const Mat& gyF, double range, double gradThr) {
    if (r.len < 8) return false;
    Vec2d nrm(-r.d[1], r.d[0]);
    int nS = std::max(6, (int)(r.len * 0.84 / 2.0));   // 两端各裁 8%：角点附近易被相邻棱/花纹污染
    auto mag = [&](double x, double y) {
        double gx = bilinear(gxF, x, y), gy = bilinear(gyF, x, y);
        return std::sqrt(gx*gx + gy*gy);
    };
    vector<Point2d> ref;
    for (int i = 0; i < nS; ++i) {
        double t = -r.len*0.42 + r.len * 0.84 * (i + 0.5) / nS;
        double px = r.c.x + t*r.d[0], py = r.c.y + t*r.d[1];
        double bestG = -1, bestO = 0;
        for (double o = -range; o <= range + 1e-9; o += 0.5) {
            double g = mag(px + o*nrm[0], py + o*nrm[1]);
            if (g > bestG) { bestG = g; bestO = o; }
        }
        if (bestG < gradThr) continue;
        double g0 = mag(px + (bestO-0.5)*nrm[0], py + (bestO-0.5)*nrm[1]);
        double g1 = bestG;
        double g2 = mag(px + (bestO+0.5)*nrm[0], py + (bestO+0.5)*nrm[1]);
        double den = g0 - 2*g1 + g2;
        double off = bestO;
        if (std::fabs(den) > 1e-9) {
            double delta = 0.5 * (g0 - g2) / den;
            if (std::fabs(delta) <= 1.0) off = bestO + delta;
        }
        ref.push_back(Point2d(px + off*nrm[0], py + off*nrm[1]));
    }
    if ((int)ref.size() < 5) return false;
    Vec2d d2; Point2d c2; tlsLine(ref, d2, c2);
    // 方向变化太大 -> 抓到了内部花纹，放弃
    if (std::fabs(d2[0]*r.d[0] + d2[1]*r.d[1]) < 0.985) return false;   // > 约 10 度
    vector<Point2d> keep;
    for (auto& p : ref) if (ptLineDist(p, c2, d2) < 1.5) keep.push_back(p);
    if ((int)keep.size() < 5) return false;
    Vec2d d3; Point2d c3; tlsLine(keep, d3, c3);
    double s = 0;
    for (auto& p : keep) { double e = ptLineDist(p, c3, d3); s += e*e; }
    double rmsNew = std::sqrt(s / (double)keep.size());
    // 注意：预简化后的段可能只有 2 个点，此时 r.rms == 0，
    // 不能用 "rmsNew <= r.rms + 0.15" 作为判据，否则精化永远被拒（顶点会停在整数坐标）。
    if (rmsNew > std::max(0.6, r.rms + 0.2)) return false;
    r.d = d3; r.c = c3; r.rms = rmsNew;
    return true;
}

static double edgeSupportOf(const Mat& gxF, const Mat& gyF, const vector<Point2d>& a,
                            const vector<Point2d>& b, double gradThr) {
    int good = 0, tot = 0;
    for (size_t k = 0; k < a.size(); ++k) {
        double dx = b[k].x - a[k].x, dy = b[k].y - a[k].y;
        double L = std::sqrt(dx*dx + dy*dy);
        int n = std::max(8, (int)(L / 2.0));
        for (int i = 1; i < n; ++i) {
            double t = (double)i / n;
            double gx = bilinear(gxF, a[k].x + t*dx, a[k].y + t*dy);
            double gy = bilinear(gyF, a[k].x + t*dx, a[k].y + t*dy);
            if (std::sqrt(gx*gx + gy*gy) >= gradThr) good++;
            tot++;
        }
    }
    return tot > 0 ? (double)good / tot : -1;
}

// ----------------------------------------------------------------------------
// 立方体：6 个有序顶点 -> 位姿
//   标注 A（near=(s,s,s) 与下标 0,2,4 相连）：
//     i :   0        1        2        3        4        5
//     A : (0,s,s)  (0,0,s)  (s,0,s)  (s,0,0)  (s,s,0)  (0,s,0)   near=(s,s,s) hidden=(0,0,0)
//     B : (s,0,0)  (s,s,0)  (0,s,0)  (0,s,s)  (0,0,s)  (s,0,s)   near=(0,0,0) hidden=(s,s,s)
// ----------------------------------------------------------------------------
static const double kTabA[6][3] = {{0,1,1},{0,0,1},{1,0,1},{1,0,0},{1,1,0},{0,1,0}};
static const double kTabB[6][3] = {{1,0,0},{1,1,0},{0,1,0},{0,1,1},{0,0,1},{1,0,1}};

static bool solveCube(const vector<Point2d>& vimg0, double s, const Mat& K,
                      const Mat& gxF, const Mat& gyF, double gradThr,
                      State* st, Result& R)
{
    const int NP = 6;
    // 48 个假设 = 6 个起点 × 2 个绕向 × 2 个标注
    struct Hyp { int sh, rev, lab; };
    vector<Hyp> hyps;
    if (st && st->sticky >= 0) {
        int v = st->sticky;
        hyps.push_back({v / 4, (v / 2) % 2, v % 2});   // 先试上一帧的胜者
    }
    for (int sh = 0; sh < NP; ++sh)
        for (int rev = 0; rev < 2; ++rev)
            for (int lab = 0; lab < 2; ++lab) {
                int v = sh*4 + rev*2 + lab;
                if (st && st->sticky == v) continue;
                hyps.push_back({sh, rev, lab});
            }

    double bestScore = 1e18; int bestV = -1;
    Mat bestRvec, bestTvec;
    vector<Point2d> bestImg;
    Mat bestRm;
    R.hypRms.clear();

    for (size_t hi = 0; hi < hyps.size(); ++hi) {
        const Hyp& h = hyps[hi];
        vector<Point2d> img;
        for (int i = 0; i < NP; ++i) img.push_back(vimg0[(h.sh + i) % NP]);
        if (h.rev) reverse(img.begin(), img.end());
        const double (*tab)[3] = h.lab ? kTabB : kTabA;
        vector<Point3d> obj;
        for (int i = 0; i < NP; ++i) obj.push_back(Point3d(tab[i][0]*s, tab[i][1]*s, tab[i][2]*s));

        Mat rvec, tvec;
        try {
            solvePnP(obj, img, K, Mat(), rvec, tvec, false, SOLVEPNP_EPNP);
        } catch (const cv::Exception&) { continue; }

        vector<Point2d> proj; projectPoints(obj, rvec, tvec, K, Mat(), proj);
        double sse = 0;
        for (int i = 0; i < NP; ++i) sse += norm(proj[i] - img[i]);
        double rms = std::sqrt(sse / NP);
        if (tvec.at<double>(2) <= 0) rms += 1000.0;

        // 只用 6 个轮廓点求位姿存在"Necker 镜像"二义性：另一个解能把同样的 6 点
        // 投到同样的位置，但把立方体整体"翻"过去（可见面变成背面）。
        // 因此加两条与位姿无关的判据：
        //   a) 相机俯视场景时，可见面里必须有一个朝上的面；
        //   b) 可见近角点到三个中间角点的"内部 Y 型棱"必须有图像梯度支持。
        Mat Rm2; Rodrigues(rvec, Rm2);
        int nFront = 0; double maxUp = -2.0;
        double th2 = upVectorTilt();
        Vec3d upv(0, -std::cos(th2), -std::sin(th2));
        Point3d cubeC2(s*0.5, s*0.5, s*0.5);
        double nearCoord[3] = {0,0,0}; bool haveNear[3] = {false,false,false};
        for (int ax = 0; ax < 3; ++ax) {
            for (int sg = 0; sg < 2; ++sg) {
                double sgn = sg ? 1.0 : -1.0;
                double n3[3] = {0,0,0}; n3[ax] = sgn;
                Point3d nrmM(n3[0], n3[1], n3[2]);
                Point3d cenM = cubeC2 + nrmM * (s*0.5);
                Mat nM = Rm2 * (Mat_<double>(3,1) << nrmM.x, nrmM.y, nrmM.z);
                Mat cM = Rm2 * (Mat_<double>(3,1) << cenM.x, cenM.y, cenM.z) + tvec;
                Vec3d nCam(nM.at<double>(0), nM.at<double>(1), nM.at<double>(2));
                Vec3d cCam(cM.at<double>(0), cM.at<double>(1), cM.at<double>(2));
                if (nCam.dot(cCam) < 0) { nFront++; maxUp = std::max(maxUp, nCam.dot(upv));
                                          nearCoord[ax] = sg ? s : 0.0; haveNear[ax] = true; }
            }
        }
        double supIn = -1.0;
        if (nFront == 3 && haveNear[0] && haveNear[1] && haveNear[2]) {
            Point3d nearP(nearCoord[0], nearCoord[1], nearCoord[2]);
            Point3d hidP((nearCoord[0] > 0 ? 0.0 : s), (nearCoord[1] > 0 ? 0.0 : s),
                         (nearCoord[2] > 0 ? 0.0 : s));
            vector<Point3d> mids, ps;
            for (int ax = 0; ax < 3; ++ax) {
                double c[3] = {nearP.x, nearP.y, nearP.z};
                c[ax] = (c[ax] > 0) ? 0.0 : s;
                Point3d m(c[0], c[1], c[2]);
                if (std::fabs(m.x - hidP.x) < 1e-9 && std::fabs(m.y - hidP.y) < 1e-9 &&
                    std::fabs(m.z - hidP.z) < 1e-9) continue;   // 跳过隐藏角点
                mids.push_back(m);
            }
            vector<Point2d> p2; vector<Point3d> all; all.push_back(nearP);
            for (auto& m : mids) all.push_back(m);
            projectPoints(all, rvec, tvec, K, Mat(), p2);
            vector<Point2d> ea, eb;
            for (size_t k = 1; k < p2.size(); ++k) { ea.push_back(p2[0]); eb.push_back(p2[k]); }
            supIn = edgeSupportOf(gxF, gyF, ea, eb, gradThr);
        }
        double score = rms;
        if (nFront != 3)      score += 1000.0;
        if (maxUp < 0.25)     score += 1000.0;              // 可见面里没有朝上的面 -> 镜像解
        if (supIn >= 0)       score += 2.0 * (1.0 - supIn); // 内部棱支持度低 -> 可疑
        R.hypRms.push_back({h.sh*4 + h.rev*2 + h.lab, score});

        if (score < bestScore) { bestScore = score; bestV = h.sh*4 + h.rev*2 + h.lab;
                                 bestRvec = rvec.clone(); bestTvec = tvec.clone(); bestImg = img; }
        // 上一帧胜者已经足够好 -> 直接收敛，省掉其余 47 次求解（实时用）
        if (st && st->sticky >= 0 && hi == 0 && rms < 1.0) break;
    }
    if (bestV < 0) { R.msg = "solvePnP 全部假设失败"; return false; }
    if (st) st->sticky = bestV;
    R.solveScore = bestScore;

    // 用 ITERATIVE 精化（EPNP 给初值）
    {
        int lab = bestV%2;
        const double (*tab)[3] = lab ? kTabB : kTabA;
        vector<Point3d> obj;
        for (int i = 0; i < NP; ++i) obj.push_back(Point3d(tab[i][0]*s, tab[i][1]*s, tab[i][2]*s));
        try {
            solvePnP(obj, bestImg, K, Mat(), bestRvec, bestTvec, true, SOLVEPNP_ITERATIVE);
            vector<Point2d> proj; projectPoints(obj, bestRvec, bestTvec, K, Mat(), proj);
            double sse = 0;
            for (int i = 0; i < NP; ++i) sse += norm(proj[i] - bestImg[i]);
            R.reprojRms = std::sqrt(sse / NP);
        } catch (const cv::Exception&) { R.reprojRms = bestScore; }
    }

    int sh = bestV/4, rev = (bestV/2)%2, lab = bestV%2;

    Mat Rm; Rodrigues(bestRvec, Rm);

    // ---- 可见面：完全按几何判定（对 6 个面做朝向测试 n·X<0），
    //      不再依赖硬编码下标表，因此与胜出的 (shift,dir,lab) 无关。
    Point3d cubeC(s*0.5, s*0.5, s*0.5);
    struct VFace { Vec3d n; Vec3d cen; vector<Point2d> img; int axis; int sign; };
    vector<VFace> vf;
    for (int ax = 0; ax < 3; ++ax) {
        for (int sg = 0; sg < 2; ++sg) {
            double sgn = sg ? 1.0 : -1.0;
            double n3[3] = {0, 0, 0}; n3[ax] = sgn;
            Point3d nrmM(n3[0], n3[1], n3[2]);
            Point3d cenM = cubeC + nrmM * (s*0.5);
            int u = (ax + 1) % 3, w = (ax + 2) % 3;
            vector<Point3d> cor;
            for (int i = 0; i < 4; ++i) {
                double c[3] = {s*0.5, s*0.5, s*0.5};
                c[ax] = s*0.5 + sgn*s*0.5;
                c[u]  = (i & 1) ? s : 0.0;
                c[w]  = (i & 2) ? s : 0.0;
                cor.push_back(Point3d(c[0], c[1], c[2]));
            }
            Mat nM = Rm * (Mat_<double>(3,1) << nrmM.x, nrmM.y, nrmM.z);
            Mat cM = Rm * (Mat_<double>(3,1) << cenM.x, cenM.y, cenM.z) + bestTvec;
            Vec3d nCam(nM.at<double>(0), nM.at<double>(1), nM.at<double>(2));
            Vec3d cCam(cM.at<double>(0), cM.at<double>(1), cM.at<double>(2));
            if (nCam.dot(cCam) >= 0) continue;          // 背面 -> 不可见
            VFace f; f.n = nCam; f.cen = cCam; f.axis = ax; f.sign = sg ? 1 : -1;
            vector<Point2d> ip; projectPoints(cor, bestRvec, bestTvec, K, Mat(), ip);
            Vec3d cc(0,0,0); for (auto& q : ip) cc += Vec3d(q.x, q.y, 0);
            cc *= 0.25;
            sort(ip.begin(), ip.end(), [&](const Point2d& a, const Point2d& b) {
                return std::atan2(a.y - cc[1], a.x - cc[0]) < std::atan2(b.y - cc[1], b.x - cc[0]);
            });
            f.img = ip;
            vf.push_back(f);
        }
    }
    if (vf.size() != 3) { R.msg = "可见面数 != 3（位姿异常）"; return false; }

    // 正交性校验（立方体三面法向应互相垂直）
    {
        double e = 0;
        for (size_t i = 0; i < vf.size(); ++i)
            for (size_t j = i+1; j < vf.size(); ++j)
                e = std::max(e, std::fabs(vf[i].n.dot(vf[j].n)));
        R.axisOrthoErr = e;
    }

    // ---- 规范化位姿：z = 朝上的面(可见面外法向)，x = 图像右方向在该面上的投影 ----
    double th = upVectorTilt();
    Vec3d up(0, -std::cos(th), -std::sin(th));
    int top = 0; double bestUp = -1e18;
    for (int i = 0; i < 3; ++i) { double dd = vf[i].n.dot(up); if (dd > bestUp) { bestUp = dd; top = i; } }
    // 规范化坐标轴必须是"立方体的三条棱方向"（也就是可见面的外法向），
    // 否则 center ± hs·(±ex±ey±ez) 就不是立方体的角点：
    // 早期版本把 ex 取成"图像右方向在顶面上的投影"，它与棱方向差约 3.6 度，
    // 8 个角点因此整体偏 2~3mm（像素上约 8px），而位姿本身其实是对的。
    Vec3d ez = vf[top].n;
    int sA = -1, sB = -1;
    for (int i = 0; i < 3; ++i) if (i != top) { (sA < 0 ? sA : sB) = i; }
    Vec3d ex = vf[sA].n;
    if (ex.dot(Vec3d(1,0,0)) < 0) ex = -ex;   // 取"朝图像右侧"的那个侧面，保证跨帧稳定
    ex = ex - ez * ex.dot(ez);                // 数值上投影一次，保证与 ez 严格正交
    ex *= 1.0/std::sqrt(ex.dot(ex));
    Vec3d ey = ez.cross(ex);                  // 会等于 ±另一个侧面法向

    Mat Rcanon = (Mat_<double>(3,3) << ex[0], ey[0], ez[0],
                                       ex[1], ey[1], ez[1],
                                       ex[2], ey[2], ez[2]);
    Mat center = Rm * (Mat_<double>(3,1) << s*0.5, s*0.5, s*0.5) + bestTvec;
    R.center = Vec3d(center.at<double>(0), center.at<double>(1), center.at<double>(2));
    Rodrigues(Rcanon, R.rvec);
    R.tvec = center.clone();
    R.centerDist = std::sqrt(R.center.dot(R.center));
    R.isCube = true;
    R.topFace = 0;
    R.topNormal = ez;

    // ---- 角点物理位置（相机系, m）----
    // 角点号 j：bit0 -> x 正负, bit1 -> y 正负, bit2 -> z 正负（规范化模型系，+z 朝上）
    // 于是 j = 4..7 的四个角就是"朝上的面"的四个角。
    {
        double hs = s * 0.5;
        R.cornersCam.clear();
        for (int j = 0; j < 8; ++j) {
            double off3[3] = {(j&1)?hs:-hs, (j&2)?hs:-hs, (j&4)?hs:-hs};
            Mat oc = Rcanon * (Mat_<double>(3,1) << off3[0], off3[1], off3[2]);
            R.cornersCam.push_back(cv::Point3d(R.center[0] + oc.at<double>(0),
                                               R.center[1] + oc.at<double>(1),
                                               R.center[2] + oc.at<double>(2)));
        }
        // 第 k 个检测顶点对应哪个角点号：把它的模型点投到相机系，再转回规范化模型系取符号
        const double (*tb)[3] = lab ? kTabB : kTabA;
        R.vertexCornerId.clear(); R.vertexPos3D.clear();
        for (int k = 0; k < 6; ++k) {
            Point3d mp(tb[k][0]*s, tb[k][1]*s, tb[k][2]*s);
            Mat pc = Rm * (Mat_<double>(3,1) << mp.x, mp.y, mp.z) + bestTvec;
            Vec3d dvec(pc.at<double>(0) - R.center[0],
                       pc.at<double>(1) - R.center[1],
                       pc.at<double>(2) - R.center[2]);
            double c3[3];
            for (int a = 0; a < 3; ++a)   // 规范化坐标 = Rcanon^T * d
                c3[a] = Rcanon.at<double>(0,a)*dvec[0] + Rcanon.at<double>(1,a)*dvec[1] +
                        Rcanon.at<double>(2,a)*dvec[2];
            int id = (c3[0] > 0 ? 1:0) | (c3[1] > 0 ? 2:0) | (c3[2] > 0 ? 4:0);
            R.vertexCornerId.push_back(id);
            R.vertexPos3D.push_back(R.cornersCam[id]);
        }
        // 近角 = 三个可见面共用的角；隐藏角 = 它的体对角
        Vec3d ax3[3] = {ex, ey, ez};
        double cn[3] = {0, 0, 0};
        for (auto& f : vf) {
            int bj = 0; double bd = -2;
            for (int a = 0; a < 3; ++a) {
                double dd = f.n.dot(ax3[a]);
                if (std::fabs(dd) > bd) { bd = std::fabs(dd); bj = a; }
            }
            cn[bj] = (f.n.dot(ax3[bj]) > 0) ? hs : -hs;
        }
        Mat nrmc = Rcanon * (Mat_<double>(3,1) << cn[0], cn[1], cn[2]);
        R.nearCorner   = cv::Point3d(R.center[0] + nrmc.at<double>(0),
                                     R.center[1] + nrmc.at<double>(1),
                                     R.center[2] + nrmc.at<double>(2));
        R.hiddenCorner = cv::Point3d(R.center[0] - nrmc.at<double>(0),
                                     R.center[1] - nrmc.at<double>(1),
                                     R.center[2] - nrmc.at<double>(2));
    }

    // 一致性自检：三个可见面的外法向应各自平行于规范化坐标轴之一（0 = 完全对齐）
    {
        Vec3d ax[3] = {ex, ey, ez};
        double e = 0;
        for (int i = 0; i < 3; ++i) {
            double bd = 0;
            for (int j = 0; j < 3; ++j) bd = std::max(bd, std::fabs(vf[i].n.dot(ax[j])));
            bd = std::min(1.0, bd);
            e = std::max(e, std::acos(bd) * 180.0 / CV_PI);   // 用角度当口径，别用 1-cos
        }
        R.canonConsist = e;
    }

    // ---- 输出平面：直接给"可见面"的真实平面（相机系）----
    //   n 为立方体朝外的外法向；可见面的 n 指向相机，故 d = n·X_face < 0，
    //   平面方程 n·X = d，相机到该平面的距离 = |d|。
    {
        const char* axn[3] = {"x", "y", "z"};
        Vec3d axc[3] = {ex, ey, ez};
        for (size_t i = 0; i < vf.size(); ++i) {
            Face f;
            f.n = vf[i].n;
            f.center = vf[i].cen;
            f.d = f.n.dot(f.center);
            f.imgCorners = vf[i].img;
            // 按"规范化坐标轴"命名：法向最接近哪个轴就叫哪个；最接近 +z 的叫 up
            int bj = 0; double bd = -2;
            for (int a = 0; a < 3; ++a) {
                double dd = vf[i].n.dot(axc[a]);
                if (std::fabs(dd) > bd) { bd = std::fabs(dd); bj = a; }
            }
            double sgn = vf[i].n.dot(axc[bj]);
            if (bj == 2 && sgn > 0) { f.name = "up"; R.topFace = (int)i; }
            else                    f.name = string(sgn > 0 ? "+" : "-") + axn[bj];
            R.faces.push_back(f);
        }
        // 偏航角：图像右方向在顶面上的投影 与 规范化 +x 轴(某条棱) 的夹角
        Vec3d rightRef(1,0,0);
        Vec3d ref = rightRef - ez * rightRef.dot(ez);
        if (std::sqrt(ref.dot(ref)) < 1e-6) { Vec3d fwd(0,1,0); ref = fwd - ez * fwd.dot(ez); }
        ref *= 1.0 / std::sqrt(ref.dot(ref));
        Vec3d ezx = ez.cross(ref);
        R.yawDeg = std::atan2(ex.dot(ezx), ex.dot(ref)) * 180.0 / CV_PI;
    }
    R.visibleFaces.clear();
    for (int j = 0; j < 3; ++j) R.visibleFaces.push_back(vf[j].img);

    // ---- 顶点（按胜出假设的顺序）----
    R.verts = bestImg;

    // ---- 轮廓边支持度 ----
    {
        vector<Point2d> a, b;
        for (int i = 0; i < 6; ++i) { a.push_back(bestImg[i]); b.push_back(bestImg[(i+1)%6]); }
        R.edgeSupport = edgeSupportOf(gxF, gyF, a, b, gradThr);
    }
    ostringstream os;
    os << "cube(shift=" << sh << (rev?"/rev":"/fwd") << (lab?"/B":"/A") << ")";
    R.msg = os.str();
    return true;
}

// ----------------------------------------------------------------------------
// 单面 4 顶点（正对相机）：IPPE 共面 PnP
// ----------------------------------------------------------------------------
static bool solveFace(const vector<Point2d>& vimg, double s, const Mat& K,
                      const Mat& gxF, const Mat& gyF, double gradThr, Result& R) {
    int n = (int)vimg.size();
    static const double sq[4][2] = {{0,0},{1,0},{1,1},{0,1}};
    double bestRms = 1e18; Mat bR, bT; int bPh = 0; bool bRev = false;
    vector<pair<double,double>> rmsList;
    for (int rev = 0; rev < 2; ++rev) {
        for (int ph = 0; ph < n; ++ph) {
            vector<Point3d> obj; vector<Point2d> ip;
            for (int i = 0; i < n; ++i) {
                int k = (ph + i) % n;
                obj.push_back(Point3d(sq[i][0]*s, sq[i][1]*s, 0));
                ip.push_back(vimg[rev ? (n - 1 - k) : k]);
            }
            vector<Mat> rvs, tvs;
            try { solvePnPGeneric(obj, ip, K, Mat(), rvs, tvs, false, SOLVEPNP_IPPE); }
            catch (const cv::Exception&) { continue; }
            for (size_t k = 0; k < rvs.size(); ++k) {
                vector<Point2d> proj; projectPoints(obj, rvs[k], tvs[k], K, Mat(), proj);
                double sse = 0;
                for (int i = 0; i < n; ++i) sse += norm(proj[i] - ip[i]);
                double zmin = tvs[k].at<double>(2);
                double rms = std::sqrt(sse / n);
                if (zmin <= 0) rms += 1000.0;
                rmsList.push_back({(double)(ph*2+rev), rms});
                if (rms < bestRms) { bestRms = rms; bR = rvs[k].clone(); bT = tvs[k].clone(); bPh = ph; bRev = rev; }
            }
        }
    }
    if (bestRms > 1e17) { R.msg = "单面 IPPE 失败"; return false; }
    sort(rmsList.begin(), rmsList.end(), [](const pair<double,double>& a, const pair<double,double>& b){ return a.second < b.second; });
    for (size_t i = 0; i < rmsList.size() && i < 2; ++i)
        R.hypRms.push_back({(int)rmsList[i].first, rmsList[i].second});

    vector<Point2d> img = vimg;
    vector<Point2d> ord;
    for (int i = 0; i < n; ++i) ord.push_back(img[bRev ? (n - 1 - (bPh+i)%n) : (bPh+i)%n]);
    R.verts = ord;
    Mat Rm; Rodrigues(bR, Rm);
    Vec3d cen(bT.at<double>(0), bT.at<double>(1), bT.at<double>(2));   // 模型原点=面上一角
    Vec3d nz(Rm.at<double>(0,2), Rm.at<double>(1,2), Rm.at<double>(2,2));
    // 单面情况下把规范化坐标定义为：+z = 可见面外法向（指向相机），
    // 可见面落在 z = -hs 处，立方体沿 -z 方向向后延伸。
    Vec3d faceC = cen + nz * (s*0.5);       // 面的中心（模型 (s/2,s/2,0) 处）
    if (nz.dot(faceC) > 0) nz = -nz;        // 可见面法向必然指向相机
    Vec3d right(1,0,0);
    Vec3d exc = right - nz * right.dot(nz);
    if (std::sqrt(exc.dot(exc)) < 1e-6) { Vec3d fwd(0,1,0); exc = fwd - nz * fwd.dot(nz); }
    exc *= 1.0 / std::sqrt(exc.dot(exc));
    Vec3d eyc = nz.cross(exc);
    double hs = s * 0.5;
    Vec3d centerF = faceC + nz * hs;        // 立方体中心 = 可见面心 + nz*hs
    Mat RcanonF = (Mat_<double>(3,3) << exc[0], eyc[0], nz[0],
                                        exc[1], eyc[1], nz[1],
                                        exc[2], eyc[2], nz[2]);
    Rodrigues(RcanonF, R.rvec);
    Mat tcanon = (Mat_<double>(3,1) << centerF[0], centerF[1], centerF[2]);
    R.tvec = tcanon.clone();
    R.center = centerF;
    R.centerDist = std::sqrt(centerF.dot(centerF));
    R.reprojRms = bestRms; R.isCube = false; R.solveScore = bestRms;
    R.topNormal = nz;
    R.yawDeg = 0;
    R.cornersCam.clear();
    for (int j = 0; j < 8; ++j) {
        double off3[3] = {(j&1)?hs:-hs, (j&2)?hs:-hs, (j&4)?hs:-hs};
        Mat oc = RcanonF * (Mat_<double>(3,1) << off3[0], off3[1], off3[2]);
        R.cornersCam.push_back(cv::Point3d(centerF[0] + oc.at<double>(0),
                                           centerF[1] + oc.at<double>(1),
                                           centerF[2] + oc.at<double>(2)));
    }
    R.vertexCornerId.clear(); R.vertexPos3D.clear();
    for (int i = 0; i < n; ++i) {
        Point3d mp(sq[i][0]*s, sq[i][1]*s, 0.0);
        Mat pc = Rm * (Mat_<double>(3,1) << mp.x, mp.y, mp.z) + bT;
        Vec3d dvec(pc.at<double>(0) - centerF[0], pc.at<double>(1) - centerF[1],
                   pc.at<double>(2) - centerF[2]);
        double cx = dvec.dot(exc), cy = dvec.dot(eyc);
        int id = (cx > 0 ? 1:0) | (cy > 0 ? 2:0);        // 可见面 z 位恒为 0
        R.vertexCornerId.push_back(id);
        R.vertexPos3D.push_back(R.cornersCam[id]);
    }
    R.nearCorner = R.cornersCam[0];
    R.hiddenCorner = R.cornersCam[7];
    Face f; f.n = nz; f.d = nz.dot(faceC); f.center = faceC; f.imgCorners = ord; f.name = "face";
    R.faces.push_back(f); R.topFace = 0; R.topNormal = nz; R.yawDeg = 0;
    {
        vector<Point2d> a, b;
        for (int i = 0; i < n; ++i) { a.push_back(ord[i]); b.push_back(ord[(i+1)%n]); }
        R.edgeSupport = edgeSupportOf(gxF, gyF, a, b, gradThr);
    }
    ostringstream os; os << "single-face(ph=" << bPh << (bRev?"/rev":"/fwd") << ")";
    R.msg = os.str();
    return true;
}

// ----------------------------------------------------------------------------
// 单帧主流程
// ----------------------------------------------------------------------------
static Result processFrame(const Mat& frameBGR, const Params& P, const Mat& K, State* st) {
    Result R;
    auto T0 = chrono::steady_clock::now();
    auto ms = [](chrono::steady_clock::time_point a, chrono::steady_clock::time_point b) {
        return chrono::duration<double, milli>(b - a).count();
    };

    Rect roi(0, 0, frameBGR.cols, frameBGR.rows);
    if (P.roi.width > 0 && P.roi.height > 0) {
        int px = (int)(P.roi.width * P.roiPad), py = (int)(P.roi.height * P.roiPad);
        roi = Rect(P.roi.x - px, P.roi.y - py, P.roi.width + 2*px, P.roi.height + 2*py);
        roi &= Rect(0, 0, frameBGR.cols, frameBGR.rows);
    }
    if (roi.width < 32 || roi.height < 32) { R.msg = "ROI 太小"; return R; }
    Mat bgr = frameBGR(roi).clone();
    Point2d off(roi.x, roi.y);
    // ROI 裁剪后的内参：主点同样要平移。
    // 若用 ROI 局部坐标却传全图内参，投影模型不一致（主点被平移了 roi.x/roi.y），
    // 6 个点会解不出正确位姿（RMS 会莫名涨到几像素、距离偏差几厘米）。
    Mat Kroi = K.clone();
    Kroi.at<double>(0,2) -= roi.x;
    Kroi.at<double>(1,2) -= roi.y;

    Mat gray; cvtColor(bgr, gray, COLOR_BGR2GRAY);
    if (P.verbose) asciiDump(gray, "gray(ROI)");
    Mat g32;  gray.convertTo(g32, CV_32F);
    Mat gxF, gyF;
    Sobel(g32, gxF, CV_32F, 1, 0, 3);
    Sobel(g32, gyF, CV_32F, 0, 1, 3);
    double gradThr;
    {
        Mat mag; magnitude(gxF, gyF, mag);
        vector<float> v(mag.begin<float>(), mag.end<float>());
        size_t k = (size_t)(v.size() * 0.85);
        if (k >= v.size()) k = v.size() - 1;
        nth_element(v.begin(), v.begin()+k, v.end());
        gradThr = v[k];
    }

    auto t1 = chrono::steady_clock::now();
    vector<SegCand> cands = segmentAll(bgr, P, gray);
    if (P.segMode >= 1 && P.segMode <= (int)cands.size()) {
        SegCand c = cands[P.segMode-1];
        cands.clear(); cands.push_back(c);
    }
    // 便宜的预筛：凸性 + 面积 + 是否触边（立方体轮廓不该被 ROI 切掉）
    for (auto& c : cands) {
        vector<Point> ct;
        if (!bestContour(c.mask, P.minAreaRatio, ct)) { c.score = -1; continue; }
        vector<Point> hull; convexHull(ct, hull);
        double ah = std::fabs(contourArea(hull)), ac = std::fabs(contourArea(ct));
        c.solid = ah > 1 ? ac / ah : 0;
        c.area  = ah / (double)(c.mask.rows * c.mask.cols);
        Rect bb = boundingRect(ct);
        c.border = (bb.x <= 1 || bb.y <= 1 || bb.br().x >= c.mask.cols-1 || bb.br().y >= c.mask.rows-1);
        c.bbox = bb;
        c.score = c.solid * (c.border ? 0.15 : 1.0) * (c.area >= P.minAreaRatio ? 1.0 : 0.02);
        if (c.area > 0.90) c.score *= 0.2;      // 几乎填满 ROI 的掩膜不可能是立方体
    }
    sort(cands.begin(), cands.end(), [](const SegCand& a, const SegCand& b){ return a.score > b.score; });
    R.tSeg = ms(t1, chrono::steady_clock::now());
    if (P.verbose) {
        for (auto& c : cands)
            cout << "  [seg] " << std::setw(13) << c.name
                 << " area=" << std::setprecision(3) << c.area << " solid=" << c.solid
                 << " 触边=" << (c.border ? "是" : "否") << " score=" << c.score
                 << " bbox=[" << c.bbox.x << "," << c.bbox.y << "," << c.bbox.width << "," << c.bbox.height << "]\n";
    }

    // 逐个候选：拟合直线 -> 顶点 -> 用"多边形边缘支持度 + 顶点数"打分
    struct Fit { vector<Run> runs; vector<Point2d> verts; double support; int tier; string name; };
    vector<Fit> fits;
    int tried = 0;
    for (auto& c : cands) {
        if (c.score <= 0 || tried >= 4) continue;
        tried++;
        vector<Point> ct;
        if (!bestContour(c.mask, P.minAreaRatio, ct)) continue;
        vector<Point> hullP; convexHull(ct, hullP);
        if (hullP.size() < 4) continue;
        // 预简化 eps 与拆分容差各试几档：掩膜锯齿与真实角点混在一起时，
        // 单一阈值很容易把 6 个角切成 8 段或并成 5 段。多试几档再由
        // "顶点数 + 边缘支持度" 打分选优，比调死一个阈值稳得多。
        const double epsR[3] = {0.004, 0.008, 0.018};
        const double tolR[3] = {P.splitTol, P.splitTol * 1.8, P.splitTol * 3.0};
        double per = arcLength(hullP, true);
        for (int v = 0; v < 3; ++v) {
            vector<Point> simp;
            approxPolyDP(hullP, simp, std::max(1.5, epsR[v] * per), true);
            vector<Point2d> hull;
            for (auto& q : simp) hull.push_back(Point2d(q.x, q.y));
            vector<Run> runs = hullToRuns(hull, tolR[v], P.minRunLen, P.mergeAngleDeg);
            if (runs.size() < 4) continue;
            int nRef = 0;
            if (P.subpix) for (auto& r : runs) if (refineRun(r, gxF, gyF, P.subpixRange, gradThr)) nRef++;

            vector<Point2d> verts;
            bool fail = false;
            for (size_t i = 0; i < runs.size(); ++i) {
                size_t j = (i + 1) % runs.size();
                Point2d vv;
                if (!intersectLines(runs[i].c, runs[i].d, runs[j].c, runs[j].d, vv)) { fail = true; break; }
                verts.push_back(vv);
            }
            if (fail || verts.size() < 4) continue;
            bool sane = true;
            for (size_t i = 0; i < verts.size() && sane; ++i)
                for (size_t j = i+1; j < verts.size(); ++j)
                    if (norm(verts[i]-verts[j]) < 5) { sane = false; break; }
            if (!sane) continue;

            vector<Point2d> ea, eb;
            for (size_t i = 0; i < verts.size(); ++i) { ea.push_back(verts[i]); eb.push_back(verts[(i+1)%verts.size()]); }
            double sup = edgeSupportOf(gxF, gyF, ea, eb, gradThr);
            Fit f; f.runs = runs; f.verts = verts; f.support = sup;
            f.tier = (verts.size() == 6) ? 0 : (verts.size() == 4 ? 1 : 2);
            f.name = c.name;
            fits.push_back(f);
            R.mask = c.mask;
            R.hullSolidity = c.solid;
            if (P.verbose)
                cout << "  [fit] cand=" << c.name << " v=" << v << " hullPts=" << hull.size()
                     << " runs=" << runs.size() << " verts=" << verts.size()
                     << " 边支持=" << std::setprecision(3) << sup
                     << " 亚像素精化=" << nRef << "/" << runs.size() << endl;
        }
    }
    // 打分：边缘支持度为主，顶点数只作为加成。
    // （若让"顶点数"主导，整幅图边框那种垃圾掩膜只要凑出 4 个顶点就会赢过真实轮廓）
    auto fitKey = [](const Fit& f) {
        double k = f.support;
        if (f.verts.size() == 6)      k += 0.50;
        else if (f.verts.size() == 4) k += 0.15;
        else if (f.verts.size() > 7)  k -= 0.40;
        return k;
    };
    sort(fits.begin(), fits.end(), [&](const Fit& a, const Fit& b) { return fitKey(a) > fitKey(b); });

    // 两阶段：先按"顶点数+边缘支持度"取前几个拟合结果，逐个解位姿，
    // 再用位姿自身的总分（重投影 + 朝上面判据 + 内部棱支持）选最优。
    // 这样多档容差重试不会因为"支持度略高但精度略差"而选错那一档。
    {
        auto t3 = chrono::steady_clock::now();
        double segT = R.tSeg, fitT = R.tFit;
        Result bestR;
        bool have = false;
        int nSolved = 0;
        for (auto& f : fits) {
            if (nSolved >= 3) break;
            if (f.verts.size() != 6 && f.verts.size() != 4) {
                if (!have) { R.nVerts = (int)f.verts.size(); R.edgeSupport = f.support;
                             R.verts.clear(); for (auto& v : f.verts) R.verts.push_back(v + off);
                             R.msg = "顶点数 = " + to_string(f.verts.size()) + "（不是 6 也不是 4）"; }
                continue;
            }
            Result cur;
            cur.nVerts = (int)f.verts.size();
            cur.edgeSupport = f.support;
            cur.hullSolidity = R.hullSolidity;
            cur.mask = R.mask;
            bool ok = (f.verts.size() == 6)
                    ? solveCube(f.verts, P.cubeSize, Kroi, gxF, gyF, gradThr, st, cur)
                    : solveFace(f.verts, P.cubeSize, Kroi, gxF, gyF, gradThr, cur);
            nSolved++;
            if (!ok) continue;
            if (!have || cur.solveScore < bestR.solveScore) { bestR = cur; have = true; }
        }
        R.tPnp = ms(t3, chrono::steady_clock::now());
        if (have) {
            R = bestR;
            R.tSeg = segT; R.tFit = fitT;   // R=bestR 会把这些计时字段一起覆盖掉
            for (auto& v : R.verts) v += off;
            for (auto& fa : R.faces) for (auto& p : fa.imgCorners) p += off;
            for (auto& vv : R.visibleFaces) for (auto& p : vv) p += off;
            R.ok = true;
        }
    }

    if (!R.ok && R.msg.empty()) R.msg = "未找到有效立方体轮廓";

    if (!P.debugPath.empty() || P.buildDebugImage) {
        Mat dbg = frameBGR.clone();
        if (!R.mask.empty() && R.mask.size() == roi.size()) {
            Mat m3; cvtColor(R.mask, m3, COLOR_GRAY2BGR);
            m3.setTo(Scalar(0,110,0), R.mask);
            Mat sub = dbg(roi);
            addWeighted(sub, 0.65, m3, 0.35, 0, sub);
        }
        rectangle(dbg, roi, Scalar(255,0,0), 1);
        for (size_t i = 0; i < R.verts.size(); ++i) {
            line(dbg, R.verts[i], R.verts[(i+1)%R.verts.size()], Scalar(0,255,0), 2);
            circle(dbg, R.verts[i], 4, Scalar(0,0,255), -1);
            putText(dbg, to_string(i), R.verts[i] + Point2d(7,-7),
                    FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0,255,255), 2);
        }
        if (R.ok) {
            for (auto& f : R.faces)
                for (size_t i = 0; i + 1 < f.imgCorners.size(); ++i)
                    line(dbg, f.imgCorners[i], f.imgCorners[i+1], Scalar(0,190,255), 1);
            for (auto& f : R.faces) {
                if (f.imgCorners.empty()) continue;
                Point2d c(0,0);
                for (auto& p : f.imgCorners) c += p;
                c *= 1.0 / (double)f.imgCorners.size();
                circle(dbg, c, 5, Scalar(255,0,255), -1);
            }
        }
        ostringstream os;
        os << R.msg << " nV=" << R.nVerts;
        if (R.ok) os << " rms=" << std::fixed << std::setprecision(2) << R.reprojRms
                     << " d=" << std::setprecision(3) << R.centerDist << "m";
        putText(dbg, os.str(), Point2d(12, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0,0,0), 4);
        putText(dbg, os.str(), Point2d(12, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0,255,255), 2);
        R.debugImage = dbg;
    }
    R.tTotal = ms(T0, chrono::steady_clock::now());
    return R;
}


// ---------------------------------------------------------------------------
// 自动 ROI 候选：未提供 ROI 时，把各分割策略得到的轮廓外接框当作候选区域。
// 这就是"ROI 不一定需要"的兜底：先按全图试一次，失败再在这些候选框里各试一次。
// ---------------------------------------------------------------------------
static vector<Rect> autoRoiCandidates(const Mat& bgr, const Params& P, const Mat&) {
    vector<Rect> out;
    Mat gray; cvtColor(bgr, gray, COLOR_BGR2GRAY);
    vector<SegCand> cands = segmentAll(bgr, P, gray);
    struct C { Rect r; double score; };
    vector<C> cs;
    for (auto& c : cands) {
        vector<Point> ct;
        if (!bestContour(c.mask, P.minAreaRatio, ct)) continue;
        vector<Point> hull; convexHull(ct, hull);
        double ah = std::fabs(contourArea(hull)), ac = std::fabs(contourArea(ct));
        double solid = ah > 1 ? ac / ah : 0;
        double area = ah / (double)(c.mask.rows * c.mask.cols);
        Rect bb = boundingRect(ct);
        bool border = (bb.x <= 1 || bb.y <= 1 || bb.br().x >= c.mask.cols-1 || bb.br().y >= c.mask.rows-1);
        if (border || area < P.minAreaRatio || area > 0.85 || solid < 0.85) continue;
        cs.push_back({bb, solid * std::min(1.0, area / 0.10)});
    }
    sort(cs.begin(), cs.end(), [](const C& a, const C& b) { return a.score > b.score; });
    for (size_t i = 0; i < cs.size() && i < 3; ++i) {
        int px = (int)(cs[i].r.width  * 0.20);
        int py = (int)(cs[i].r.height * 0.20);
        Rect r = Rect(cs[i].r.x - px, cs[i].r.y - py,
                      cs[i].r.width + 2*px, cs[i].r.height + 2*py) &
                 Rect(0, 0, bgr.cols, bgr.rows);
        if (r.width > 32 && r.height > 32) out.push_back(r);
    }
    return out;
}

} // namespace   (内部匿名命名空间到此结束，下面是类成员实现)

// =============================================================================
// 类实现
// =============================================================================
static Mat buildK_(const CubePoseParams& P, const Size& sz) {
    Mat K = Mat::eye(3,3,CV_64F);
    if (!P.calibFile.empty()) {
        FileStorage fs(P.calibFile, FileStorage::READ);
        if (fs.isOpened()) {
            Mat cm; fs["camera_matrix"] >> cm;
            if (!cm.empty() && cm.rows == 3) return cm.clone();
            double fx=0,fy=0,cx=0,cy=0;
            fs["fx"]>>fx; fs["fy"]>>fy; fs["cx"]>>cx; fs["cy"]>>cy;
            if (fx > 0) {
                K.at<double>(0,0)=fx; K.at<double>(1,1)= fy>0?fy:fx;
                K.at<double>(0,2)=cx; K.at<double>(1,2)=cy; return K;
            }
        } else {
            cerr << "[cube_pose] 无法读取标定文件: " << P.calibFile << endl;
        }
    }
    if (P.fx > 0) {
        K.at<double>(0,0) = P.fx; K.at<double>(1,1) = P.fy > 0 ? P.fy : P.fx;
        K.at<double>(0,2) = P.cx > 0 ? P.cx : sz.width  * 0.5;
        K.at<double>(1,2) = P.cy > 0 ? P.cy : sz.height * 0.5;
        return K;
    }
    double fx = sz.width / (2.0 * std::tan(30.0 * CV_PI / 180.0));
    K.at<double>(0,0) = fx; K.at<double>(1,1) = fx;
    K.at<double>(0,2) = sz.width * 0.5; K.at<double>(1,2) = sz.height * 0.5;
    static bool warned = false;
    if (!warned) {
        warned = true;
        cerr << "[cube_pose][警告] 未提供内参，按 fx=fy=" << fx
             << " 粗估 —— 绝对距离/角度不可信，请标定后用 YAML 里的 fx/fy/cx/cy 或 calibFile。\n";
    }
    return K;
}

CubePoseResult CubePoseDetector::detect(const cv::Mat& bgr, const cv::Rect& roi) {
    CubePoseResult R;
    if (bgr.empty()) { R.msg = "空图像"; return R; }
    if (bgr.channels() == 1) { R.msg = "需要 BGR 图像（单通道请先 cvtColor）"; return R; }

    g_tiltDeg = params_.tiltDeg;
    Mat K = buildK_(params_, bgr.size());

    Params P = params_;
    if (!roi.empty()) {
        P.roi = roi;             // 给了 ROI 就只用 ROI
    } else if (!params_.autoRoi) {
        P.roi = Rect();          // 明确要求不开自动搜索 -> 全图单区域
    } else {
        P.roi = Rect();          // 全图；下方按分割候选自动扩展搜索区域
    }

    State st;
    st.sticky = sticky_;

    // 未给 ROI 时：把"全图"当作唯一区域先试一次；若失败，再用分割候选的
    // 外接框作为候选 ROI 重试（这就是"ROI 不一定需要"的自动模式）。
    R = processFrame(bgr, P, K, &st);
    if (!R.ok && roi.empty() && params_.autoRoi) {
        vector<Rect> cand = autoRoiCandidates(bgr, params_, K);
        for (auto& rr : cand) {
            Params P2 = params_;
            P2.roi = rr;
            P2.roiPad = 0.05;
            Result R2 = processFrame(bgr, P2, K, &st);
            if (R2.ok && (!R.ok || R2.solveScore < R.solveScore)) R = R2;
        }
    }
    sticky_ = st.sticky;
    R.K = K.clone();
    if (!params_.debugPath.empty() && !R.debugImage.empty())
        imwrite(params_.debugPath, R.debugImage);
    return R;
}

double CubePoseDetector::distance(const cv::Mat& bgr, const cv::Rect& roi) {
    CubePoseResult r = detect(bgr, roi);
    return r.ok ? r.centerDist : -1.0;
}

bool CubePoseDetector::loadConfig(const std::string& yamlPath) {
    string path = yamlPath;
    if (path.empty()) {
        const char* cand[] = {"cube_pose.yaml", "cube_pose.yml", "../cube_pose.yaml"};
        for (auto c : cand) {
            FileStorage fs(c, FileStorage::READ);
            if (fs.isOpened()) { path = c; break; }
        }
        if (path.empty()) return false;
    }
    return params_.loadFromYaml(path);
}

// ---------------------------------------------------------------------------
// 结果便捷工具：像素 -> 平面上的 3D 点
// ---------------------------------------------------------------------------
bool rayPlaneIntersect(const Mat& K, const Point2d& pixel, const Vec3d& n, double d, Point3d& out) {
    if (K.empty() || K.rows != 3) return false;
    Mat Kinv = K.inv();
    Mat ray = Kinv * (Mat_<double>(3,1) << pixel.x, pixel.y, 1.0);
    Vec3d dir(ray.at<double>(0), ray.at<double>(1), ray.at<double>(2));
    double denom = n.dot(dir);
    if (std::fabs(denom) < 1e-12) return false;
    double t = d / denom;
    if (t <= 0) return false;
    out = Point3d(t*dir[0], t*dir[1], t*dir[2]);
    return true;
}

bool CubePoseResult::pixelToPlane(const Point2d& pixel, const CubePoseFace& f, Point3d& out) const {
    return rayPlaneIntersect(K, pixel, f.n, f.d, out);
}
bool CubePoseResult::pixelToPlane(const Point2d& pixel, int faceIndex, Point3d& out) const {
    if (faceIndex < 0 || faceIndex >= (int)faces.size()) return false;
    return pixelToPlane(pixel, faces[faceIndex], out);
}
bool CubePoseResult::pixelToTopPlane(const Point2d& pixel, Point3d& out) const {
    const CubePoseFace* f = findFace("up");
    if (!f && !faces.empty()) f = &faces[0];
    if (!f) return false;
    return pixelToPlane(pixel, *f, out);
}


// =============================================================================
// 配置读写（YAML）
// =============================================================================
bool CubePoseParams::loadFromYaml(const std::string& path) {
    FileStorage fs;
    try {
        // 注意：OpenCV 自带的 YAML 解析器要求文件以 %YAML:1.0 开头，
        // 文件不合法时它是"抛异常"而不是返回空，所以这里必须 try/catch。
        if (!fs.open(path, FileStorage::READ)) return false;
    } catch (const cv::Exception& e) {
        cerr << "[cube_pose] 读取配置失败(" << path << "): " << e.what() << endl;
        cerr << "            请确认文件以 %YAML:1.0 开头（可用 --dump-yaml 生成模板）。" << endl;
        return false;
    }
    if (!fs.isOpened()) return false;

    auto rd = [&](const char* k, double& v) {
        FileNode n = fs[k];
        if (!n.empty()) { try { n >> v; } catch (...) {} }
    };
    auto ri = [&](const char* k, int& v) {
        FileNode n = fs[k];
        if (!n.empty()) { try { n >> v; } catch (...) {} }
    };
    // 布尔：YAML 里建议写 0/1；写 true/false 也能识别
    auto rb = [&](const char* k, bool& v) {
        FileNode n = fs[k];
        if (n.empty()) return;
        try { int t = v ? 1 : 0; n >> t; v = (t != 0); return; } catch (...) {}
        try { string t; n >> t; v = (t == "true" || t == "1" || t == "yes" || t == "on"); } catch (...) {}
    };
    auto rs = [&](const char* k, std::string& v) {
        FileNode n = fs[k];
        if (!n.empty()) { try { n >> v; } catch (...) {} }
    };

    // 立方体
    rd("cubeSize", cubeSize);
    rd("tiltDeg",  tiltDeg);
    // ROI
    rd("roiPad", roiPad);
    rb("autoRoi", autoRoi);
    int rx = 0, ry = 0, rw = 0, rh = 0;
    ri("roi_x", rx); ri("roi_y", ry); ri("roi_w", rw); ri("roi_h", rh);
    if (rw > 0 && rh > 0) roi = Rect(rx, ry, rw, rh);
    else                  roi = Rect();
    // 分割
    ri("segMode", segMode);
    rb("invert", invert);
    rd("minAreaRatio", minAreaRatio);
    // 直线拟合
    rd("splitTol", splitTol);
    ri("minRunLen", minRunLen);
    rd("mergeAngleDeg", mergeAngleDeg);
    // 亚像素
    rb("subpix", subpix);
    rd("subpixRange", subpixRange);
    // 内参
    rd("fx", fx); rd("fy", fy); rd("cx", cx); rd("cy", cy);
    rs("calibFile", calibFile);
    // 调试
    rb("buildDebugImage", buildDebugImage);
    rs("debugPath", debugPath);
    rb("verbose", verbose);
    return true;
}

bool CubePoseParams::saveToYaml(const std::string& path) const {
    std::ofstream fo(path.c_str());
    if (!fo) return false;
    fo << "%YAML:1.0\n---\n"
          << "# =============================================================================\n"
          "#  cube_pose 配置文件（全部参数都在这里，不用改代码）\n"
          "#  改完直接跑： ./cube_pose --config cube_pose.yaml image.jpg\n"
          "#  代码里用：   det.loadConfig(\"cube_pose.yaml\");  det.detect(frame, roi);\n"
          "# =============================================================================\n\n"
          "# ---------- 立方体实物 ----------\n"
          "# 实物边长(m)。【必须按实物改】它决定距离/平面坐标的绝对尺度：\n"
          "# 填错一倍，所有距离和平面距离都会错一倍（像素误差不变）。\n"
          "cubeSize: " << cubeSize << "\n\n"
          "# 相机向下俯仰角(度)。只用于判断\"哪个面朝上\"。\n"
          "# 相机大致水平 -> 0~10；俯视桌面 30~45 都可以。有 IMU 的话可以改成用重力方向。\n"
          "tiltDeg: " << tiltDeg << "\n\n"
          "# ---------- ROI（YOLO 检测框）----------\n"
          "# 填 0 表示不使用固定 ROI，程序会全图搜索 + 自动候选区域重试。\n"
          "# 用 YOLO 时建议代码里直接传 detect(frame, roi)，比写死在 yaml 里灵活。\n"
          "roi_x: " << roi.x << "\n"
          "roi_y: " << roi.y << "\n"
          "roi_w: " << roi.width << "\n"
          "roi_h: " << roi.height << "\n\n"
          "# ROI 自动外扩比例。YOLO 框通常贴得很紧，不加外扩会把立方体轮廓切掉，\n"
          "# 表现就是\"顶点数不是 6\"或重投影 RMS 突然变大。0.15~0.25 比较合适。\n"
          "roiPad: " << roiPad << "\n\n"
          "# 没有 ROI 时是否自动找候选区域（1=开 0=关）\n"
          "autoRoi: " << (autoRoi ? 1 : 0) << "\n\n"
          "# ---------- 分割（把立方体从背景里分出来）----------\n"
          "# 0=自动在下面 4 种里选优  1=Otsu 2=自适应阈值 3=Canny+闭运算 4=Lab色差\n"
          "# 现场如果知道哪种稳，就写死一个，省一半时间\n"
          "segMode: " << segMode << "\n"
          "# 目标比背景暗时置 1（只对 segMode=1 生效）\n"
          "invert: " << (invert ? 1 : 0) << "\n"
          "# 轮廓面积 / ROI 面积 的下限，用来滤掉小噪点\n"
          "minAreaRatio: " << minAreaRatio << "\n\n"
          "# ---------- 轮廓 -> 直线段 ----------\n"
          "# 直线拆分残差阈值(px)：越小越敏感（可能把一个角切成两段），越大越迟钝\n"
          "splitTol: " << splitTol << "\n"
          "# 直线段最短长度(px)，比它短的当成噪声丢掉\n"
          "minRunLen: " << minRunLen << "\n"
          "# 相邻直线段方向差小于该值(度)就合并\n"
          "mergeAngleDeg: " << mergeAngleDeg << "\n\n"
          "# ---------- 亚像素精化 ----------\n"
          "subpix: " << (subpix ? 1 : 0) << "\n"
          "subpixRange: " << subpixRange << "\n\n"
          "# ---------- 相机内参 ----------\n"
          "# 【强烈建议标定】不填则按 fx=fy=W/(2*tan30) 粗估，绝对距离不可信。\n"
          "# 标定后把数值填这里，或填 calibFile 指向 OpenCV 标定 yaml。\n"
          "fx: " << fx << "\n"
          "fy: " << fy << "\n"
          "cx: " << cx << "\n"
          "cy: " << cy << "\n"
          "calibFile: \"" << calibFile << "\"\n\n"
          "# ---------- 调试 ----------\n"
          "# 1 = 结果里带上调试图 result.debugImage（画了掩膜/顶点编号/三个可见面）\n"
          "buildDebugImage: " << (buildDebugImage ? 1 : 0) << "\n"
          "# 非空 = detect() 顺便把调试图写到这个路径\n"
          "debugPath: \"" << debugPath << "\"\n"
          "# 1 = 打印各分割候选与拟合诊断（现场调参用）\n"
          "verbose: " << (verbose ? 1 : 0) << "\n";
    return true;
}

} // namespace cubepose
