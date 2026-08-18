#include "rclcpp/rclcpp.hpp"
#include "camera/msg/robot_pose_msg.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class Machine: public rclcpp::Node
{
  private:
  rclcpp::Subscription<camera::msg::RobotPoseMsg>::SharedPtr machine_sub;
  void Machine_callback(const camera::msg::RobotPoseMsg::SharedPtr RobotPoseBag)
  {
    RCLCPP_INFO(this->get_logger(),"Get RobotPoseBag!");
    RCLCPP_INFO(this->get_logger(),"x:%.2f  y:%.2f  z:%.2f,angles{roll:%.2f,pitch:%.2f,yaw:%.2f}",
    RobotPoseBag->x.data,
    RobotPoseBag->y.data,
    RobotPoseBag->z.data,
    RobotPoseBag->angles.data[0],
    RobotPoseBag->angles.data[1],
    RobotPoseBag->angles.data[2]);
  };
  public:
  explicit Machine(const std::string name):Node(name)
  {
    machine_sub = this->create_subscription<camera::msg::RobotPoseMsg>("robot_pose_bag",10,std::bind(&Machine::Machine_callback,this,_1));
  };
};

int main(int argc,char **argv)
{
  rclcpp::init(argc,argv);
  auto node=std::make_shared<Machine>("Machine"); 
  rclcpp::spin(node);
  rclcpp::shutdown();
}
