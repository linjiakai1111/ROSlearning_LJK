#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x(100), y(100);
    for (int i = 0; i < 100; ++i) {
        x[i] = i * 0.1;
        y[i] = std::sin(x[i]);
    }

    plt::plot(x, y, "b-");            // 蓝色实线（format 串与 matplotlib 一致）
    plt::title("Hello matplotlib-cpp");
    plt::xlabel("x");
    plt::ylabel("sin(x)");
    plt::grid(true);
    plt::save("demo.png");            // 存成图片
    return 0;
}