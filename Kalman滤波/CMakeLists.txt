cmake_minimum_required(VERSION 3.16)
project(Kalman_Filter CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(Kalman_Filter Kalman_filter.cpp)

target_include_directories(Kalman_Filter BEFORE PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${Python3_NumPy_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Kalman_Filter PRIVATE
    ${OpenCV_LIBS}
    Python3::Python
)

target_compile_definitions(Kalman_Filter PRIVATE NPY_NO_DEPRECATED_API=NPY_1_7_API_VERSION)