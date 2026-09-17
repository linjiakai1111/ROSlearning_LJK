# <center>C++ Matplotlib（matplotlib-cpp）使用说明</center>

> 本文所有代码均在本机实测通过，环境为：
> **Ubuntu 22.04 / g++ 11.4.0 / Python 3.10.12 / matplotlib 3.10.9（pip 用户级）/ numpy 2.2.6（pip 用户级）/ ROS 2 Humble**
> 文中标注“实测”的现象都是在这台机器上真实复现出来的，不是照抄文档。

---

## ==00==-这是什么

**matplotlib-cpp** 是一个**单头文件**（`matplotlibcpp.h`，约 3000 行）的 C++ 库，它把 C++ 的 `std::vector` 等容器数据喂给 Python 的 matplotlib 来画图。

- 官方仓库：<https://github.com/lava/matplotlib-cpp>
- 工作原理：头文件在运行时**嵌入一个 CPython 解释器**（`Py_Initialize`），然后把数据通过 numpy 数组传给 `matplotlib.pyplot` 的函数，所以画出来的图和你用 Python 画的一模一样。
- 它**不是**“用 C++ 重写 matplotlib”，也不是 `gnuplot`/`matplot++` 那类纯 C++ 库。

### 适合 / 不适合

| 适合 | 不适合 |
| --- | --- |
| 调试算法时快速把数据可视化（滤波、控制、SLAM 轨迹） | 对实时性要求高（每帧都要过一次 Python 解释器） |
| 已经在用 Python/matplotlib 做数据分析，想让 C++ 程序出一致的图 | 目标机器没有 Python 环境、或不能装 matplotlib |
| 想在 ROS 节点里直接画传感器/滤波器曲线 | 嵌入式、交叉编译等轻量场景 |
| 想借 matplotlib 的全套样式（中文、对数坐标、colorbar、3D 等） | 需要多线程同时画图（解释器不是线程安全的） |

### 代价

因为它本质是“把 Python 嵌进你的 C++ 程序”，所以：

1. 程序运行时依赖 `numpy` + `matplotlib`，**发布程序时必须带上 Python 环境**；
2. 所有绘图关键字参数都只能传**字符串**（后文 ==06== 有坑详解）；
3. 出现异常时错误信息往往指向“下一个调用”，排查需要技巧。

---

## ==01==-环境准备

### 1. 依赖

| 依赖 | 作用 | 本机检查命令 |
| --- | --- | --- |
| `libpython3.x-dev` | 提供 `Python.h`，用于嵌入解释器 | `ls /usr/include/python3.10/Python.h` |
| `numpy` | C++ 数据 → Python 数组的桥梁 | `python3 -c "import numpy;print(numpy.__version__, numpy.get_include())"` |
| `matplotlib` | 真正的绘图后端 | `python3 -c "import matplotlib;print(matplotlib.__version__)"` |
| C++11 以上的编译器 | 头文件用到了 C++11 | `g++ --version` |

安装（Ubuntu）：

```bash
sudo apt install g++ python3-dev python3-numpy python3-matplotlib
# 或者用 pip 装更新版本的 matplotlib（本文环境就是 pip 用户级安装的）
python3 -m pip install --user matplotlib numpy
```

### 2. 获取头文件

```bash
# 方式一：直接下载单头文件
curl -sL -o matplotlibcpp.h \
  https://raw.githubusercontent.com/lava/matplotlib-cpp/master/matplotlibcpp.h

# 方式二：clone 整个仓库（里面有 examples/ 目录可以对照学习）
git clone https://github.com/lava/matplotlib-cpp.git
```

在代码里这样引用：

```cpp
#include "matplotlibcpp.h"      // 头文件就在同目录/已加入 -I 路径
namespace plt = matplotlibcpp;  // 惯例简写
```

> 编译期不用链接任何 matplotlib 库，**只需链接 Python 库**（`-lpython3.10`）。

---

## ==02==-第一个程序

`demo.cpp`：

```cpp
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
```

### 编译（实测通过的确切命令）

```bash
g++ -std=c++17 demo.cpp -o demo \
    $(python3 -c "import numpy;print('-I'+numpy.get_include())") \
    $(python3-config --includes) \
    -lpython3.10
```

**`-I` 的顺序非常关键**：numpy 的 include 目录必须放在 `${python3-config --includes}` **前面**（原因见 ==06== 第 1 条，顺序反了会编译通过但运行时段错误）。

### 运行

```bash
./demo                      # 有桌面环境：直接出图/存图
MPLBACKEND=Agg ./demo       # 无显示器（SSH、容器、CI）时用 Agg 后端
```

> 无显示器时不要用 `plt::show()`，用 `plt::save()` 存图；本机有桌面（`DISPLAY=:0`，默认后端 `qtagg`），`plt::show()` 可以弹窗。

---

## ==03==-三种工程化编译方式

### 1. 直接 g++（见 ==02==）

### 2. CMake（实测通过）

`CMakeLists.txt`：

```cmake
cmake_minimum_required(VERSION 3.16)
project(mpl_demo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

add_executable(mpl_demo main.cpp)

# 让 numpy 的 include 目录排在前面，避免被 /usr/include/python3.X/numpy（旧版 numpy 1.x）抢先命中
target_include_directories(mpl_demo BEFORE PRIVATE ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(mpl_demo PRIVATE Python3::Python)

target_compile_definitions(mpl_demo PRIVATE NPY_NO_DEPRECATED_API=NPY_1_7_API_VERSION)
```

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build
```

> 实测说明：CMake 生成的编译命令里，`target_include_directories` 的目录是 `-I`，而 `Python3::Python` 导入目标的头文件目录是 `-isystem`，**`-I` 天然排在 `-isystem` 之前**，所以本机即使不写 `BEFORE` 也能正常编译运行；但写上 `BEFORE` 更保险，换机器不容易翻车。

### 3. ROS 2（ament_cmake，实测通过）

目录结构：

```text
src/ros_demo/
├── CMakeLists.txt
├── package.xml
└── src/
    ├── matplotlibcpp.h
    └── plot_node.cpp
```

`package.xml`（关键部分）：

```xml
<buildtool_depend>ament_cmake</buildtool_depend>
<depend>rclcpp</depend>
<export><build_type>ament_cmake</build_type></export>
```

`CMakeLists.txt`：

```cmake
cmake_minimum_required(VERSION 3.8)
project(ros_demo)
set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Python3 COMPONENTS Development NumPy REQUIRED)

add_executable(plot_node src/plot_node.cpp)
target_include_directories(plot_node BEFORE PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${Python3_NumPy_INCLUDE_DIRS})

# 注意：ament_target_dependencies 用的是“无关键字”写法，
# 这里必须同样不加 PRIVATE，否则报错（实测报错原文见下）
target_link_libraries(plot_node Python3::Python)
ament_target_dependencies(plot_node rclcpp)

install(TARGETS plot_node DESTINATION lib/${PROJECT_NAME})
ament_package()
```

```bash
colcon build --packages-select ros_demo
source install/setup.bash
ros2 run ros_demo plot_node
```

> **实测踩坑**：如果写成 `target_link_libraries(plot_node PRIVATE Python3::Python)`，会和 `ament_target_dependencies` 冲突：
> `The keyword signature for target_link_libraries has already been used with the target "plot_node". All uses of target_link_libraries with a target must be either all-keyword or all-plain.`
> 解决办法就是**把 `PRIVATE` 去掉**（与 ament 保持一致）。

---

## ==04==-API 速查表

以下函数都在 `matplotlibcpp.h` 里真实存在（`namespace plt = matplotlibcpp;`）。

### 绘图

| 函数 | 说明 |
| --- | --- |
| `plt::plot(x, y, "fmt")` / `plot(y)` | 折线；`fmt` 与 matplotlib 格式串一致（`"r--"`、`"b.-"`） |
| `plt::plot(x, y, {{"label","a"},{"linewidth","2"}})` | 带关键字参数的版本（值都是字符串！） |
| `plt::named_plot("名字", x, y, "fmt")` | 画线的同时设置 label，配 `legend()` 用 |
| `plt::semilogx/semilogy/loglog(x, y, "fmt")` | 半对数、双对数坐标 |
| `plt::named_semilogx / named_semilogy / named_loglog` | 同上，带 label |
| `plt::scatter(x, y, s, {{"c","green"}})` | 散点；`s` 是点大小（点²） |
| `plt::bar(x, y, ec, ls, lw, kw)` / `barh` | 柱状图 / 条形图 |
| `plt::hist(y, bins, color, alpha, cumulative)` | 直方图 |
| `plt::named_hist(label, y, bins, color, alpha)` | 带 label 的直方图 |
| `plt::errorbar(x, y, yerr, kw)` | 误差棒 |
| `plt::fill(x, y, kw)` / `fill_between(x, y1, y2, kw)` | 面积填充 |
| `plt::stem` / `arrow` / `quiver` / `boxplot` / `contour` / `spy` | 火柴杆 / 箭头 / 矢量场 / 箱线图 / 等高线 / 稀疏矩阵 |
| `plt::imshow(ptr, rows, cols, channels, kw, &out)` | 显示原始图像缓冲区（灰度/彩色） |
| `plt::plot3(x, y, z, kw)` / `plot_surface(x, y, z)` | 3D（见 ==06== 第 9 条） |
| `plt::colorbar(mappable)` | 颜色条，`mappable` 由 `imshow(..., &out)` 拿到 |

### 样式与坐标轴

| 函数 | 说明 |
| --- | --- |
| `plt::title(s)` / `suptitle(s)` / `xlabel(s)` / `ylabel(s)` / `set_zlabel(s)` | 标题与轴标签 |
| `plt::legend()` / `legend(kw)` | 图例（配合 `named_plot`） |
| `plt::grid(true)` | 网格开关 |
| `plt::xlim(a, b)` / `ylim(a, b)` | 设置范围；无参调用是**读取**范围（返回 `std::array<double,2>`） |
| `plt::xticks(v, labels)` / `yticks` / `tick_params` | 刻度 |
| `plt::axhline(y)` / `axvline(x)` / `axvspan(x1,x2)` | 参考线/参考带 |
| `plt::axis("equal")` / `set_aspect_equal()` | 等比例坐标 |
| `plt::rcparams({{"font.sans-serif","Noto Sans CJK JP"}})` | 全局样式（字体、线宽等） |
| `plt::xkcd()` / `annotate(text, x, y)` | 手绘风格 / 标注 |
| `plt::backend("Agg")` | 切换后端 |

### 布局、输出与交互

| 函数 | 说明 |
| --- | --- |
| `plt::figure()` / `figure(n)` | 新建 / 切换图窗 |
| `plt::figure_size(w, h)` | 图窗尺寸（像素） |
| `plt::subplot2grid(nr, nc, r, c)` | **推荐**的多子图方式（见 ==06== 第 4 条） |
| `plt::subplots_adjust(kw)` / `tight_layout()` | 子图间距 |
| `plt::clf()` / `cla()` | 清空整个图窗 / 只清当前子图 |
| `plt::save("a.png", dpi)` | 保存（`dpi` 可选，0 表示用默认） |
| `plt::show(block)` | 显示窗口；`show(false)` 不阻塞 |
| `plt::pause(sec)` | 暂停并处理 GUI 事件（实时刷新必备） |
| `plt::ion()` / `plt::draw()` / `plt::close()` | 交互模式 / 重绘 / 关窗（**注意没有 `ioff()`**） |
| `plt::detail::_interpreter::kill()` | 手动销毁解释器（见 ==06== 第 7 条） |

---

## ==05==-示例合集（均实测通过）

### 1. 多子图 + 曲线样式

```cpp
#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
namespace plt = matplotlibcpp;

int main() {
    plt::figure_size(900, 620);
    plt::rcparams({{"font.sans-serif", "Noto Sans CJK JP"}});   // 中文字体（详见第 2 节；不用中文可删）

    std::vector<double> x(200), s(200), c(200);
    for (int i = 0; i < 200; ++i) {
        x[i] = i * 0.05;
        s[i] = std::sin(x[i]) * std::exp(-0.05 * x[i]);   // 阻尼正弦
        c[i] = std::cos(x[i]);
    }

    plt::subplot2grid(2, 2, 0, 0);                 // 2×2 网格，第 (0,0) 格
    plt::named_plot("阻尼正弦", x, s, "b-");
    plt::named_plot("余弦",     x, c, "r--");
    plt::xlabel("t / s"); plt::ylabel("幅值");
    plt::title("曲线样式"); plt::legend(); plt::grid(true);
    plt::xlim(0.0, 10.0);

    plt::subplot2grid(2, 2, 0, 1);                 // 第 (0,1) 格：散点
    std::vector<double> px(50), py(50);
    for (int i = 0; i < 50; ++i) { px[i] = std::sin(i * 0.3); py[i] = std::cos(i * 0.3); }
    plt::scatter(px, py, 20, {{"c", "green"}, {"marker", "o"}});
    plt::title("散点图");

    plt::subplot2grid(2, 2, 1, 0);                 // 第 (1,0) 格：直方图
    std::vector<double> data(2000);
    for (int i = 0; i < 2000; ++i) {
        double u1 = (rand() % 1000) / 1000.0 + 1e-9, u2 = (rand() % 1000) / 1000.0;
        data[i] = sqrt(-2 * log(u1)) * cos(2 * 3.14159 * u2);   // 近似正态
    }
    plt::hist(data, 30, "steelblue", 0.75);        // bins=30, color, alpha
    plt::title("直方图");

    plt::subplot2grid(2, 2, 1, 1);                 // 第 (1,1) 格：柱状图
    std::vector<double> bx{1, 2, 3, 4}, by{5, 7, 3, 8};
    plt::bar(bx, by, "black", "-", 1.0, {{"color", "orange"}});  // lw 用位置参数传 1.0
    plt::title("柱状图");

    plt::tight_layout();
    plt::save("panels.png", 120);
    return 0;
}
```

### 2. 中文标题与标签（本机实测要点）

```cpp
plt::rcparams({{"font.sans-serif", "Noto Sans CJK JP"},   // 字体名必须是 matplotlib 认得的
               {"axes.unicode_minus", "False"}});         // 负号用 ASCII 的 '-'
```

**实测大坑**：网上到处写的 `"Noto Sans CJK SC"` 在这台机器上**不存在**，matplotlib 会打一堆
`findfont: Generic family 'sans-serif' not found because none of the following families were found: Noto Sans CJK SC`
然后中文全部变成**方框豆腐块**（渲染像素统计：用 JP 字体 1763 个墨点，用不存在的 SC 字体只有 848 个，和 DejaVu 缺字时完全一样）。

查本机到底有哪些中文字体名（照抄这个输出里的名字）：

```bash
python3 -c "import matplotlib.font_manager as fm; print(sorted({f.name for f in fm.fontManager.ttflist if 'CJK' in f.name}))"
# 本机输出：['Noto Sans CJK JP', 'Noto Serif CJK JP']
```

想确认某个字体名是否真的可用：

```bash
python3 -c "
from matplotlib import font_manager as fm
print(fm.findfont(fm.FontProperties(family='Noto Sans CJK JP'), fallback_to_default=False))"
# 本机输出：/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc
```

### 3. 对数坐标 / 误差棒 / 面积填充 / 参考线

```cpp
std::vector<double> x(100), y(100), yerr(100, 0.1), y2(100);
for (int i = 0; i < 100; ++i) { x[i] = i * 0.1; y[i] = std::sin(x[i]); y2[i] = y[i] + 0.3; }

plt::loglog(x, y, "g-");                                  // 双对数
plt::semilogy(x, y, "b-");                                // y 半对数
plt::errorbar(x, y, yerr, {{"fmt", "o"}, {"color", "red"}});
plt::fill_between(x, y, y2, {{"alpha", "0.3"}, {"color", "orange"}});
plt::axhline(0.0, 0.0, 1.0, {{"color", "black"}, {"linestyle", "--"}});  // 水平参考线
```

### 4. 显示图像（imshow + colorbar）

```cpp
int R = 64, C = 64;
std::vector<unsigned char> img(R * C);                     // 灰度图，行优先
for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c) img[r * C + c] = (unsigned char)((r * 4 + c * 2) % 256);

PyObject* mappable = nullptr;
plt::imshow(img.data(), R, C, 1, {{"cmap", "viridis"}}, &mappable);  // 1=灰度, 3=RGB, 4=RGBA
plt::colorbar(mappable);                                   // 颜色条
plt::save("imshow.png");
```

> 如果要直接显示 OpenCV 的 `cv::Mat`，编译时定义 `WITH_OPENCV` 并包含 OpenCV 头文件，头文件里已经内置了 `imshow(const cv::Mat&)` 重载（会自动 BGR→RGB）。

### 5. 实时动态刷新（`ion` + `cla` + `pause`）

```cpp
#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
namespace plt = matplotlibcpp;

int main() {
    plt::figure_size(800, 500);
    plt::ion();                       // 打开交互模式
    std::vector<double> xs, ys;
    for (int k = 0; k < 30; ++k) {    // 模拟实时数据流
        xs.push_back(k * 0.1);
        ys.push_back(std::sin(k * 0.1));
        plt::cla();                                    // 清掉上一帧
        plt::named_plot("实时信号", xs, ys, "b-");
        plt::title("实时更新");
        plt::grid(true);
        plt::pause(0.01);                              // 让 GUI 事件循环转起来
    }
    plt::save("realtime.png");
    plt::close();
    plt::detail::_interpreter::kill();                 // 见 ==06== 第 7 条：避免退出段错误
    return 0;
}
```

**要点**：
- 想看到窗口动起来，必须 `ion()` + 每帧 `cla()` 重画 + `pause()`；`pause()` 不只是延时，它还会处理窗口事件。`plt::show(false)` 也可以非阻塞地显示窗口。
- 结尾的 `close()` + `kill()` 是实测必要的：不加的话，弹过窗的程序退出时段错误（见 ==06== 第 7 条）；加上之后 Agg 与桌面 GUI 后端各跑 2 次，退出码都是 0。

### 6. 综合实例：卡尔曼滤波结果可视化

（放在 `Kalman滤波/` 目录里，配合已有的 `Kalman_filter.cpp` 使用）

```cpp
#include "matplotlibcpp.h"
#include <vector>
#include <cmath>
#include <random>
namespace plt = matplotlibcpp;

int main() {
    // ---- 1. 造一段带噪声的“测量数据”和一阶卡尔曼滤波结果 ----
    std::mt19937 gen(42);
    std::normal_distribution<double> noise(0.0, 0.8);

    std::vector<double> t, z, xk, err;
    double x = 0.0, p = 1.0, q = 1e-3, r = 0.64;
    for (int k = 0; k < 120; ++k) {
        double truth = std::sin(k * 0.05) * 5.0;
        double meas  = truth + noise(gen);
        p += q;
        double K = p / (p + r);
        x += K * (meas - x);
        p *= (1 - K);
        t.push_back(k * 0.1); z.push_back(meas); xk.push_back(x); err.push_back(meas - x);
    }

    // ---- 2. 全局样式：中文字体 + 正常显示负号 ----
    plt::rcparams({{"font.sans-serif", "Noto Sans CJK JP"},
                   {"axes.unicode_minus", "False"}});
    plt::figure_size(1000, 700);

    // ---- 3. 左上：测量值 vs 滤波值 ----
    plt::subplot2grid(2, 2, 0, 0);
    plt::named_plot("含噪测量值", t, z, "b.");
    plt::named_plot("卡尔曼滤波", t, xk, "r-");
    plt::xlabel("时间 t / s"); plt::ylabel("位置 / m");
    plt::title("滤波前后对比"); plt::legend(); plt::grid(true);

    // ---- 4. 右上：残差 ----
    plt::subplot2grid(2, 2, 0, 1);
    plt::plot(t, err, "g-");
    plt::axhline(0.0, 0.0, 1.0, {{"color", "black"}, {"linestyle", "--"}});
    plt::xlabel("时间 t / s"); plt::ylabel("残差 / m");
    plt::title("测量残差"); plt::grid(true);

    // ---- 5. 左下：残差直方图 ----
    plt::subplot2grid(2, 2, 1, 0);
    plt::hist(err, 20, "steelblue", 0.8);
    plt::xlabel("残差 / m"); plt::ylabel("频次"); plt::title("残差分布");

    // ---- 6. 右下：协方差收敛（对数坐标）----
    plt::subplot2grid(2, 2, 1, 1);
    std::vector<double> kk, pp;
    double p2 = 1.0;
    for (int k = 0; k < 120; ++k) { p2 += q; double K = p2 / (p2 + r); p2 *= (1 - K); kk.push_back(k); pp.push_back(p2); }
    plt::semilogy(kk, pp, "m-");
    plt::xlabel("迭代次数"); plt::ylabel("协方差 P"); plt::title("协方差收敛"); plt::grid(true);

    plt::tight_layout();
    plt::save("kalman_report.png", 150);   // 150 dpi，中文渲染无警告 = 字体配置正确
    return 0;
}
```

---

## ==06==-避坑清单（每条都是本机实测现象）

### 1. numpy 头文件顺序错 → 编译通过、运行段错误

Ubuntu 的 `python3-numpy`（本机 **1.21.5**）把头文件装在 `/usr/include/python3.10/numpy/`，
而 pip 装的 numpy（本机 **2.2.6**）头文件在 `~/.local/.../numpy/_core/include`。
如果编译命令把 `/usr/include/python3.10` 放在前面，`#include <numpy/arrayobject.h>` 会命中 **numpy 1.x 的头文件**，
于是：**编译 0 错误，一运行就崩**：

```text
A module that was compiled using NumPy 1.x cannot be run in NumPy 2.2.6 ...
AttributeError: _ARRAY_API not found
段错误 (核心已转储)        # 退出码 139
```

**正确写法**（numpy 的 `-I` 必须在前面）：

```bash
g++ -std=c++17 demo.cpp -o demo \
    $(python3 -c "import numpy;print('-I'+numpy.get_include())") \
    $(python3-config --includes) -lpython3.10
```

### 2. 关键字参数全是字符串 → 数值型 kwargs 会崩

`plot/scatter/bar/...` 的关键字参数类型是 `std::map<std::string, std::string>`，
所有值都会被转成 Python 的 **str**。给需要参与**单位换算**的参数传字符串就会炸：

```cpp
plt::bar(bx, by, "black", "-", 1.0, {{"color","orange"},{"width","0.6"}});  // ❌
// matplotlib 报：ConversionError: Failed to convert value(s) to axis units: '0.6'
```

**解决**：能用**位置参数**就别用关键字——

| 想设置 | 别写 | 应该用 |
| --- | --- | --- |
| 柱宽 | `{"width","0.6"}` | 逃生舱里调 `pyplot.bar(..., width=0.6)`（见 ==07==，实测可行）或用默认柱宽 |
| 柱子线宽 | `{"lw","1.0"}` | `plt::bar(x, y, "black", "-", 1.0, ...)` 第 5 个位置参数 |
| 散点大小 | `{"s","20"}` | `plt::scatter(x, y, 20, ...)` 第 3 个位置参数 |
| 直方图 | `{"bins","30"}` | `plt::hist(y, 30, "steelblue", 0.75)` 位置参数 |
| 线宽 | `{"linewidth","3"}` | 实测**侥幸能用**（matplotlib 内部做了 `float()` 转换），但不保证，重要场合走 ==07== |

### 3. 静默失败 + 错误“污染”下一个调用

很多函数返回 `bool`，**失败时不抛异常，只返回 false，并在 Python 侧残留一个未处理的异常**；
于是**下一个** matplotlib-cpp 调用会抛出一句让人摸不着头脑的错误：

```text
terminate called after throwing an instance of 'std::runtime_error'
  what():  Call to title() failed.        # 真正出错的其实是上一次 bar()
```

排查套路：**检查返回值**，并用 `PyErr_Print()` 打印真正的 Python 报错：

```cpp
bool ok = plt::bar(bx, by, "black", "-", 1.0, {{"color","orange"},{"width","0.6"}});
if (!ok) {
    std::printf("bar 返回 false，PyErr = %d\n", PyErr_Occurred() != nullptr);
    PyErr_Print();     // 打印真实堆栈：ConversionError: ... '0.6'
}
```

（实测输出：`bar(...width="0.6") returned 0, PyErr pending = 1`）

### 4. `subplot()` 传的是浮点数 → 新版 matplotlib 直接报错

头文件里 `subplot()` 用 `PyFloat_FromDouble` 传参，新版 matplotlib 不再接受浮点数
（本机 matplotlib 3.10.9 实测报错如下）：

```text
ValueError: Number of rows must be a positive integer, not 2.0
... what(): Call to subplot() failed.
```

**统一改用 `subplot2grid()`**（它内部用 `PyLong_FromLong`，实测正常）：

```cpp
plt::subplot2grid(2, 2, 0, 0);   // 2×2 网格的第 (0,0) 格，替代 plt::subplot(2,2,1)
```

### 5. 没有 `ioff()`

头文件只提供了 `plt::ion()`，**没有 `ioff()`**（写了会编译报错 `'ioff' is not a member of 'plt'`）。
关闭交互模式用逃生舱调 Python 的 `matplotlib.pyplot.ioff`（见 ==07==）。

### 6. 中文变方框

见 ==05== 第 2 条：字体名必须从 `fontManager.ttflist` 里查，本机只有 `Noto Sans CJK JP` / `Noto Serif CJK JP`。
另外记得把 `axes.unicode_minus` 设为字符串 `"False"`，否则负号显示成方框。

### 7. 程序退出时段错误（GUI 后端）

用 `plt::show()`/`plt::close()` 弹过窗之后，`return 0` 退出时**连续 4 次实测 4 次段错误（退出码 139）**，
因为静态单例解释器的析构顺序/线程问题（头文件注释里也承认了这一点）。
两种可靠写法：

```cpp
// 写法一：头文件推荐的“同线程销毁解释器”
plt::close();
plt::detail::_interpreter::kill();
return 0;                     // 实测：Agg 与 GUI 各 2 次，退出码全为 0

// 写法二：直接跳过静态析构（够用且最简单）
std::fflush(stdout);
_exit(0);                     // 实测退出码 0
```

只 `save()` 存图、不弹窗的程序（Agg 后端）没有这个问题，退出正常。

### 8. 多线程 / ROS 回调里画图

嵌入的 Python 解释器**不是线程安全的**。ROS 回调运行在 executor 线程上，
直接在回调里画图容易崩或卡死。推荐两种做法：

1. **缓存 + 主线程画**（最稳）：回调里只把数据推进 `std::vector`（加锁或 `std::mutex`），
   另开定时器/主循环统一刷新画面；
2. 必须在回调里画时，**给所有 matplotlib-cpp 调用加同一把互斥锁**，并只在**同一个线程**里创建/销毁解释器。

另外，实时刷新时**务必降采样**（例如每 5 帧刷新一次、窗口只保留最近 N 个点）：
每次刷新都要经过 Python 解释器 + GUI 重绘，几十 Hz 的数据很容易来不及刷新
（这条是经验建议，本机没有做高频率压测）。

### 9. 3D 图（`plot_surface` / `plot3`）在本机不可用

```text
Error loading module mpl_toolkits.mplot3d!
```

原因是**两套 matplotlib 混装**：

- pip 用户级 matplotlib **3.10.9**：`mpl_toolkits` 是**命名空间包**（`~/.local/.../mpl_toolkits/`，**没有** `__init__.py`）；
- apt 的 `python3-matplotlib` **3.5.1**：`/usr/lib/python3/dist-packages/mpl_toolkits/` 是**常规包**（**有** `__init__.py`）。

Python 的导入规则是“扫描路径时，后面发现的常规包会覆盖前面发现的命名空间包”，
于是 `import mpl_toolkits.mplot3d` 加载到了 3.5.1 的旧代码，与 3.10.9 的 matplotlib 不兼容：

```text
ImportError: cannot import name 'docstring' from 'matplotlib'
```

**解决思路**（二选一，本机未动手改环境）：
统一安装来源——`sudo apt remove python3-matplotlib` 之后只用 pip 版本，
或反过来卸载 pip 版本、全部用 apt 版本；确认办法：`python3 -c "import mpl_toolkits;print(mpl_toolkits.__file__)"`
应该指向与 matplotlib 同一 site-packages。

### 10. 无显示器环境

SSH / 容器 / CI 里跑，要加后端环境变量，并改用 `save()`：

```bash
MPLBACKEND=Agg ./demo
```

---

## ==07==-逃生舱：直接调用 pyplot（传真正的数值参数）

遇到“必须传数值关键字参数”“需要 `ioff()`”“需要 matplotlib-cpp 没封装的函数”时，
可以直接用 CPython C API 调 pyplot，兼容同一个解释器实例：

```cpp
#include "matplotlibcpp.h"
#include <cstdio>
namespace plt = matplotlibcpp;

// 复用 matplotlib-cpp 已经初始化好的 pyplot 模块
static PyObject* pyplt() {
    static PyObject* m = nullptr;
    if (!m) m = PyImport_ImportModule("matplotlib.pyplot");
    return m;
}

static void call_pyplot(const char* fn, PyObject* args, PyObject* kwargs) {
    PyObject* f = PyObject_GetAttrString(pyplt(), fn);
    if (!f) { PyErr_Print(); return; }
    PyObject* r = PyObject_Call(f, args, kwargs);
    if (!r) PyErr_Print(); else Py_DECREF(r);   // 失败时打印真正的 Python 错误
    Py_DECREF(f);
}

int main() {
    plt::figure_size(800, 500);

    // plt.plot([1,2,3,4], [1,4,9,16], linewidth=3.0, marker="o")  —— linewidth 是真 float
    PyObject* args = Py_BuildValue("([d,d,d,d],[d,d,d,d])", 1.,2.,3.,4., 1.,4.,9.,16.);
    PyObject* kwargs = PyDict_New();
    PyDict_SetItemString(kwargs, "linewidth", PyFloat_FromDouble(3.0));
    PyDict_SetItemString(kwargs, "marker", PyUnicode_FromString("o"));
    call_pyplot("plot", args, kwargs);
    Py_DECREF(args); Py_DECREF(kwargs);

    call_pyplot("ioff", PyTuple_New(0), nullptr);   // matplotlib-cpp 没有 ioff()

    plt::title("escape hatch: linewidth=3 (true float)");
    plt::save("escape.png");
    return 0;
}
```

同理，柱宽这类参数可以在逃生舱里直接调用 `pyplot.bar(..., width=0.6)`（实测可行）：

```cpp
// pyplot.bar([1,2,3,4], [5,7,3,8], width=0.6, color="orange")
PyObject* args = Py_BuildValue("([i,i,i,i],[i,i,i,i])", 1,2,3,4, 5,7,3,8);
PyObject* kwargs = PyDict_New();
PyDict_SetItemString(kwargs, "width", PyFloat_FromDouble(0.6));   // 真 float，不再是 "0.6" 字符串
PyDict_SetItemString(kwargs, "color", PyUnicode_FromString("orange"));
call_pyplot("bar", args, kwargs);
Py_DECREF(args); Py_DECREF(kwargs);
```

---

## ==08==-参考资料

- matplotlib-cpp 仓库与 examples：<https://github.com/lava/matplotlib-cpp>
- matplotlib 官方文档（所有关键字参数的含义都以它为准）：<https://matplotlib.org/stable/api/pyplot_summary.html>
- matplotlib 支持的格式串（`"r--"`、`"b.-"` 等）：<https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.plot.html>
- 嵌入 CPython 的注意事项：<https://docs.python.org/3/extending/embedding.html>
- 相关笔记：同目录 `CMake_learning.md`（CMake 用法）、`openCV/openCV_learning.md`（OpenCV）
