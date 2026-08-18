cmake_minimum_required(VERSION 3.8)
project(helloworld)

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
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# 易错点：两个源文件都要列出来，漏掉 main.cpp 会报 undefined reference to main
add_executable(helloworld src/helloworld.cpp main.cpp)
# 易错点：头文件在 include/ 下，必须告诉编译器搜索路径，否则 include 找不到
target_include_directories(helloworld PRIVATE include)
ament_target_dependencies(helloworld rclcpp std_msgs)

install(
  TARGETS helloworld
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()