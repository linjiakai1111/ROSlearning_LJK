//发布者节点
#include "rclcpp/rclcpp.hpp"
#include "camera/msg/robot_pose_msg.hpp"
#include "std_msgs/msg/float32.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class vision_sensor : public rclcpp::Node
{
private:
  //声明发布者
  //使用自定义消息类型的时候，ROS会自动把.msg文件从驼峰转为蛇形，但在使用消息类型时还是按照驼峰来(me)
  rclcpp::Publisher<camera::msg::RobotPoseMsg>::SharedPtr camera_pub;
  rclcpp::TimerBase::SharedPtr timer_; 
  std_msgs::msg::Float32 self_add;
  camera::msg::RobotPoseMsg RobotPoseBag;
public:
  explicit vision_sensor(const std::string& name) : Node(name) 
{
  RCLCPP_INFO(this->get_logger(), "Established!");
  camera_pub=this->create_publisher<camera::msg::RobotPoseMsg>("robot_pose_bag",10);
  self_add.data=0.1f;
  // 关键：Float32MultiArray.data 默认是空 vector，必须先扩容到 3 个元素才能下标访问(claude)
  timer_=this->create_wall_timer(
    std::chrono::seconds(1),
    [this](){
      RobotPoseBag.angles.data.resize(3);
      RobotPoseBag.x.data+=self_add.data;
      RobotPoseBag.y.data+=self_add.data;
      RobotPoseBag.z.data+=self_add.data;
      RobotPoseBag.angles.data[0]+=self_add.data;
      RobotPoseBag.angles.data[1]+=self_add.data;
      RobotPoseBag.angles.data[2]+=self_add.data;
      camera_pub->publish(RobotPoseBag);
    }
  );
}
};

int main(int argc,char **argv)
{
  rclcpp::init(argc,argv);
  auto node=std::make_shared<vision_sensor>("camera");
  rclcpp::spin(node);
  rclcpp::shutdown();
}