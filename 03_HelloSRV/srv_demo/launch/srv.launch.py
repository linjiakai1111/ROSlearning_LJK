from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  srv_demo_node=Node(
    package="srv_demo",
    executable="srv_demo_node",
    name="srv_demo_node",
    output="screen"
  )
  clt_demo_node=Node(
    package="srv_demo",
    executable="clt_demo_node",
    name="clt_demo_node",
    output="screen"
  )
  return LaunchDescription([
    srv_demo_node,
    clt_demo_node
  ])