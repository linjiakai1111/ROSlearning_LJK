import rclpy
from rclpy.node import Node
from community_interfaces.srv import Complain
from community_interfaces.srv import Command
from community_interfaces.srv import Rent
from std_msgs.msg import UInt16
import os

class WriteNode(Node):
    def __init__(self,name):
        super().__init__(name)
        #self.timer_period
        self.compalin_server=self.create_service(Complain,"Complaining",self.complain_callback)
        self.command_exert=self.create_client(Command,"Commanding")
        self.pub_salary=self.create_service(Rent,"salary",self.salary_callback)
        self.recv_recharge=self.create_subscription(UInt16,"recharge",self.recv_recharge_callback,10)
        #self.pub_command_result=self.create_publisher(bool,"command_result")
        self.res_account=231
        self.self_account=2000
        self.success=True
    def recv_recharge_callback(self,recharge):
        self.res_account+=recharge.data
        self.get_logger().info(f"Resident1 have recharge {recharge} pennies")
    def complain_callback(self,request,response):
        response.money=0
        if self.res_account>100:
            response.success=True
            response.feedback="We'll try our best to deal with it"
            self.get_logger().info("Server of people!")
            self.noise_command()
            if self.success:
                self.res_account-=50
                self.self_account+=50
            else:
                self.get_logger().info("He don't stop,sorry")
                response.success=False
                response.feedback="Sorry,we have no way"
        else:
            response.success=False
            response.feedback="Work for richer..."
            response.money=100-self.res_account
            response.expired_data=13
            self.get_logger().info("Work for richer...")
        return response
    def salary_callback(self,request,response):
        if request.ask_money<self.self_account:
            self.self_account-=request.ask_money
            response.pay_money=request.ask_money
            self.get_logger().warning(f"You deserve {response.pay_money} pennies")
        else:
            response.pay_money=self.self_account
            self.self_account=0
            self.get_logger().info(f"No money for salary!,Pay your salary {response.pay_money},which is our all property")
        return response
    def noise_command(self):
        request = Command.Request()
        request.command="Stop your noisy behaviour!"
        self.get_logger().info("Stop your noisy behaviour!")
        self.command_exert.call_async(request).add_done_callback(self.command_callback)
    def command_callback(self,response):
        result=response.result()
        self.success=result.success
        if result.success:
            self.get_logger().info("Management is over")
        else:
            self.get_logger().warning("You'll lose your job!Undelicate,unpresented,unprevileged worker!")

def main(args=None):
    print(f"Debug running file is {os.path.abspath(__file__)}")
    rclpy.init(args=args)
    management_node=WriteNode("management")
    rclpy.spin(management_node)
    rclpy.shutdown()