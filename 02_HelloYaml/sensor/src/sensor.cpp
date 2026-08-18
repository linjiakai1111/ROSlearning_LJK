#include "rclcpp/rclcpp.hpp"
#include "sensor/msg/pose_bag.hpp"

class SensorNode : public rclcpp::Node
{
private:
  sensor::msg::PoseBag Bag;
  rclcpp::Publisher<sensor::msg::PoseBag>::SharedPtr sensor_pub;
  rclcpp::TimerBase::SharedPtr timer_;
  double x;
  double y;
  double z;
public:
  explicit SensorNode(const std::string & name) : Node(name)
  {
    RCLCPP_INFO(this->get_logger(), "Sensor node started");

    this->declare_parameter<double>("x",1.0);
    this->declare_parameter<double>("y",2.0);
    this->declare_parameter<double>("z",3.0);

    x=this->get_parameter("x").as_double();
    RCLCPP_INFO(this->get_logger(),"Got x:%.2f",x);
    y=this->get_parameter("y").as_double();
    RCLCPP_INFO(this->get_logger(),"Got y:%.2f",y);
    z=this->get_parameter("z").as_double();
    RCLCPP_INFO(this->get_logger(),"Got z:%.2f",z);

    RCLCPP_INFO(this->get_logger(), "Parameters have successfully initialized");

    sensor_pub=this->create_publisher<sensor::msg::PoseBag>("PoseBag",10);
    timer_=this->create_wall_timer(
        std::chrono::seconds(3),
        [this](){
          Bag.x.data=x;
          Bag.y.data=y;
          Bag.z.data=z;
          sensor_pub->publish(Bag);
        }
    );
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SensorNode>("sensor");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}