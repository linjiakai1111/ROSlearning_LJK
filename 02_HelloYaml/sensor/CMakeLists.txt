cmake_minimum_required(VERSION 3.8)
project(sensor)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/PoseBag.msg"
  "msg/OriginPose.msg"
  DEPENDENCIES std_msgs
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(sensor_node src/sensor.cpp)
add_executable(brain_node src/brain.cpp)
add_executable(robot_node src/robot.cpp)

ament_target_dependencies(sensor_node rclcpp std_msgs)
ament_target_dependencies(brain_node rclcpp std_msgs)
ament_target_dependencies(robot_node rclcpp std_msgs)

target_link_libraries(sensor_node "${cpp_typesupport_target}")
target_link_libraries(brain_node "${cpp_typesupport_target}")
target_link_libraries(robot_node "${cpp_typesupport_target}")

install(TARGETS
  sensor_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  brain_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  robot_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
