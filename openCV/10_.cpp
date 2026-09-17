#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <cmath>

using namespace cv;
using namespace std;

void normalized_image(Mat&,int,int);
void rotate(Mat&,int,int);

int main(int argc,char ** argv)
{
  Mat image = imread("park.png");
  int height = image.rows;
  int width = image.cols;
  //normalized_image(image,height,width);
  // resize(image,image,Size(512,512));
  // imshow("hhhh",image);
  // waitKey(0);
  rotate(image,height,width);
  return 0;
}

void rotate(Mat& image,int height,int width)
{
  Mat rotation_matrix = getRotationMatrix2D(Point2f(width/2,height/2),45.0,1.0);
  Mat rotated_image;
  warpAffine(image,rotated_image,rotation_matrix,image.size(),INTER_LINEAR,0,Scalar(0,0,255));
  imshow("rotated_image",rotated_image);
  waitKey(0);
}
void normalized_image(Mat& image,int height,int width)
{
  Mat normalized_image,int_shifted_image;
  int_shifted_image = Mat::zeros(height,width,CV_8UC3);
  normalize(image,normalized_image,0,1,NORM_MINMAX,CV_32F);
  vector<Mat> splited_shifted;
  for(int i = 0;i<height;i++){
    for(int j = 0;j<width;j++){
      for(int k = 0;k<3;k++){
        int_shifted_image.at<Vec3b>(i,j)[k] = (normalized_image.at<Vec3f>(i,j)[k] > 0.2) ? 255:0;
      }
    }
  }
  // imshow("原图",image);
  // waitKey(0);
  // imshow("CV_32F图",normalized_image);
  // waitKey(0);
  imshow("二值化",int_shifted_image);
  waitKey(0);
  split(int_shifted_image,splited_shifted);
  Mat zero_Mat = Mat::zeros(height,width,CV_8UC1);
  for (int i = 0;i<3;i++)
  {
    Mat temp;
    Mat tplt[3] = {zero_Mat,zero_Mat,zero_Mat};
    tplt[i] = splited_shifted[i];
    merge(tplt,3,temp);
    imshow("Channel " + to_string(i),temp);
    waitKey(0);
  }
}