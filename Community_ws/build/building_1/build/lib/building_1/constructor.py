import rclpy
from rclpy.node import Node
import os
from community_interfaces.msg import NoiseElement
from community_interfaces.srv import Command
from community_interfaces.srv import Rent
import random

class WriteNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("I'm going to conduct construction")
        self.timer_period = 3
        self.Pub_Buzzer=self.create_publisher(NoiseElement, "Buzzer", 10)
        self.timer=self.create_timer(self.timer_period,self.buzzer_callback)
        self.get_command=self.create_service(Command,"Commanding",self.command_callback)
        self.get_asking=self.create_service(Rent,"family_rental",self.family_callback)
        self.ask_salary=self.create_client(Rent,"salary")
        self.account=31
        self.earning=0
        self.ask_media_salary=0
    def buzzer_callback(self):
        buzzer=NoiseElement()
        buzzer.sound="hummm~hummm"
        buzzer.db=90
        buzzer.duration_sec=3
        self.Pub_Buzzer.publish(buzzer)
        self.get_logger().info(f"Echo {buzzer.sound} in {buzzer.db} dB for {buzzer.duration_sec}s")
        ###在这里索取salary后再打印日志###
        self.ask_for_salary()
        ###在这里索取salary后再打印日志###
        # 注意：account 的更新已移到 salary_callback 异步回调中
        # 这里 self.earning 可能还没被更新（异步），仅作参考显示
        self.get_logger().info(f"Ask for {self.ask_media_salary} pennies,now the account has {self.account} pennies")
    def command_callback(self,request,response):
        self.get_logger().info(f'The fucking management ask me \"{request.command}\"')
        if self.account>100:
            response.success=True
            self.get_logger().info(f'Have earn {self.account},quit')
        else:
            response.success=False
            self.get_logger().info(f'Still miss {100-self.account} pennies,continue')
        return response
    def family_callback(self,request,response):
        if request.ask_money>self.account:
            self.get_logger().info(f"I just have {self.account} pennies")
            response.pay_money=self.account
            self.account=0
        else:
            self.get_logger().info("I have enough money to pay for rental")
            self.account-=request.ask_money
            response.pay_money=request.ask_money
        return response
    def ask_for_salary(self):
        request=Rent.Request()
        self.ask_media_salary=random.randint(95,105)
        request.ask_money=self.ask_media_salary
        # 注意：add_done_callback 会传入 Future 对象，所以用 salary_callback 来接收
        self.ask_salary.call_async(request).add_done_callback(self.salary_callback)
    def salary_callback(self,future):
        result=future.result()  # future.result() 返回服务响应
        self.earning=result.pay_money
        self.account+=self.earning
        if result.pay_money==self.ask_media_salary:
            self.get_logger().info("This is what I deserve")
        else:
            self.get_logger().warning("The fucking management didn't pay enough money!")


def main(args=None):
    print("debug running file is %s"%os.path.abspath(__file__))
    rclpy.init(args=args)
    constructor_node=WriteNode("constructor")
    rclpy.spin(constructor_node)
    rclpy.shutdown()