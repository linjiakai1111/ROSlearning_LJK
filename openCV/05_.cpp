#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
using namespace cv;
int g_r_n();
int main(int argc,char ** argv)
{
  Mat origin_src = imread("park.png");
  int height = origin_src.rows;
  int width = origin_src.cols;
  Mat dst_add,dst_subtract,dst_multiply,dst_divide;
  Mat random_Matrix(Size(width,height),CV_8UC3,Scalar(g_r_n(),g_r_n(),g_r_n()));
  /*直接加减的模式
  imshow("light enhanced origin_src",origin_src+random_Matrix);
  waitKey(0);
  imshow("light diminished origin_src",origin_src-Scalar(g_r_n(),g_r_n(),g_r_n()));
  waitKey(0);
  */
  //使用openCV内置函数的模式
  //加法
  add(origin_src,Scalar(50,50,50),dst_add);
  imshow("added origin_src",dst_add);
  waitKey(0);
  //减法
  subtract(origin_src,Scalar(50,50,50),dst_subtract);
  imshow("subtracted origin_src",dst_subtract);
  waitKey(0);
  //乘法
  multiply(origin_src,Scalar(3,3,3),dst_multiply);
  imshow("divided origin_src",dst_multiply);
  waitKey(0);
  //除法
  divide(origin_src,Scalar(3,3,3),dst_divide);
  imshow("Multiplied origin_src",dst_divide);
  waitKey(0);
  return 0;
}
int g_r_n()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> dist(0,255);
  return dist(gen);
}