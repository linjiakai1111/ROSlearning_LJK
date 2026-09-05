// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice
#include "community_interfaces/msg/detail/noise_element__rosidl_typesupport_fastrtps_cpp.hpp"
#include "community_interfaces/msg/detail/noise_element__struct.hpp"

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

namespace community_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_community_interfaces
cdr_serialize(
  const community_interfaces::msg::NoiseElement & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sound
  cdr << ros_message.sound;
  // Member: db
  cdr << ros_message.db;
  // Member: duration_sec
  cdr << ros_message.duration_sec;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_community_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  community_interfaces::msg::NoiseElement & ros_message)
{
  // Member: sound
  cdr >> ros_message.sound;

  // Member: db
  cdr >> ros_message.db;

  // Member: duration_sec
  cdr >> ros_message.duration_sec;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_community_interfaces
get_serialized_size(
  const community_interfaces::msg::NoiseElement & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sound
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.sound.size() + 1);
  // Member: db
  {
    size_t item_size = sizeof(ros_message.db);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: duration_sec
  {
    size_t item_size = sizeof(ros_message.duration_sec);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_community_interfaces
max_serialized_size_NoiseElement(
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


  // Member: sound
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: db
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: duration_sec
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = community_interfaces::msg::NoiseElement;
    is_plain =
      (
      offsetof(DataType, duration_sec) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _NoiseElement__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const community_interfaces::msg::NoiseElement *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NoiseElement__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<community_interfaces::msg::NoiseElement *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NoiseElement__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const community_interfaces::msg::NoiseElement *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NoiseElement__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_NoiseElement(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _NoiseElement__callbacks = {
  "community_interfaces::msg",
  "NoiseElement",
  _NoiseElement__cdr_serialize,
  _NoiseElement__cdr_deserialize,
  _NoiseElement__get_serialized_size,
  _NoiseElement__max_serialized_size
};

static rosidl_message_type_support_t _NoiseElement__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NoiseElement__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace community_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_community_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<community_interfaces::msg::NoiseElement>()
{
  return &community_interfaces::msg::typesupport_fastrtps_cpp::_NoiseElement__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, community_interfaces, msg, NoiseElement)() {
  return &community_interfaces::msg::typesupport_fastrtps_cpp::_NoiseElement__handle;
}

#ifdef __cplusplus
}
#endif
