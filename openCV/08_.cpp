#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
void DIY_channels_split(Mat&,int,int);
void split_merge_channels(Mat&,int,int);
void mix_channels(Mat&,int,int);

int main(int argc,char ** argv){
  Mat src = imread("garden.png");
  Mat hsv,shifted_hsv;
  Mat back_to_bgr;//,back_to_bgr_s
  cvtColor(src,hsv,COLOR_BGR2HSV);
  Scalar highest(255,255,255);
  Scalar lowest(100, 0, 0);
  inRange(hsv,lowest,highest,shifted_hsv);
  //得到的shifted_hsv是一个单通道灰色图
  imshow("HSV",hsv);
  imshow("shifted_hsv",shifted_hsv);
  std::cout << shifted_hsv.type() << "-------" 
            << hsv.type() << std::endl;
  cvtColor(shifted_hsv,back_to_bgr,COLOR_GRAY2BGR);
  imshow("ROI",back_to_bgr & src);
  waitKey(0);
  return 0;
}