#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main(int argc,char ** argv)
{
  Mat src_park01=imread("park.png");
  Mat src_park02=src_park01.clone();
  int park_h = src_park01.rows;
  int park_w = src_park01.cols;
  int dims = src_park01.channels();
  std::cout << "height:" << park_h
       << "\nwidth:" << park_w
       << std::endl;
  for(int h = 0 ;h < park_h ; h++)
    for(int w = 0 ;w < park_w ; w++)
    {
        if(dims == 1)
        {
          int pv = src_park01.at<uchar>(h,w);
          src_park01.at<uchar>(h,w) = 255 - pv;
        }
        if(dims == 3)
        {
          Vec3b bgr = src_park01.at<Vec3b>(h,w);
          src_park01.at<Vec3b>(h,w)[0] = 255 - bgr[0];
          src_park01.at<Vec3b>(h,w)[1] = 255 - bgr[1];
          src_park01.at<Vec3b>(h,w)[2] = 255 - bgr[2];
        }
    }
  for(int h = 0; h < park_h ; h++ ){
    uchar* current_row = src_park02.ptr<uchar>(h);
    for(int w = 0 ; w < park_w ; w++ )
    {
      if(dims == 1)
      {
        *current_row++ = 255 - *current_row;
      }
      if(dims == 3)
      {
        *current_row++ = 255 - *current_row;
        *current_row++ = 255 - *current_row;
        *current_row++ = 255 - *current_row;
      }
    }
  }
    imshow("Converted RGB src_park01",src_park01);
    waitKey(0);
    imshow("Converted RGB src_park02",src_park02);
    waitKey(0);
  return 0;
}