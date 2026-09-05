# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target village_interfaces::village_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${village_interfaces_TARGETS}.
if(village_interfaces_TARGETS AND NOT TARGET village_interfaces::village_interfaces)
  add_library(village_interfaces::village_interfaces INTERFACE IMPORTED)
  set_target_properties(village_interfaces::village_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${village_interfaces_TARGETS}")
endif()
