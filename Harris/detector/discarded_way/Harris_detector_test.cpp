#include <Eigen/Dense>
#include <random>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

//g++ Harris_detector.cpp -I/usr/include/eigen3 $(pkg-config --cflags --libs opencv4) -o Harris_

using namespace cv;
using namespace Eigen;
using namespace std;

int main(int argc,char** argv)
{
  Mat src = imread("cube02.jpg");
  Mat gray_src,source,Ix,Iy,A,B,C;
  cvtColor(src,source,COLOR_BGR2GRAY);
  source.convertTo(gray_src,CV_32F);
  Sobel(gray_src,Ix,CV_32F,1,0,3);
  Sobel(gray_src,Iy,CV_32F,0,1,3);

  Mat Ix2 = Ix.mul(Ix);
  Mat Iy2 = Iy.mul(Iy);
  Mat Ixy = Ix.mul(Iy);

  GaussianBlur(Ix2,A,Size(3,3),1.0);
  GaussianBlur(Iy2,B,Size(3,3),1.0);
  GaussianBlur(Ixy,C,Size(3,3),1.0);

  Mat R = (A.mul(B) - C.mul(C)) - 0.04 * (A + B).mul(A + B);

  Mat display;
  normalize(R, display, 0, 255, NORM_MINMAX);
  threshold(display,display,73,255,THRESH_BINARY);
  int count = 0;
  for(int i=0;i<display.rows;i++)
    for(int j = 0;j<display.cols;j++)
    {
      if(display.at<float>(i,j)){
        //cout<< display.at<float>(i,j) <<endl;
        src.at<Vec3b>(i,j) = {0,0,255};
        count++;
      }
      else{
        display.at<float>(i,j) = 0;
      }
    }
  cout<< count <<endl;
  display.convertTo(display, CV_8UC1);
  imshow("R", display);
  waitKey(0);
  imshow("origin",src);
  waitKey(0);
  return 0;
}