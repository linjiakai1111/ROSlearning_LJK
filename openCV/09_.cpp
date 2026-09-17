#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <cmath>

using namespace cv;
using namespace std;

int g_r_n(int,int);
void find_max_int(Mat&,Mat&,int,int);
void draw_line_with_slope(Mat&);
float slope(int*);
Mat get_slope_image(Mat&,int,int);
void draw_polyline(Mat&);

int main(int argc,char ** argv)
{
  Mat image = imread("park.png");
  Mat gray_image;
  Mat background = Mat::zeros(512,512,CV_8UC3);
  cout << background.cols << ":" << background.rows << endl;
  cvtColor(image,gray_image,COLOR_BGR2GRAY);
  int height = image.rows;
  int width = image.cols;
  //draw_line_with_slope(background);
  imshow("grad image",get_slope_image(image,height,width));
  waitKey(0);
  //draw_polyline(background);
  return 0;
}
void draw_line_with_slope(Mat& background)
{
  int loc_xy[4] = {0,0,0,0};
  //find_max_int(image,gray_image,height,width);
  for(int i = 0 ; i < 50 ; i++ ){
    for( int j = 0 ; j < 4 ; j++ ){
      if((j+1)%2) loc_xy[j] = g_r_n(0,background.cols);
      else loc_xy[j] = g_r_n(0,background.rows);
    } 
    line(background,
        Point(loc_xy[0],loc_xy[1]),
        Point(loc_xy[2],loc_xy[3]),
        Scalar(g_r_n(0,255),g_r_n(0,255),g_r_n(0,255)),
        1,
        LINE_AA,
        0);
    cout << "slope level: " 
         << slope(loc_xy)
         << endl;
    imshow("random_line",background);
    waitKey(10);
    }
}
int g_r_n(int min,int max)
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(min,max);
  return dist(gen);
}
void find_max_int(Mat& image,Mat& gray_image,int height,int width)
{
  Mat mean,stddev;
  double min,max,grad_min,grad_max;
  Point MinLoc,MaxLoc;
  minMaxLoc(gray_image,&min,&max,&MinLoc,&MaxLoc);
  cout << "min: " << min << "MinLocation:" << MinLoc
       << "\nmax: " << max << "MaxLocation:" << MaxLoc << endl;
  meanStdDev(image,mean,stddev);
  cout << "mean:\n" << mean 
       << "\nstandard_deviation:\n" << stddev << endl;
}
float slope(int* loc_xy)
{
  // if((sizeof(loc_xy)/sizeof(int)) == 4)
  if(sizeof(loc_xy[0]) == 4)
  {
    return (loc_xy[3]-loc_xy[1])/static_cast<float>((loc_xy[2]-loc_xy[0]));
  }
    else return  0.000111;
}
Mat get_slope_image(Mat& image,int height,int width)
{
  Mat image_grad = Mat::zeros(Size(width-1,height-1),CV_32FC3);
  Mat normalized_grad;
  for(int i = 0;i < height-1;i++)
  {
    for(int j = 0;j < width-1;j++)
    {
      Vec3b pixel_o = image.at<Vec3b>(i,j);
      Vec3b pixel_x = image.at<Vec3b>(i,j+1);
      Vec3b pixel_y = image.at<Vec3b>(i+1,j);
      for(int k = 0;k<3;k++)
      {
        image_grad.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(pow( pow(pixel_x[k]-pixel_o[k],2) + pow(pixel_y[k]-pixel_o[k] , 2 ),0.5));
      }
    }
  }
  //normalize();
  return image_grad;
}
void draw_polyline(Mat& background)
{
  std::vector<cv::Point> pts;
  for(int i = 0; i < 9 ; i++)
  {
    pts.push_back(Point(g_r_n(0,background.cols),g_r_n(0,background.rows)));
  }
  polylines(
    background,
    pts,
    true,
    Scalar(255,255,255),
    1,
    LINE_AA,
    0
  );
  imshow("polylines",background);
  waitKey(0);
}
void Normalize_image(Mat& image)
{
  Mat normalized_image;
  normalize(image,normalized_image,0,1,NORM_MINMAX);
  
}