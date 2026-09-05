import rclpy
from rclpy.node import Node
from std_msgs.msg import String,UInt32
from village_interfaces.srv import BorrowMoney

class gratis_novel(Node):
    def __init__(self,name):
        super().__init__(name)
        self.timer_cycle = 3
        self.timer = self.create_timer(self.timer_cycle,self.money_offender)
        self.pirate = self.create_subscription(String,"sexy_girl",self.get_free_novel,10)
        self.offender = self.create_publisher(UInt32,"sexy_girl_money",10)
        self.borrow_client = self.create_client(BorrowMoney,"borrow_money")
    def money_offender(self):
        nodollar=UInt32()
        nodollar.data=0
        self.offender.publish(nodollar)
        self.get_logger().info("%s就爱白嫖，花了%d元"%(self.get_name(),nodollar.data))
        self.borrow_money_to_eat()
    def get_free_novel(self,chapter):
        self.get_logger().info("成功白嫖%s" % chapter.data)
    def borrow_money_to_eat(self,money=10):
        self.get_logger().info("借钱吃饭了，要借%d元" % money)
        #确认服务是否在线，若不在则跳出循环
        while not self.borrow_client.wait_for_service(1.0):
            self.get_logger().warn("还没借到钱，我再等等。。。")
        #构造请求内容
        request = BorrowMoney.Request()#Request对应的就是BorrowMoney里---对应的上部，使用文件名.Request()的方式声明
        request.name = self.get_name()
        request.money = money
        #发送异步借钱请求
        self.borrow_client.call_async(request).add_done_callback(self.borrow_response_callback)
        """
        解说一下:
        borrow_client是gratis_novel里面创建的客户实例，里面含有call_async这个可以接收request的函数
        在接受到request后调用call_async内的函数add_done_callback对自己创建的函数borrow_response_callback进行调用*
        """

    """
    编写客户端的一般步骤：
    1.导入服务接口
    2.创建请求结果接受函数
    3.声明并创建客户端
    4.编写结果接收逻辑
    5.调用客户端发送请求
    """
    def borrow_response_callback(self,response):
        result = response.result()#用result()从response中获取消息类型
        if result.success:
            self.get_logger().info("借到%d元钱了" % (result.money))
        else:
            self.get_logger().info("没借到，真抠门，缺%d元吃饭" % (10-result.money))

def main(args=None):
    rclpy.init(args=args)
    li3_node=gratis_novel("li3")
    rclpy.spin(li3_node)
    rclpy.shutdown()