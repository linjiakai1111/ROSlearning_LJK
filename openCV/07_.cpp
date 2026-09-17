#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
void DIY_channels_split(Mat&,int,int);
void split_merge_channels(Mat&,int,int);
void mix_channels(Mat&,int,int);

int main(int argc,char ** argv){
  Mat src_1 = imread("garden.png");
  int height = src_1.rows;
  int width = src_1.cols;
  //DIY_channels_split(src_1,height,width);
  //split_merge_channels(src_1,height,width);
  mix_channels(src_1,height,width);
  return 0;
}

void DIY_channels_split(Mat& src_1,int height,int width)
{
  Mat R_src,G_src,B_src;

  R_src = Mat::zeros(Size(width,height),CV_8UC3);
  R_src.copyTo(G_src);
  R_src.copyTo(B_src);
    int dims = R_src.channels();
  for (int h = 0; h<height ; h++)
    for (int w = 0; w<width ; w++)
    {
      if(dims == 3)
      {
        Vec3b pixel = src_1.at<Vec3b>(h,w);
        B_src.at<Vec3b>(h,w)[0] |= pixel[0];
        G_src.at<Vec3b>(h,w)[1] |= pixel[1];
        R_src.at<Vec3b>(h,w)[2] |= pixel[2];
      }
    }
  imshow("Blue",B_src);
  waitKey(0);
  imshow("Green",G_src);
  waitKey(0);
  imshow("Red",R_src);
  waitKey(0);
  imshow("All",R_src + B_src + G_src);
  waitKey(0);
  imshow("All",R_src + B_src + G_src);
  waitKey(0);
}
void split_merge_channels(Mat& src_1,int height,int width)
{
  std::vector<Mat> channels_hub;
  split(src_1,channels_hub);
  Mat zero_0 = Mat::zeros(height,width,CV_8UC1);
  
  Mat B_chn[3] = {channels_hub[0],zero_0,zero_0};
  Mat blue_img;
  merge(B_chn,3,blue_img);

  Mat G_chn[3] = {zero_0,channels_hub[1],zero_0};
  Mat green_img;
  merge(G_chn,3,green_img);

  Mat R_chn[3] = {zero_0,zero_0,channels_hub[2]};
  Mat red_img;
  merge(R_chn,3,red_img);

  imshow("Blue",blue_img);
  waitKey(0);
  imshow("Green",green_img);
  waitKey(0);
  imshow("Red",red_img);
  waitKey(0);
}
void mix_channels(Mat& src_1,int height,int width)
{
  std::string Name[]={"Red","Green","Blue"};
  Mat ZERO_ = Mat::zeros(Size(width,height),CV_8UC1);
  Mat Format_split[3] = {ZERO_,ZERO_,ZERO_};
  Mat bgr[3];
  Mat image;
  int color_format[] = {0,2,1,1,2,0};
  for(int i = 0;i < 3 ; i++ )
    bgr[i].create(Size(width,height),CV_8UC1);
  mixChannels(&src_1,1,bgr,3,color_format,3);
  for(int i = 0;i < 3 ; i++ ){
    Format_split[i]=bgr[i];
    merge(Format_split,3,image);
    imshow(Name[i],image);
    waitKey(0);
    for(int i = 0;i < 3 ; i++ )
      Format_split[i] = ZERO_;
  }
}
