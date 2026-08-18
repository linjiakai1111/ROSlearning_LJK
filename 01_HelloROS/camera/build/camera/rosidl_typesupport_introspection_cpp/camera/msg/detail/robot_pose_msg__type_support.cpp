// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "camera/msg/detail/robot_pose_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace camera
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotPoseMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) camera::msg::RobotPoseMsg(_init);
}

void RobotPoseMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<camera::msg::RobotPoseMsg *>(message_memory);
  typed_message->~RobotPoseMsg();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotPoseMsg_message_member_array[4] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Float32>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera::msg::RobotPoseMsg, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Float32>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera::msg::RobotPoseMsg, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Float32>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera::msg::RobotPoseMsg, z),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "angles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Float32MultiArray>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera::msg::RobotPoseMsg, angles),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotPoseMsg_message_members = {
  "camera::msg",  // message namespace
  "RobotPoseMsg",  // message name
  4,  // number of fields
  sizeof(camera::msg::RobotPoseMsg),
  RobotPoseMsg_message_member_array,  // message members
  RobotPoseMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotPoseMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotPoseMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotPoseMsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace camera


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<camera::msg::RobotPoseMsg>()
{
  return &::camera::msg::rosidl_typesupport_introspection_cpp::RobotPoseMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, camera, msg, RobotPoseMsg)() {
  return &::camera::msg::rosidl_typesupport_introspection_cpp::RobotPoseMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
