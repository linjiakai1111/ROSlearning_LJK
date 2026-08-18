#ifndef HELLOWORLD_HPP_
#define HELLOWORLD_HPP_

#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int16.hpp"

// HelloWorld 类：继承 rclcpp::Node，封装节点初始化与日志打印
class HelloWorld : public rclcpp::Node
{
public:
    std_msgs::msg::String My_name;  // 姓名，沿用 std_msgs 消息类型
    std_msgs::msg::UInt16 My_age;   // 年龄，沿用 std_msgs 消息类型

    // 易错点：单参数构造函数建议加 explicit，防止隐式类型转换
    explicit HelloWorld(const std::string & name);

private:
    // 易错点：形参与成员同名会遮蔽成员，这里按原逻辑保留传参方式
    void myPrint(std_msgs::msg::String My_name, std_msgs::msg::UInt16 My_age);
};

#endif  // HELLOWORLD_HPP_
