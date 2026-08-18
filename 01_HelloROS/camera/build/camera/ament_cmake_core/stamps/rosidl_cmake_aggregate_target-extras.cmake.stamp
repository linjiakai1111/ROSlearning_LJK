# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target camera::camera
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${camera_TARGETS}.
if(camera_TARGETS AND NOT TARGET camera::camera)
  add_library(camera::camera INTERFACE IMPORTED)
  set_target_properties(camera::camera PROPERTIES
    INTERFACE_LINK_LIBRARIES "${camera_TARGETS}")
endif()
