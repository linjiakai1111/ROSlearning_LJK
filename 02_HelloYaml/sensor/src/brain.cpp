#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/pose_bag.hpp"
#include "sensor/msg/origin_pose.hpp"

using namespace std::placeholders;

class Brain_node:public rclcpp::Node
{
  private:
  double msg_second;
  std::string rob_init_flag;
  rclcpp::Time time_stamp;
  rclcpp::Subscription<sensor::msg::PoseBag>::SharedPtr brain_sub;
  rclcpp::Subscription<sensor::msg::OriginPose>::SharedPtr brain_rob_sub;
  void brain_callback(const sensor::msg::PoseBag::SharedPtr Bag)
  {
    RCLCPP_INFO(this->get_logger(),"x:%.2f,y:%.2f,z:%.2f",Bag->x.data,Bag->y.data,Bag->z.data);
  }
  void brain_rob_callback(const sensor::msg::OriginPose::SharedPtr origin_status)
  {
    time_stamp = rclcpp::Time(origin_status->header.stamp);
    msg_second=time_stamp.seconds();
    rob_init_flag=origin_status->is_init ? "YES":"NO";
    RCLCPP_INFO(this->get_logger(),"\nget message at Time:%f,\nGot OriginalPose:\nr:%.2f,\nsita:%.2f,\n elec_charge:%.2f,\nis_init:%s",
    msg_second,
    origin_status->r.data,
    origin_status->sita.data,
    origin_status->elec_charge.data,
    rob_init_flag.c_str());
  }
  public:
  explicit Brain_node(const std::string name):Node(name)
  {
    brain_rob_sub=this->create_subscription<sensor::msg::OriginPose>("OriginPose",10,std::bind(&Brain_node::brain_rob_callback,this,_1));
    brain_sub=this->create_subscription<sensor::msg::PoseBag>("PoseBag",10,std::bind(&Brain_node::brain_callback,this,_1));
  }
};

int main(int argc,char** argv)
{
  rclcpp::init(argc,argv);
  auto node=std::make_shared<Brain_node>("brain");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}