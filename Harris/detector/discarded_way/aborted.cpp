#include <Eigen/Dense>
#include <random>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>

//g++ Harris_detector.cpp -I/usr/include/eigen3 $(pkg-config --cflags --libs opencv4) -o Harris_

using namespace cv;
using namespace Eigen;
using namespace std;
// class Harris_detetcor{
//   public:
//   private:
// }

Matrix3d Gauss_ = (Matrix3d() << 1.0/16.0,2.0/16.0,1.0/16.0,
                                2.0/16.0,4.0/16.0,2.0/16.0,
                                1.0/16.0,2.0/16.0,1.0/16.0).finished();
//Gauss_ = Gauss_ / Gauss_.sum();
Matrix3d Sobel = (Matrix3d() << -1.0,0,1.0,
                                -2.0,0,2.0,
                                -1.0,0,1.0).finished();
int main(int argc,char** argv)
{
  Mat src = imread("house.jpeg",IMREAD_GRAYSCALE);
  Mat image = Mat::zeros(src.rows+2,src.cols+2,CV_8UC1);
  for(int i = 1;i<src.rows+1;i++){
    for(int j = 1;j<src.cols+1;j++){
      image.at<uchar>(i,j) = src.at<uchar>(i-1,j-1);
    }
  }
  imshow("extented_image",image);
  waitKey(0);
  return 0;
}
Mat extend_image(Mat src){
  Mat src = imread("house.jpeg",IMREAD_GRAYSCALE);
  Mat image = Mat::zeros(src.rows+2,src.cols+2,CV_8UC1);
  for(int i = 1;i<src.rows+1;i++){
    for(int j = 1;j<src.cols+1;j++){
      image.at<uchar>(i,j) = src.at<uchar>(i-1,j-1);
    }
  }
  return image;
}
// int height = image.rows;
//   int width = image.cols;
//   Mat Ix_image = Mat::zeros(Size(width-1,height-1),CV_8UC1);
//   Mat Iy_image = Mat::zeros(Size(width-1,height-1),CV_8UC1);
//   Mat background = Mat::zeros(Size(width,height),CV_8UC1);
//   //Mat weight_image = Mat::zeros(Size(width-1,height-1),CV_32FC1);
//   //vector<Matrix2d> Tailar_gray;
//   cout << "height:" << height << "\nwidth:" << width <<endl;
//   for( int row = 1;row<height-1;row++){//height-1
//     for(int col = 1;col<width-1;col++){//width-1
//       Matrix2d M_partial = Matrix2d::Zero();
//       double R = 0;

//       for(int i = -1;i<2;i++){
//         for(int j = -1;j<2;j++){
//           double Ixy = image.at<uchar>(row+i,col+j);
//           double partial_x = static_cast<double>(Ixy - image.at<uchar>(row+i,col+j+1)) / 255;
//           double partial_y = static_cast<double>(Ixy - image.at<uchar>(row+1+i,col+j)) / 255;
//           Matrix2d temp_partial = (Matrix2d() << pow(partial_x,2),partial_x*partial_y,
//                                                      partial_x*partial_y,pow(partial_y,2)).finished();
//           double weight = Gauss_.coeffRef(i,j);
//           M_partial = M_partial + weight * temp_partial;
//             }
//           }

//       //weight_image.at<uchar>(row-1,col-1) =   
//       SelfAdjointEigenSolver<Matrix2d> es(M_partial * 255);//后续改为公式手算
//       if(es.info() != Eigen::Success){
//         //weight_image.at<uchar>(row-1,col-1) = 0;
//         cout << "M_partial对角化失败！！" << endl;}
//       else{
//         Vector2d uni_value = es.eigenvalues();
//         R += uni_value[0]*uni_value[1] - 0.04 * (uni_value[0]+uni_value[1]);

//       cout<< M_partial.coeff(0,0) << " " << M_partial(0,1)
//           <<"\n"<< M_partial.coeff(1,0) << " " << M_partial(1,1)
//           <<"\n"<< R << ":" << uni_value[0] <<"--"<< uni_value[1] 
//           <<"\n------"<<endl;
//       //count++;
//       //if(!count%32)cout << R << ":" << uni_value[0] <<"--"<< uni_value[1] <<endl;
//       if(abs(R) > 0.35){image.at<uchar>(row,col) = 255;background.at<uchar>(row,col) = 255;}
//       // weight_image.at<uchar>(row-1,col-1) = R*255;
        
//       }
//     }
//   }

//   imshow("Gauss_weight",background);
//   waitKey(0);
//   imshow("shifted_image",image);
//   waitKey(0);
// }