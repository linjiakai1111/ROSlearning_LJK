#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <cmath>

using namespace cv;
using namespace std;

Mat Mean = (Mat_<float>(3,3) <<
    1/9.0f,1/9.0f,1/9.0f,
    1/9.0f,1/9.0f,1/9.0f,
    1/9.0f,1/9.0f,1/9.0f);
Mat Gauss = (Mat_<float>(3,3) <<
    1/16.0f,2/16.0f,1/16.0f,
    2/16.0f,4/16.0f,2/16.0f,
    1/16.0f,2/16.0f,1/16.0f);
Mat Sobel_ = (Mat_<float>(3,3) <<
    -1, 0,  1,
    -2, 0,  2,
    -1, 0,  1);

Mat curl_kernel(Mat,int,int);

int main(int argc,char ** argv)
{
  Mat image = imread("park.png");
  Mat lap,gx,gy,bilateral,result;
  cout << "type=" << image.type()
       << " channels=" << image.channels() << endl;
  int height = image.rows;
  int width = image.cols;
  vector<Mat> channels;
  Mat shifted_channels[3];
  split(image,channels);
  for( int i = 0;i<3;i++){
    shifted_channels[i] = curl_kernel(channels[i],height,width);
  }
  merge(shifted_channels,3,result);
  imshow("convolution",result);
  waitKey(0);
  // Laplacian(image,lap,CV_32F);
  // imshow("Laplace",lap);
  // waitKey(0);
  // Sobel(image,gx,CV_32F,1,0,3);
  // imshow("Sobel_x",gx);
  // waitKey(0);
  // Sobel(image,gy,CV_32F,0,1,3);
  // imshow("Sobel_x",gy);
  // waitKey(0);
  // bilateralFilter(image,bilateral,9,75,75);
  // imshow("Sobel_x",bilateral);
  // waitKey(0);

  return 0;
}
Mat curl_kernel(Mat image,int height,int width)
{
  //cvtColor(image,image,COLOR_BGR2GRAY);
  cout <<width<<":"<<height<< endl;
  Mat Convoluted_result = Mat::zeros(Size(width,height),CV_8UC1);
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
      Convoluted_result.at<uchar>(Y_ctr,X_ctr) = saturate_cast<uchar>(Temp);
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
Mat extend_image(Mat src){
  //Mat src = imread("house.jpeg",IMREAD_GRAYSCALE);
  Mat image = Mat::zeros(src.rows+2,src.cols+2,CV_8UC1);
  for(int i = 1;i<src.rows+1;i++){
    for(int j = 1;j<src.cols+1;j++){
      image.at<uchar>(i,j) = src.at<uchar>(i-1,j-1);
    }
  }
  return image;
}