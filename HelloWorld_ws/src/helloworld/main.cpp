#include "helloworld.hpp"

// 易错点：rclcpp::init 必须最先调用，shutdown 必须最后调用
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<HelloWorld>("helloworld");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}
