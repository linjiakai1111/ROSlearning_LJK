from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    node_1=Node(
        package="building_1",
        executable="constructor_node",
        name="constructor_node",
        output="screen"
    )

    node_2=Node(
        package="building_1",
        executable="resident1_node",
        name="resident1_node",
        output="screen"
    )

    node_3=Node(
        package="building_1",
        executable="management_node",
        name="management_node",
        output="screen"
    )

    node_4=Node(
        package="building_1",
        executable="tenant_node",
        name="tenant_node",
        output="screen"
    )

    return LaunchDescription([
        node_1,
        node_2,
        node_3,
        node_4
    ])