#include "rclcpp/rclcpp.hpp"
#include "RandomNum.hpp"
#include "srv_interface/srv/srv_msg.hpp"

using namespace std::placeholders;

class CltDemoNode: public rclcpp::Node
{
  public:
  explicit CltDemoNode(const std::string& name):rclcpp::Node(name)
  {
    ask_client_ = this->create_client<srv_interface::srv::SrvMsg>("MatchIndex");
    timer_=this->create_wall_timer(
      std::chrono::milliseconds(1000),
      std::bind(&CltDemoNode::send_request,this)
    );
    RCLCPP_INFO(this->get_logger(),"Client Node has opened");
  }
  private:
    rclcpp::Client<srv_interface::srv::SrvMsg>::SharedPtr ask_client_;
    rclcpp::TimerBase::SharedPtr timer_;
    RandomNum random_tool_;
    rclcpp::Time _start_;
    rclcpp::Time _end_;
    int randInt; 
    void send_request(){
      if(!ask_client_->wait_for_service(std::chrono::seconds(3)))
      {
        RCLCPP_INFO(this->get_logger(),"Service未响应，继续等待");
      }
      _start_ = this->get_clock()->now();
      randInt=random_tool_.RandomInt(0,100);
      auto request = std::make_shared<srv_interface::srv::SrvMsg::Request>();
      request->index.data = randInt;
      auto Temp = ask_client_->async_send_request(
        request,
        std::bind(&CltDemoNode::Clt_callback,this,_1)
      );
    }
    void Clt_callback(rclcpp::Client<srv_interface::srv::SrvMsg>::SharedFuture Future){
      try{
        std::string index_status = Future.get()->is_open ? "is open" : "is close";
        _end_ = this->get_clock()->now();
        RCLCPP_INFO(this->get_logger(),"Since Request formed,it has been %d nanosec for getting response,\n and map[%d] %s",
                    static_cast<int>((_end_.seconds()-_start_.seconds())*1e9),
                    randInt,
                    index_status.c_str());
      }catch(const std::exception &e){
        RCLCPP_INFO(this->get_logger(),"Failed to get response output , %s",e.what());
      }
    }
};
int main(int argc,char** argv){
  rclcpp::init(argc,argv);
  auto node = std::make_shared<CltDemoNode>("clt_node");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}