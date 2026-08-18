from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  camera_node=Node(
    package = "camera",
    executable="camera_node"
    )
  machine_node=Node(
    package = "camera",
    executable="machine_node"
  )
  launch_d= LaunchDescription([camera_node,machine_node])
  return launch_d