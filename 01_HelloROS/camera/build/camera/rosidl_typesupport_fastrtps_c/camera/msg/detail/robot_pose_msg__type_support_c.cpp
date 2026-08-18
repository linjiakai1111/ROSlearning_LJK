// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice
#include "camera/msg/detail/robot_pose_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "camera/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "camera/msg/detail/robot_pose_msg__struct.h"
#include "camera/msg/detail/robot_pose_msg__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/float32__functions.h"  // x, y, z
#include "std_msgs/msg/detail/float32_multi_array__functions.h"  // angles

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_camera
size_t get_serialized_size_std_msgs__msg__Float32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_camera
size_t max_serialized_size_std_msgs__msg__Float32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_camera
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_camera
size_t get_serialized_size_std_msgs__msg__Float32MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_camera
size_t max_serialized_size_std_msgs__msg__Float32MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_camera
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32MultiArray)();


using _RobotPoseMsg__ros_msg_type = camera__msg__RobotPoseMsg;

static bool _RobotPoseMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotPoseMsg__ros_msg_type * ros_message = static_cast<const _RobotPoseMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->x, cdr))
    {
      return false;
    }
  }

  // Field name: y
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->y, cdr))
    {
      return false;
    }
  }

  // Field name: z
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->z, cdr))
    {
      return false;
    }
  }

  // Field name: angles
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32MultiArray
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->angles, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _RobotPoseMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotPoseMsg__ros_msg_type * ros_message = static_cast<_RobotPoseMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->x))
    {
      return false;
    }
  }

  // Field name: y
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->y))
    {
      return false;
    }
  }

  // Field name: z
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->z))
    {
      return false;
    }
  }

  // Field name: angles
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Float32MultiArray
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->angles))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera
size_t get_serialized_size_camera__msg__RobotPoseMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotPoseMsg__ros_msg_type * ros_message = static_cast<const _RobotPoseMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x

  current_alignment += get_serialized_size_std_msgs__msg__Float32(
    &(ros_message->x), current_alignment);
  // field.name y

  current_alignment += get_serialized_size_std_msgs__msg__Float32(
    &(ros_message->y), current_alignment);
  // field.name z

  current_alignment += get_serialized_size_std_msgs__msg__Float32(
    &(ros_message->z), current_alignment);
  // field.name angles

  current_alignment += get_serialized_size_std_msgs__msg__Float32MultiArray(
    &(ros_message->angles), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _RobotPoseMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_camera__msg__RobotPoseMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_camera
size_t max_serialized_size_camera__msg__RobotPoseMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: x
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: y
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: z
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: angles
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Float32MultiArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = camera__msg__RobotPoseMsg;
    is_plain =
      (
      offsetof(DataType, angles) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotPoseMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_camera__msg__RobotPoseMsg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotPoseMsg = {
  "camera::msg",
  "RobotPoseMsg",
  _RobotPoseMsg__cdr_serialize,
  _RobotPoseMsg__cdr_deserialize,
  _RobotPoseMsg__get_serialized_size,
  _RobotPoseMsg__max_serialized_size
};

static rosidl_message_type_support_t _RobotPoseMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotPoseMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, camera, msg, RobotPoseMsg)() {
  return &_RobotPoseMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
