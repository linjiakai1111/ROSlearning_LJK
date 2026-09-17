#include <opencv2/opencv.hpp>

int main(int argc,char ** argv)
{
  cv::Mat src = cv::imread("park.png",cv::IMREAD_GRAYSCALE);
  cv::namedWindow("输入窗口",cv::WINDOW_FREERATIO);
  if(src.empty())
  {
    printf("Couldn't find image");
  }
  cv::imshow("Kalman_Filter",src);
  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}
//g++ 11_.cpp -o 11_ `pkg-config --cflags --libs opencv4`