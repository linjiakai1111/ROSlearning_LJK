#include <Eigen/Dense>
#include <random>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

//g++ Harris_detector.cpp -I/usr/include/eigen3 $(pkg-config --cflags --libs opencv4) -o Harris_

using namespace cv;
using namespace Eigen;
using namespace std;

Mat curl_kernel(Mat);
Mat extend_image(Mat);
// class Harris_detetcor{
//   public:
//   private:
// }

Matrix3d Gauss_ = (Matrix3d() << 1.0/16.0,2.0/16.0,1.0/16.0,
                                2.0/16.0,4.0/16.0,2.0/16.0,
                                1.0/16.0,2.0/16.0,1.0/16.0).finished();
//Gauss_ = Gauss_ / Gauss_.sum();
Mat Sobel_ = (Mat_<float>(3,3) <<
    -1, 0,  1,
    -2, 0,  2,
    -1, 0,  1);
int main(int argc,char** argv)
{
  Mat source = imread("house.jpeg",IMREAD_GRAYSCALE);
  Mat image =curl_kernel(extend_image(source));
  //imshow("Sobel_image",image);
  //waitKey(0);
  int height = image.rows;
  int width = image.cols;
  Mat partial_result = Mat::zeros(height-2,width-2,CV_32FC1);
  cout << height <<":"<< width <<endl;
  cout <<"No Error"<< endl;
  for(int row = 1 ;row < height ;row++){
    for(int col = 1;col < width ;col++){
      Matrix2d partial_mat = Matrix2d::Zero();
      //cout << row <<":"<< col <<endl;
      double R;
      double temp_c = 0;
      for(int i =-1;i<2;i++){
        for(int j = -1;j<2;j++){
          double partial_x = image.at<float>(row+j,col+i) - image.at<float>(row,col+i+1);
          double partial_y = image.at<float>(row+j,col+i) - image.at<float>(row+1+j,col);
          Matrix2d partial_mat = partial_mat + Gauss_(1+i,1+j) * (Matrix2d() << pow(partial_x,2),partial_x*partial_y,
                                                                  partial_x*partial_y,pow(partial_y,2)).finished();
        }
      }
      double A = partial_mat(0,0);
      double B = partial_mat(1,0);
      double C = partial_mat(1,1);
      R = A*C-pow(B,2) - 0.04 * pow(A+C,2);
      partial_result.at<float>(row-1,col-1) = R;
    }
  }
  imshow("R_image",partial_result);
  waitKey(0);
  //int count = 0;
}
//int R_clc(Matrix)
Mat curl_kernel(Mat image)//Mat image,int height,int width
{
  int height = image.rows;
  int width = image.cols;
  //cvtColor(image,image,COLOR_BGR2GRAY);
  cout <<width<<":"<<height<< endl;
  Mat Convoluted_result = Mat::zeros(Size(width,height),CV_32FC1);
  cout << "image.rows=" << image.rows << " image.cols=" << image.cols << endl;
  cout << "height=" << height << " width=" << width << endl;
  Mat Convolution_kernel = Sobel_;

  for(int Y_ctr = 1;Y_ctr<height;Y_ctr++)
    for(int X_ctr = 1;X_ctr<width;X_ctr++){
    {
      float Temp = 0.0f;
      for(int delta_x = -1; delta_x < 2 ;delta_x++)
        for(int delta_y = -1; delta_y < 2;delta_y++)
        {
          Temp += Convolution_kernel.at<float>(1+delta_y,1+delta_x) * image.at<uchar>(Y_ctr+delta_y,X_ctr+delta_x);
        }
      Convoluted_result.at<float>(Y_ctr,X_ctr) = Temp;//saturate_cast<uchar>(Temp);
    }
  }
  cout << "result.rows=" << Convoluted_result.rows
       << " result.cols=" << Convoluted_result.cols << endl;
  cout <<Convoluted_result.cols<<":"<<Convoluted_result.rows<< endl;
  // imshow("Convoluted Result",Convoluted_result);
  // waitKey(0);
  // imshow("origin",image);
  // waitKey(0);
  return Convoluted_result;
}