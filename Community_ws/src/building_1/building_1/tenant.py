import rclpy
from rclpy.node import Node
import os
from community_interfaces.srv import Rent

class WriteNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.rental_server=self.create_service(Rent,"rental",self.rent_callback)
        self.family_client=self.create_client(Rent,"family_rental")
        self.family_timer=None
        self.pocket=256
        self.lack=0#从constructor那里要来的钱要同时考虑lack和pocket

    def rent_callback(self,request,response):
        if request.ask_money<=self.pocket:
            self.lack=0
            response.pay_money=request.ask_money
            self.pocket-=response.pay_money
            self.get_logger().info(f"I have paid {response.pay_money} pennies")
        else:
            response.pay_money=self.pocket
            self.lack=request.ask_money-self.pocket
            self.pocket=0
            self.get_logger().info(f"I don't have enough money,and then I'll ask my husband for money,I have pay {response.pay_money} pennies,still need {self.lack}")
            if self.family_timer is None or self.family_timer.is_canceled():
                self.family_timer=self.create_timer(3,self.family_ask_rental)
        return response

    def family_ask_rental(self):
        if self.lack<=0:
            self.family_timer.cancel()
            return  # 钱够了就不发了
        request=Rent.Request()
        request.ask_money=self.lack-self.pocket
        self.get_logger().info(f"Lack of {request.ask_money} pennies")
        self.family_client.call_async(request).add_done_callback(self.ask_rental_callback)

    def ask_rental_callback(self,response):
        result=response.result()  # Future 对象必须先 .result() 取值
        self.lack-=(result.pay_money-self.pocket)
        if self.lack>0:
            self.get_logger().info(f"*****Futile guy*****still need {self.lack} pennies")
        else:
            self.pocket-=self.lack
            self.get_logger().info(f"Pay over the rental!!!,the rest is {self.pocket}")
            

            
def main(args=None):
    print(f"Debug running file is {os.path.abspath(__file__)}")
    rclpy.init(args=args)
    tenant_node=WriteNode("tenant_node")
    rclpy.spin(tenant_node)
    rclpy.shutdown()