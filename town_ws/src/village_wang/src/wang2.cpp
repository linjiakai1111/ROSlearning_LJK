#include "rclcpp/rclcpp.hpp"
//1.导入接受者消息类型 std_msgs/msg/String
#include "std_msgs/msg/string.hpp"
//导入发布者的消息接口类型
#include "std_msgs/msg/u_int32.hpp"
#include "village_interfaces/srv/sell_novel.hpp"
#include <queue>

using std::placeholders::_1;
using std::placeholders::_2;
class SingleDogNode: public rclcpp::Node
{
private:
    //3.申明订阅者
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_novel;
    //2.创建回调函数
    rclcpp::Publisher<std_msgs::msg::UInt32>::SharedPtr pub_money;
    std::queue<std::string>novels_queue;

    //声明回调组
    rclcpp::CallbackGroup::SharedPtr sell_novels_callback_group;
    //声明服务端
    rclcpp::Service<village_interfaces::srv::SellNovel>::SharedPtr sell_server;

    void novel_callback(const std_msgs::msg::String::SharedPtr novels)
    {
        std_msgs::msg::UInt32 money;
        money.data = 10;
        pub_money->publish(money);

        novels_queue.push(novels->data);

        //4.编写回调处理逻辑
        RCLCPP_INFO(this->get_logger(), "朕已阅 %s", novels->data.c_str());
    }
    //创建买书请求回调函数
    void sell_novel_callback(const village_interfaces::srv::SellNovel::Request::SharedPtr request,
                            const village_interfaces::srv::SellNovel::Response::SharedPtr response)
    {
        RCLCPP_INFO(this->get_logger(), "受到一个买书的请求，一共给了%u元", request->money);
        // 计算返回给客户端的小说数量（每本书1元）
        unsigned int num = request->money / 1u;

        if (num>novels_queue.size())
        {
            RCLCPP_INFO(this->get_logger(),"书不够，书库里有%d,要卖出去%d",(int)novels_queue.size(),num);
            rclcpp::Rate rate(1);
            while(novels_queue.size()<num)
            {
                RCLCPP_INFO(this->get_logger(),"等待中，目前还差%ld的小说",num-novels_queue.size());
                rate.sleep();
            }
        }
        RCLCPP_INFO(this->get_logger(),"书库里的书只剩下%ld本，而你要%d本，不够了",novels_queue.size(),num);
        

        for (unsigned int i = 0; i < num;i++) {
            response->novel.push_back(novels_queue.front());
            novels_queue.pop();
        }
    }
public:
    SingleDogNode(std::string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(),"大家好，我是%s",name.c_str());
        sub_novel = this->create_subscription<std_msgs::msg::String>("sexy_girl",10,std::bind(&SingleDogNode::novel_callback,this,_1));
        pub_money = this->create_publisher<std_msgs::msg::UInt32>("sexy_girl_money",10);
        //声明并创建服务端，同时自定义了回调函数组
        sell_novels_callback_group = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        sell_server = this->create_service<village_interfaces::srv::SellNovel>("sell_novel",std::bind(&SingleDogNode::sell_novel_callback,this,_1,_2),rmw_qos_profile_services_default,sell_novels_callback_group);
    }
};

int main(int argc,char **argv)
{
    /*
    创建话题订阅者的一般流程：
    1.导入订阅的话题接口
    2.创建订阅回调函数
    3.编写订阅回调处理逻辑
    */
    rclcpp::init(argc,argv);
    auto node = std::make_shared<SingleDogNode>("wang2"); 
    
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
}