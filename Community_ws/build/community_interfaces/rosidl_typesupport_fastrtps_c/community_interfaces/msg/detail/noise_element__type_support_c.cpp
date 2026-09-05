// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice
#include "community_interfaces/msg/detail/noise_element__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "community_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "community_interfaces/msg/detail/noise_element__struct.h"
#include "community_interfaces/msg/detail/noise_element__functions.h"
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

#include "rosidl_runtime_c/string.h"  // sound
#include "rosidl_runtime_c/string_functions.h"  // sound

// forward declare type support functions


using _NoiseElement__ros_msg_type = community_interfaces__msg__NoiseElement;

static bool _NoiseElement__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NoiseElement__ros_msg_type * ros_message = static_cast<const _NoiseElement__ros_msg_type *>(untyped_ros_message);
  // Field name: sound
  {
    const rosidl_runtime_c__String * str = &ros_message->sound;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: db
  {
    cdr << ros_message->db;
  }

  // Field name: duration_sec
  {
    cdr << ros_message->duration_sec;
  }

  return true;
}

static bool _NoiseElement__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NoiseElement__ros_msg_type * ros_message = static_cast<_NoiseElement__ros_msg_type *>(untyped_ros_message);
  // Field name: sound
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sound.data) {
      rosidl_runtime_c__String__init(&ros_message->sound);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sound,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sound'\n");
      return false;
    }
  }

  // Field name: db
  {
    cdr >> ros_message->db;
  }

  // Field name: duration_sec
  {
    cdr >> ros_message->duration_sec;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_community_interfaces
size_t get_serialized_size_community_interfaces__msg__NoiseElement(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NoiseElement__ros_msg_type * ros_message = static_cast<const _NoiseElement__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name sound
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sound.size + 1);
  // field.name db
  {
    size_t item_size = sizeof(ros_message->db);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name duration_sec
  {
    size_t item_size = sizeof(ros_message->duration_sec);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NoiseElement__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_community_interfaces__msg__NoiseElement(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_community_interfaces
size_t max_serialized_size_community_interfaces__msg__NoiseElement(
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

  // member: sound
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
  // member: db
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: duration_sec
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
    using DataType = community_interfaces__msg__NoiseElement;
    is_plain =
      (
      offsetof(DataType, duration_sec) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NoiseElement__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_community_interfaces__msg__NoiseElement(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NoiseElement = {
  "community_interfaces::msg",
  "NoiseElement",
  _NoiseElement__cdr_serialize,
  _NoiseElement__cdr_deserialize,
  _NoiseElement__get_serialized_size,
  _NoiseElement__max_serialized_size
};

static rosidl_message_type_support_t _NoiseElement__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NoiseElement,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, community_interfaces, msg, NoiseElement)() {
  return &_NoiseElement__type_support;
}

#if defined(__cplusplus)
}
#endif
