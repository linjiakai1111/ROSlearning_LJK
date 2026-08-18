// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "camera/msg/detail/robot_pose_msg__rosidl_typesupport_introspection_c.h"
#include "camera/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "camera/msg/detail/robot_pose_msg__functions.h"
#include "camera/msg/detail/robot_pose_msg__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
#include "std_msgs/msg/float32.h"
// Member `x`
// Member `y`
// Member `z`
#include "std_msgs/msg/detail/float32__rosidl_typesupport_introspection_c.h"
// Member `angles`
#include "std_msgs/msg/float32_multi_array.h"
// Member `angles`
#include "std_msgs/msg/detail/float32_multi_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  camera__msg__RobotPoseMsg__init(message_memory);
}

void camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_fini_function(void * message_memory)
{
  camera__msg__RobotPoseMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_member_array[4] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera__msg__RobotPoseMsg, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera__msg__RobotPoseMsg, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera__msg__RobotPoseMsg, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(camera__msg__RobotPoseMsg, angles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_members = {
  "camera__msg",  // message namespace
  "RobotPoseMsg",  // message name
  4,  // number of fields
  sizeof(camera__msg__RobotPoseMsg),
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_member_array,  // message members
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_type_support_handle = {
  0,
  &camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_camera
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, camera, msg, RobotPoseMsg)() {
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32)();
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32)();
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32)();
  camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  if (!camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_type_support_handle.typesupport_identifier) {
    camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &camera__msg__RobotPoseMsg__rosidl_typesupport_introspection_c__RobotPoseMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
