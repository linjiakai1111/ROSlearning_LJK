// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice

#ifndef CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__TRAITS_HPP_
#define CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "camera/msg/detail/robot_pose_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
#include "std_msgs/msg/detail/float32__traits.hpp"
// Member 'angles'
#include "std_msgs/msg/detail/float32_multi_array__traits.hpp"

namespace camera
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotPoseMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    to_flow_style_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    to_flow_style_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    to_flow_style_yaml(msg.z, out);
    out << ", ";
  }

  // member: angles
  {
    out << "angles: ";
    to_flow_style_yaml(msg.angles, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotPoseMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x:\n";
    to_block_style_yaml(msg.x, out, indentation + 2);
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y:\n";
    to_block_style_yaml(msg.y, out, indentation + 2);
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z:\n";
    to_block_style_yaml(msg.z, out, indentation + 2);
  }

  // member: angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angles:\n";
    to_block_style_yaml(msg.angles, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotPoseMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace camera

namespace rosidl_generator_traits
{

[[deprecated("use camera::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const camera::msg::RobotPoseMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  camera::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use camera::msg::to_yaml() instead")]]
inline std::string to_yaml(const camera::msg::RobotPoseMsg & msg)
{
  return camera::msg::to_yaml(msg);
}

template<>
inline const char * data_type<camera::msg::RobotPoseMsg>()
{
  return "camera::msg::RobotPoseMsg";
}

template<>
inline const char * name<camera::msg::RobotPoseMsg>()
{
  return "camera/msg/RobotPoseMsg";
}

template<>
struct has_fixed_size<camera::msg::RobotPoseMsg>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float32>::value && has_fixed_size<std_msgs::msg::Float32MultiArray>::value> {};

template<>
struct has_bounded_size<camera::msg::RobotPoseMsg>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float32>::value && has_bounded_size<std_msgs::msg::Float32MultiArray>::value> {};

template<>
struct is_message<camera::msg::RobotPoseMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__TRAITS_HPP_
