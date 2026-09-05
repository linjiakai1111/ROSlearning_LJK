import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import os
from std_msgs.msg import UInt16
from community_interfaces.msg import NoiseElement
from community_interfaces.srv import Complain
from community_interfaces.srv import Rent

class WriteNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.sub_buzzer=self.create_subscription(NoiseElement,"Buzzer",self.recv_buzzer_callback,10)
        self.recharge_res_account=self.create_publisher(UInt16,"recharge",10)
        self.count=0
        self.sound=""
        self.db=0
        self.duration_sec=0
        self.lack_money=0
        self.complain_buzzer=self.create_client(Complain,"Complaining")
        self.ask_rental=self.create_client(Rent,"rental")
        self.rental_timer=None
    def recv_buzzer_callback(self,buzzer):
        self.count+=1
        self.duration_sec+=buzzer.duration_sec
        self.db=buzzer.db
        self.sound=buzzer.sound
        if self.count<=5:
            self.get_logger().info(f"Having been disturbed for {self.count} times,Don't make the fucking noise anymore!!!")
        if self.count>5:
            self.get_logger().info(f"If there is any {buzzer.sound[0:3]} ,I would complain to estate management")
            self.complain_for_management()

    def pub_recharge(self):
        recharge=UInt16()
        recharge.data=-self.lack_money
        self.recharger_res_account(recharge)
        self.get_logger().info(f"Have recharge {-self.lack_money}")
        
    def ask_for_rental(self):
        if self.lack_money<=0:
            if self.rental_timer is not None:
                self.rental_timer.cancel()
            return  # 钱够了，不发请求
        request=Rent.Request()
        request.ask_money=self.lack_money
        self.ask_rental.call_async(request).add_done_callback(self.Rental_callback)
    def complain_for_management(self):
        self.get_logger().info("Fulfill your job obligations of managing the fucking noise!")
        while not self.complain_buzzer.wait_for_service(10):
            self.get_logger().error("Service not available, complaint failed!")
        request=Complain.Request()
        request.sound=self.sound
        request.db=self.db
        request.duration_min=int(self.duration_sec/60.0)  # uint16 必须传整数，用 int() 截断
        self.complain_buzzer.call_async(request).add_done_callback(self.Complain_Feedback)
    def Complain_Feedback(self,response):
        result=response.result()
        if result.success:
            self.get_logger().info("They would cope with it")
            self.get_logger().info(f"They said \"{result.feedback}\"")
        elif result.success==False:
            if result.money!=0:
                self.get_logger().info("They have ignored it")
                self.get_logger().info(f"They said \"You have expired for {result.expired_data},and the amount due is {result.money} dollars\"")
                self.lack_money+=result.money
                if self.lack_money>0:
                    self.rental_timer=self.create_timer(2,self.ask_for_rental)
                self.ask_for_rental()
            if result.money==0:
                self.get_logger().info("Useless guy!!")

    def Rental_callback(self,response):
        result=response.result()
        if result.pay_money<=self.lack_money:
            self.get_logger().info(f"Didn't get enough money from the poor,still need {self.lack_money-result.pay_money}")
        else:
            self.get_logger().info("The constructor will pay for his noise!")
            self.pub_recharge()#*********这一步在lack_money清零后得把钱返回给management**********
        self.lack_money-=result.pay_money

def main(args=None):
    print(f"Debug running file is {os.path.abspath(__file__)}")
    rclpy.init(args=args)
    resident1_node=WriteNode("resident1")
    rclpy.spin(resident1_node)
    rclpy.shutdown()
