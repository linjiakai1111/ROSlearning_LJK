```cpp
#include <iostream>
#include <Eigen/Dense>

int main() {
    // 1. 固定大小矩阵（编译期确定，性能最高）
    Eigen::Matrix3d mat3x3; // 3x3 双精度矩阵
    Eigen::Vector3f vec3;   // 3维 单精度向量

    // 2. 动态大小矩阵（运行时确定）
    Eigen::MatrixXd dyn_mat(4, 5); // 4行5列 双精度矩阵
    Eigen::VectorXd dyn_vec(10);   // 10维 双精度向量

    // 3. 逗号初始化（非常直观）
    Eigen::Matrix2d A;
    A << 1, 2, 
         3, 4;

    // 4. 特殊矩阵生成
    Eigen::Matrix3d zero_mat = Eigen::Matrix3d::Zero();     // 全零矩阵
    Eigen::Matrix3d eye_mat = Eigen::Matrix3d::Identity();  // 单位矩阵
    Eigen::MatrixXd rand_mat = Eigen::MatrixXd::Random(3,3);// 随机矩阵

    std::cout << "Matrix A:\n" << A << std::endl;
    return 0;
}
```
```cpp
Eigen::Matrix3d A, B;
A << 1, 2, 3, 4, 5, 6, 7, 8, 9;
B << 9, 8, 7, 6, 5, 4, 3, 2, 1;

// 1. 元素访问（下标从 0 开始）
A(0, 1) = 10; // 修改第 0 行第 1 列的元素
double val = A(1, 1); // 读取元素

// 2. 矩阵加减与标量乘除
Eigen::Matrix3d C = A + B;
Eigen::Matrix3d D = A * 2.0;

// 3. 矩阵乘法（注意维度匹配）
Eigen::Matrix3d E = A * B; 

// 4. 向量专属运算
Eigen::Vector3d v1(1, 2, 3), v2(4, 5, 6);
double dot_res = v1.dot(v2);       // 点积
Eigen::Vector3d cross_res = v1.cross(v2); // 叉积
```
``` cpp
// 转置与逆矩阵
Eigen::Matrix3d A_trans = A.transpose();
Eigen::Matrix3d A_inv = A.inverse();

// 矩阵属性
double det = A.determinant(); // 行列式
double tr = A.trace();        // 迹

// 块操作（提取子矩阵）
Eigen::Matrix2d sub_block = A.block<2,2>(0,0); // 提取左上角 2x2 块
```
```cpp
Eigen::Matrix3d A;
Eigen::Vector3d b;
A << 1, 2, 3,  4, 5, 6,  7, 8, 10;
b << 3, 3, 4;

// 使用 LU 分解求解
Eigen::Vector3d x = A.lu().solve(b); 
std::cout << "Solution x:\n" << x << std::endl;

// 对于对称正定矩阵，推荐使用 Cholesky (LLT) 分解，速度更快
// Eigen::Vector3d x = A.llt().solve(b); 
```
```cpp
// 先声明一个 2x2 的矩阵
Eigen::Matrix2d mat; 
// 然后再使用逗号初始化器
mat << 1, 2, 
       3, 4; 
```
```cpp
// 直接通过花括号初始化，外层代表行，内层代表列
Eigen::Matrix2d mat = {
    {1, 2}, 
    {3, 4}
};

// 对于向量也可以这样写
Eigen::Vector3d vec = {1.0, 2.0, 3.0};
```
```cpp
// 直接在创建时传入元素
Eigen::Vector4d vec(1, 2, 3, 4); 
```