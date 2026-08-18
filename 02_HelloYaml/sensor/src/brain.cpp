#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/pose_bag.hpp"

using namespace std::placeholders;

class Brain_node:public rclcpp::Node
{
  private:
  rclcpp::Subscription<sensor::msg::PoseBag>::SharedPtr brain_sub;
  void brain_callback(const sensor::msg::PoseBag::SharedPtr Bag)
  {
    RCLCPP_INFO(this->get_logger(),"x:%.2f,y:%.2f,z:%.2f",Bag->x.data,Bag->y.data,Bag->z.data);
  }
  public:
  explicit Brain_node(const std::string name):Node(name)
  {
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