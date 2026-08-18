// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice

#ifndef CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__BUILDER_HPP_
#define CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "camera/msg/detail/robot_pose_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace camera
{

namespace msg
{

namespace builder
{

class Init_RobotPoseMsg_angles
{
public:
  explicit Init_RobotPoseMsg_angles(::camera::msg::RobotPoseMsg & msg)
  : msg_(msg)
  {}
  ::camera::msg::RobotPoseMsg angles(::camera::msg::RobotPoseMsg::_angles_type arg)
  {
    msg_.angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::camera::msg::RobotPoseMsg msg_;
};

class Init_RobotPoseMsg_z
{
public:
  explicit Init_RobotPoseMsg_z(::camera::msg::RobotPoseMsg & msg)
  : msg_(msg)
  {}
  Init_RobotPoseMsg_angles z(::camera::msg::RobotPoseMsg::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_RobotPoseMsg_angles(msg_);
  }

private:
  ::camera::msg::RobotPoseMsg msg_;
};

class Init_RobotPoseMsg_y
{
public:
  explicit Init_RobotPoseMsg_y(::camera::msg::RobotPoseMsg & msg)
  : msg_(msg)
  {}
  Init_RobotPoseMsg_z y(::camera::msg::RobotPoseMsg::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotPoseMsg_z(msg_);
  }

private:
  ::camera::msg::RobotPoseMsg msg_;
};

class Init_RobotPoseMsg_x
{
public:
  Init_RobotPoseMsg_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotPoseMsg_y x(::camera::msg::RobotPoseMsg::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotPoseMsg_y(msg_);
  }

private:
  ::camera::msg::RobotPoseMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::camera::msg::RobotPoseMsg>()
{
  return camera::msg::builder::Init_RobotPoseMsg_x();
}

}  // namespace camera

#endif  // CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__BUILDER_HPP_
