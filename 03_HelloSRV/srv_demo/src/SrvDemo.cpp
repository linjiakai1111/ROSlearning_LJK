#include "rclcpp/rclcpp.hpp"
#include "srv_interface/srv/srv_msg.hpp"
#include "std_msgs/msg/u_int16.hpp"
#include "RandomNum.hpp"

using namespace std::placeholders;

class SrvDemoNode: public rclcpp::Node
{
  private:
    rclcpp::Service<srv_interface::srv::SrvMsg>::SharedPtr mng_server;
    RandomNum random_tool_;
    void index_callback(const srv_interface::srv::SrvMsg::Request::SharedPtr request,
                        const srv_interface::srv::SrvMsg::Response::SharedPtr response)
    {
      unsigned int index = request->index.data;
      std::string open_status = (random_tool_.RandomInt(0,10)+index)%2 ? "open":"close";
      response->is_open = (random_tool_.RandomInt(0,10)+index)%2 ? true : false;
      RCLCPP_INFO(this->get_logger(),"Got Index : %u ,and it is %s",index,open_status.c_str());
    }
  public:
    explicit SrvDemoNode(const std::string& name):rclcpp::Node(name)
    {
      mng_server=this->create_service<srv_interface::srv::SrvMsg>(
        "MatchIndex",
        std::bind(&SrvDemoNode::index_callback,this,_1,_2),
        rmw_qos_profile_services_default
        //这个地方可以加线程组
      );
      RCLCPP_INFO(this->get_logger(),"Service Node has opened");
    }
};

int main(int argc,char** argv)
{
  rclcpp::init(argc,argv);
  auto node = std::make_shared<SrvDemoNode>("srv_node");

  // rclcpp::executors::MultiThreadExecutor executor;
  // executor.add_node(node);
  // executor.spin();
  // executor::shutdown();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}