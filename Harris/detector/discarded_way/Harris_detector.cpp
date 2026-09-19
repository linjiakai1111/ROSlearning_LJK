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
  Mat color_src = imread("cube01.jpg");
  int height = color_src.rows;
  int width = color_src.cols;
  cout << width <<":"<< height << endl;
  Mat gray_src;
  cvtColor(color_src,gray_src,COLOR_BGR2GRAY);
  vector<Point2f> corners;
  cout << "No Error" << endl;
  goodFeaturesToTrack(
    gray_src,
    corners,
    100,
    0.01,
    10
  );
  cout << "No Error" << endl;
  for(auto& point : corners){
    int x = point.x;
    int y = point.y;
    if( x<= width && y<=height){
      color_src.at<Vec3b>(y,x) = {0,0,255};
    }
    cout << "角点坐标: (" << point.x << ", " << point.y << ")" << endl;
  }
  imshow("corner",color_src);
  waitKey(0);
  return 0;
}