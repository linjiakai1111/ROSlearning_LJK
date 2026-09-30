#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char ** argv){
  Mat gray,hsv,color;
  Mat src = imread("park.png");
  cvtColor(src,hsv,COLOR_BGR2HSV);
  cvtColor(src,gray,COLOR_BGR2GRAY);
  cvtColor(gray,color,COLOR_GRAY2BGR);
  std::cout << color.channels() << std::endl;
  imshow("gray2bgr",color);
  waitKey(0);
  imshow("HSV",hsv);
  waitKey(0);
  imwrite("/home/line/ROSlearning_LJK/openCV/park_hsv.png",hsv);
  imshow("GRAY",gray);
  waitKey(0);
  std::cout <<gray.channels()<<std::endl;
  imwrite("/home/line/ROSlearning_LJK/openCV/park_gray.png",gray);
  Mat test = imread("park_gray.png");
  std::cout <<test.channels()<<std::endl;
  return 0;
}