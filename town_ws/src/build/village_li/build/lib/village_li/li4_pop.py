import rclpy
import os
from rclpy.node import Node
def main(args=None):
    print("debugg:running file is:",os.path.abspath(__file__))
    rclpy.init(args=args)
    li4_node=Node("li4")
    li4_node.get_logger().info("Hello,I am Dr.li4")
    rclpy.spin(li4_node)
    rclpy.shutdown()