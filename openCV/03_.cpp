#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;

int g_r_n();

int main(int argc,char ** argv){
  Mat src_0,src_1,src_2;
  src_0 = imread("park.png");
  src_1=src_0.clone();
  src_0.copyTo(src_2);
  imshow("param=image.clone()拷贝方法",src_1);
  imshow("image.copyTo(param)复制方法",src_2);
  waitKey(0);
  Mat matrix_C1=Mat::zeros(Size(8,8),CV_8UC1);
  Mat matrix_C3=Mat::zeros(Size(8,8),CV_8UC3);
  std::cout<< matrix_C1 << "\n" << 
  matrix_C3 << "\nheight:" << matrix_C3.cols <<
               "\twidth:"<< matrix_C3.rows <<
               "\tchannel:"<< matrix_C3.channels() 
               <<std::endl;
  Mat matrix_ones = Mat::ones(Size(4,4),CV_8UC1);
  Mat matrix_one_C3 = Mat::ones(Size(4,4),CV_8UC3);
  std::cout << matrix_ones << std::endl;
  std::cout << matrix_one_C3 << std::endl;
  matrix_one_C3 = Scalar(255,255,255);
  std::cout << matrix_one_C3 << std::endl;
  Mat random_matrix(Size(512,512),CV_8UC3,Scalar(g_r_n(),g_r_n(),g_r_n()));
  imshow("random_image_matrix",random_matrix);
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