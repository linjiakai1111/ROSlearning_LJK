import rclpy
from rclpy.node import Node
from village_interfaces.srv import SellNovel

class Purchaser(Node):
    def __init__(self, name):
        super().__init__(name)
        self.buy_book_client = self.create_client(SellNovel, "sell_novel")
        self.pocket = 7
        # 每5秒尝试一次购买
        self.timer = self.create_timer(5.0, self.buy_to_read)

    def buy_to_read(self):
        if self.pocket <= 0:
            self.get_logger().info("穷鬼看不起书，停止尝试")
            # 停止定时器
            self.timer.cancel()
        else:
            self.get_logger().info("看到倾家荡产")

        self.get_logger().info(f"口袋里还有{self.pocket}元")
        if not self.buy_book_client.wait_for_service(timeout_sec=0.5):
            self.get_logger().info("卖书服务不可用，稍后重试")
            return

        request = SellNovel.Request()
        request.money = 1
        future = self.buy_book_client.call_async(request)
        future.add_done_callback(self.buyer_zhang)
        self.pocket -= request.money
        self.get_logger().info("已发起购买请求")
    def buyer_zhang(self, response):
        try:
            response = response.result()
            novels = response.novel
            if novels:
                self.get_logger().info(f"Yeah, 看到了书: {novels}")
            else:
                self.get_logger().info("请求已发送，但没有收到小说列表")
        except Exception as e:
            self.get_logger().error(f"调用卖书服务失败: {e}")


def main(args=None):
    rclpy.init(args=args)
    zhang3_node = Purchaser("zhang3")
    # 使用定时器周期性调用，无需手动调用一次
    rclpy.spin(zhang3_node)
    rclpy.shutdown()