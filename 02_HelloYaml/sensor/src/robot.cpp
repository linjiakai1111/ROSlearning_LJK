#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/origin_pose.hpp"
#include <fstream>

class RobotNode : public rclcpp::Node
{
  public:
    explicit RobotNode(const std::string & name): Node(name)
    {
      init_r_ = this->declare_parameter("r",00.0);
      init_sita_ = this->declare_parameter("sita",0.00);
      is_init_ = this->declare_parameter("is_init",false);
      pub_ms_ = this->declare_parameter("pub_ms",500);

      init_r_ = this->get_parameter("r").as_double();
      init_sita_ = this->get_parameter("sita").as_double();
      is_init_ = this->get_parameter("is_init").as_bool();
      pub_ms_ = this->get_parameter("pub_ms").as_int();

      std::ifstream cap_file("/sys/class/power_supply/BAT0/capacity");
      if(cap_file.is_open()){
         cap_file >> init_elec_;
      }

      if(is_init_) RCLCPP_INFO(this->get_logger(),
        "Initiate Successfully with \nr:%.2f,\nsita:%.2f,\nelec:%.2f"
        ,init_r_,init_sita_,init_elec_);

      rob_init_pub_ = this->create_publisher<sensor::msg::OriginPose>("OriginPose",10);
      
      timer_ = this->create_wall_timer(
        std::chrono::milliseconds(pub_ms_),
        [this](){
          OriginPose.header.stamp = this->get_clock()->now();
          OriginPose.r.data = init_r_;
          OriginPose.sita.data = init_sita_;
          OriginPose.elec_charge.data = init_elec_;
          OriginPose.is_init = is_init_;
          rob_init_pub_->publish(OriginPose);
        }
      );
    }
  private:
    float init_r_;
    float init_sita_;
    float init_elec_=0.0f;
    bool is_init_;
    int pub_ms_;
    sensor::msg::OriginPose OriginPose;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor::msg::OriginPose>::SharedPtr rob_init_pub_;
    //auto rob_current_pub = std::make_shared<>
};

int main(int argc,char** argv)
{
  rclcpp::init(argc,argv);
  auto node = std::make_shared<RobotNode>("robot_node");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}