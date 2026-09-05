cmake_minimum_required(VERSION 3.8)
project(village_wang)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)  # <--- 必须加这一行
find_package(village_interfaces REQUIRED)

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

ament_package()
# 这种写法会自动寻找 src 目录下的所有 .cpp 文件，防止路径写错
add_executable(wang2_node src/wang2.cpp) 
# 或者如果你不确定路径，可以先试着只写文件名（虽然不推荐，但在简单结构下有效）：
# add_executable(wang2_node wang2.cpp) 

# 原来的样子
# ament_target_dependencies(wang2_node rclcpp)
# 修改后的样子
ament_target_dependencies(wang2_node rclcpp std_msgs village_interfaces) # <--- 把 std_msgs 加进去
install(TARGETS
  wang2_node
  DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
  )