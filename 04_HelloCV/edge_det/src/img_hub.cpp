#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <chrono>
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "convex_judge.hpp"

using namespace cv;
using namespace std;

int GRN(int,int);
Mat Find_ConvexHull(Mat&,int,int,const std::vector<Point2f>&);
VideoCapture get_videoINFO(std::string,double&,int&,int&,int&);

class video_hub: public rclcpp::Node{
  public:
  explicit video_hub(const std::string name): Node(name){
    RCLCPP_INFO(this->get_logger(), "node initiated successfully");
    img_acceptor = this->create_subscription<sensor_msgs::msg::Image>(
      "/image_raw",
      rclcpp::QoS(10).reliable(),
      std::bind(&video_hub::image_callback, this, std::placeholders::_1)
    );
  }
  private:
  void image_callback(const sensor_msgs::msg::Image::SharedPtr img_msg){
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(img_msg, sensor_msgs::image_encodings::BGR8);
    Mat frame = cv_ptr->image;
    if(frame.empty()) return;
    img_container = edge_extract(frame, frame.rows, frame.cols);
    if (img_container.empty()) return;
    imshow("edge", img_container[0]);
    if (img_container.size() > 1) imshow("corner", img_container[1]);
    if (USING_CONVEX && img_container.size() > 2) imshow("convex", img_container[2]);
    waitKey(1);
  }
  std::vector<Mat> img_container;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr img_acceptor;
};

int main(int argc,char** argv){
  rclcpp::init(argc,argv);
  auto node = std::make_shared<video_hub>("img_hub");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}