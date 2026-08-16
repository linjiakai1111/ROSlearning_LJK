#include "helloworld.hpp"

// 构造函数：先调用父类 Node 构造，再初始化成员并打印
HelloWorld::HelloWorld(const std::string & name) : Node(name)
{
    My_name.data = "林家锴";
    My_age.data = 19;
    myPrint(My_name, My_age);
}

// 私有打印函数：通过 RCLCPP_INFO 输出日志
void HelloWorld::myPrint(std_msgs::msg::String My_name, std_msgs::msg::UInt16 My_age)
{
    RCLCPP_INFO(
        this->get_logger(),
        "Hello World,my name is %s,my age is %d",
        My_name.data.c_str(),
        My_age.data);
}
