#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <chrono>
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.hpp"

#define USING_HARRIS false
#define USING_CONVEX false

using namespace cv;
using namespace std;

int GRN(int,int);
Mat Find_ConvexHull(Mat&,int,int,const std::vector<Point2f>&);
VideoCapture get_videoINFO(std::string,double&,int&,int&,int&);

class video_hub: public rclcpp::Node{
  public:
  explicit video_hub(const std::string name): Node(name){
    RCLCPP(this->get_logger(),"node initiated successfully");
    img_acceptor = this->create_subscription<sensor_msgs::msg::Image>(
      "/image_raw",
      rclcpp::Qos(10).reliable(),
      std::bind(&video_hub::image_callback,this,std::placeholders::_1)
    );
  }
  private:
  void image_callback(const sensor_msgs::msg::Image::SharedPtr img_msg){
    CVbridgr::CVImagePtr cv_ptr = CVbridgr::toCvCopy(img_msg,sensor_msgs::image_encodings::BGR8);
    Mat frame = cv_ptr -> image;
    if(frame.empty()) return;

    Copy()
  }
  rclcpp::Subscription<sensor_msgs::msg::Image> img_acceptor;
}

int main(int argc,char** argv){
  rclcpp::init(argc,argv);
  auto node = std::make_shared<video_hub>("video_hub");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}