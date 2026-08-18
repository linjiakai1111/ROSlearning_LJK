from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  sensor_node=Node(
    package="sensor",
    executable="sensor_node",
    name="sensor_node",
    output="screen",
    parameters=[
      "sensor/config/pose_params.yaml"
    ]
  )
  brain_node=Node(
    package="sensor",
    executable="brain_node",
    output="screen",
  )
  launch_d=LaunchDescription([sensor_node,brain_node])
  return launch_d