// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice
#include "camera/msg/detail/robot_pose_msg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "camera/msg/detail/robot_pose_msg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Float32 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Float32 &);
size_t get_serialized_size(
  const std_msgs::msg::Float32 &,
  size_t current_alignment);
size_t
max_serialized_size_Float32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

// functions for std_msgs::msg::Float32 already declared above

// functions for std_msgs::msg::Float32 already declared above

namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Float32MultiArray &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Float32MultiArray &);
size_t get_serialized_size(
  const std_msgs::msg::Float32MultiArray &,
  size_t current_alignment);
size_t
max_serialized_size_Float32MultiArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace camera
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera
cdr_serialize(
  const camera::msg::RobotPoseMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.x,
    cdr);
  // Member: y
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.y,
    cdr);
  // Member: z
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.z,
    cdr);
  // Member: angles
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.angles,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  camera::msg::RobotPoseMsg & ros_message)
{
  // Member: x
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.x);

  // Member: y
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.y);

  // Member: z
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.z);

  // Member: angles
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.angles);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera
get_serialized_size(
  const camera::msg::RobotPoseMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.x, current_alignment);
  // Member: y

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.y, current_alignment);
  // Member: z

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.z, current_alignment);
  // Member: angles

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.angles, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_camera
max_serialized_size_RobotPoseMsg(
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


  // Member: x
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: y
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: z
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: angles
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Float32MultiArray(
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
    using DataType = camera::msg::RobotPoseMsg;
    is_plain =
      (
      offsetof(DataType, angles) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotPoseMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const camera::msg::RobotPoseMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotPoseMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<camera::msg::RobotPoseMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotPoseMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const camera::msg::RobotPoseMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotPoseMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotPoseMsg(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotPoseMsg__callbacks = {
  "camera::msg",
  "RobotPoseMsg",
  _RobotPoseMsg__cdr_serialize,
  _RobotPoseMsg__cdr_deserialize,
  _RobotPoseMsg__get_serialized_size,
  _RobotPoseMsg__max_serialized_size
};

static rosidl_message_type_support_t _RobotPoseMsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotPoseMsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace camera

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_camera
const rosidl_message_type_support_t *
get_message_type_support_handle<camera::msg::RobotPoseMsg>()
{
  return &camera::msg::typesupport_fastrtps_cpp::_RobotPoseMsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, camera, msg, RobotPoseMsg)() {
  return &camera::msg::typesupport_fastrtps_cpp::_RobotPoseMsg__handle;
}

#ifdef __cplusplus
}
#endif
