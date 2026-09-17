#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>
#include <Eigen/Dense>
#include <cmath>
#include "matplotlibcpp.h"
#include <vector>

using namespace cv;
using namespace std;
using namespace Eigen;
namespace plt = matplotlibcpp;

class Kalman_Filter
{
  public:
    explicit Kalman_Filter()
    {
      
    }

    void predict_situation(double acc,double delta_t)
    {
      transform << 1,delta_t,
                   0,1;
      pred_t1 = transform * dfn_t0 + acc_shift * acc;
      cout << "模型估计值 x:" << pred_t1[0] << endl;
    }

    void predict_convariance()
    {
      pre_cvr = transform * dfn_cvr * transform.transpose() + procedure_cvr;
    }

    void update_gain()
    {
      // observor * pre_cvr * observor^T 是 1x1 矩阵，观测噪声是标量，
      // Eigen 不允许 矩阵 + 标量，所以直接取出标量再相加
      double S = (observor * pre_cvr * observor.transpose())(0, 0) + cvr_mistake;
      // S 是标量，除以它就是乘逆
      Kalman_gain = pre_cvr * observor.transpose() / S;
    }

    void update_situation()
    {
      cout << "传感器数值 x:" << sensor_x_ <<endl;
      cout << "二者的差值 x:" << pred_t1[0]-sensor_x_ <<endl;
      position_ = sensor_x_;
      Vector2d temp_v = dfn_t1;
      // 同样：sensor_x_ 是标量，observor * pred_t1 是 1x1 矩阵，先取出标量
      double innovation = sensor_x_ - (observor * pred_t1)(0, 0);
      dfn_t1 = pred_t1 + Kalman_gain * innovation;
      dfn_t0 = temp_v;
    }
    void update_convariance()
    {
      dfn_cvr =(eye_mat - Kalman_gain * observor) * pre_cvr;
    }

    Vector2d init_Kalman(double acc,double delta_t,double sensor_x){
        cout << "启用Kalman滤波器" <<endl;
        acc_shift = {(1/2.0)*pow(delta_t,2),delta_t};
        sensor_x_ = sensor_x;
        predict_situation(acc,delta_t);
        predict_convariance();
        update_gain();
        update_situation();
        return dfn_t1;
    }

    int return_model_x(){return pred_t1[0];}

  private:
    Matrix<double,2,2> predict;  //状态向量
    Matrix<double,2,2> transform;//状态转移矩阵
    // 类内不能用 << 初始化，要写成 (Matrix2d() << ...).finished()
    Matrix2d procedure_cvr = (Matrix2d() << 0.01,0.01,0.01,0.01).finished();//过程噪声矩阵
    Matrix2d eye_mat = Matrix2d::Identity();//单位阵
    //Vector2d ori_situation;       //*****初始状态*****
    Vector2d pred_t1 = Vector2d::Zero();   //t时刻先验状态
    Vector2d dfn_t1  = Vector2d::Zero();   //t时刻确定状态
    Vector2d dfn_t0 = {0,0};             //t-1时刻确定状态
    Vector2d acc_shift;          //加速度转状态
    //Vector2d pre_mistake = {{0.01,0.01},{0.01,0.01}};        //*****先验状态噪声*****
    double cvr_mistake = 0.01;        //*****协方差误差噪声*****
    Matrix2d pre_cvr = (Matrix2d() << 10,0.01,10,0.01).finished();//*****先验协方差*****
    Matrix2d dfn_cvr = Matrix2d::Zero();                //确定协方差
    RowVector2d observor = {1,0};   //观测矩阵
    Vector2d Kalman_gain;        //卡尔曼增益
    double x_t1;
    double x_t0 = 0;            //位移
    double v_t1;
    double v_t0 = 0;            //速度
    double a_t1,position_,sensor_x_;                 //加速度
};
double random_double(){
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> dist(1,10000);
  return dist(gen)/10000.0;
}
int main(int argc,char** argv)
{
  double t = 0;
  double acc = 20;
  Kalman_Filter kmft;
  vector<double> x_history,model_xlist,sensor_xlist;
  vector<double> t_roll;
  plt::ion();
  for(int i = 0;i<100;i++){
      double sensor_x = 2*i+random_double()*2;
      double delta_t = 0.05 + random_double()/100.0;
      t+=delta_t;
      Vector2d result = kmft.init_Kalman(acc,delta_t,sensor_x);
      cout << "x:" << result[0] << "\nv:" << result[1] << endl;
      model_xlist.push_back(kmft.return_model_x());
      sensor_xlist.push_back(sensor_x);
      x_history.push_back(result[0]);
      t_roll.push_back(t);
      plt::cla();
      plt::plot(t_roll,x_history);
      plt::plot(t_roll,model_xlist,"-r");
      plt::plot(t_roll,sensor_xlist,"-b");
      plt::pause(0.05);
  }
  //plt::set_aspect_equal();
  plt::show();
  while (true) {
    plt::pause(1);
  }
  return 0;
}