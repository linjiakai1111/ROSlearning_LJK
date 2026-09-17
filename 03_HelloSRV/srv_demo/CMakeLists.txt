cmake_minimum_required(VERSION 3.8)
project(srv_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(srv_interface REQUIRED)

add_executable(
  srv_demo_node src/SrvDemo.cpp
)
add_executable(
  clt_demo_node src/CltDemo.cpp
)

ament_target_dependencies(
  srv_demo_node
  rclcpp
  std_msgs
  srv_interface
)

ament_target_dependencies(
  clt_demo_node
  rclcpp
  std_msgs
  srv_interface
)

target_include_directories(srv_demo_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(clt_demo_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

endif()
install(TARGETS
  srv_demo_node
  clt_demo_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)
#launch文件单独放在launch这个文件夹里，安装时需要DIRECTORY

ament_package()