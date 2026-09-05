# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target community_interfaces::community_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${community_interfaces_TARGETS}.
if(community_interfaces_TARGETS AND NOT TARGET community_interfaces::community_interfaces)
  add_library(community_interfaces::community_interfaces INTERFACE IMPORTED)
  set_target_properties(community_interfaces::community_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${community_interfaces_TARGETS}")
endif()
