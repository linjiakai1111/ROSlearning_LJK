#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
using namespace cv;
using namespace std;
void Rect_Picture_Show(Mat src1,Mat src2);
int main(int argc,char ** argv)
{
  Mat with_rctg_1(Size(400,400),CV_8UC3,Scalar(32,64,128));
  Mat with_rctg_2 = with_rctg_1.clone();
  Rect rctg_1(Point(50,50),Point(350,250));
  Rect rctg_2(Point(150,100),Point(250,350));
  rectangle(with_rctg_1,rctg_1,Scalar(255,255,0),-1,LINE_8,0);
  rectangle(with_rctg_2,rctg_2,Scalar(255,255,0),-1,LINE_8,0);
  imshow("Rectangle",with_rctg_1);
  waitKey(0);
  imshow("Rectangle",with_rctg_2);
  waitKey(0);
  imshow("Rectangle",with_rctg_2 & with_rctg_1);
  waitKey(0);
  Mat Or_ = with_rctg_2 | with_rctg_1;
  for( int i = 0 ; i<3 ; i++ )
    cout << static_cast<int>(Or_.at<Vec3b>(200,200)[i]) << endl;
  cout << "rctg_1面积：" << rctg_1.area() << endl;
  for( int i = 0 ; i<3 ; i++ )
    cout << static_cast<int>(Or_.at<Vec3b>(150,300)[i]) << endl;
  cout << "rctg_2面积：" << rctg_2.area() << endl;
  imshow("Rectangle",Or_);
  waitKey(0);
  imshow("Rectangle",with_rctg_2 ^ with_rctg_1);
  waitKey(0);
  imshow("Rectangle", ~ with_rctg_1);
  waitKey(0);

  //Rect_Picture_Show(imread("park.png"),imread("garden.png"));
  return 0;
}
void Rect_Picture_Show(Mat src1,Mat src2)
{
  cout << "src1: " << src1.cols << "x" << src1.rows 
       << "src2: " << src2.cols << "x" << src2.rows << endl;

  resize(src2, src2, src1.size());
  Mat result_And = src1&src2;
  imshow("AND Result",result_And);
  waitKey(0);
  Mat result_Or = src1|src2;
  imshow("OR Result",result_Or);
  waitKey(0);
  Mat result_Xor = src1^src2;
  imshow("XOR Result",result_Xor);
  waitKey(0);
  Mat result_Not = ~src2;
  imshow("Not Result",result_Not);
  waitKey(0);
  //imwrite("/home/line/ROSlearning_LJK/openCV/Xor_mix.png",result);
}