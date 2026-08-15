#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int16.hpp"

class HelloWorld : public rclcpp::Node
{
public:
    std_msgs::msg::String My_name;
    std_msgs::msg::UInt16 My_age;
    HelloWorld(std::string name) : Node(name)
    {
        My_name.data = "林家锴";
        My_age.data = 19;
        myPrint(My_name,My_age);
    }
private:
    void myPrint(std_msgs::msg::String My_name,std_msgs::msg::UInt16 My_age)
    {
        RCLCPP_INFO(this->get_logger(),"Hello World,my name is %s,my age is %d", My_name.data.c_str(), My_age.data);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HelloWorld>("helloworld");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}