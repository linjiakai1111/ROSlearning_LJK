// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from community_interfaces:srv/Complain.idl
// generated code does not contain a copyright notice
#include "community_interfaces/srv/detail/complain__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "community_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "community_interfaces/srv/detail/complain__struct.h"
#include "community_interfaces/srv/detail/complain__functions.h"
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


using _Complain_Request__ros_msg_type = community_interfaces__srv__Complain_Request;

static bool _Complain_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Complain_Request__ros_msg_type * ros_message = static_cast<const _Complain_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: duration_min
  {
    cdr << ros_message->duration_min;
  }

  return true;
}

static bool _Complain_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Complain_Request__ros_msg_type * ros_message = static_cast<_Complain_Request__ros_msg_type *>(untyped_ros_message);
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

  // Field name: duration_min
  {
    cdr >> ros_message->duration_min;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_community_interfaces
size_t get_serialized_size_community_interfaces__srv__Complain_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Complain_Request__ros_msg_type * ros_message = static_cast<const _Complain_Request__ros_msg_type *>(untyped_ros_message);
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
  // field.name duration_min
  {
    size_t item_size = sizeof(ros_message->duration_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Complain_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_community_interfaces__srv__Complain_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_community_interfaces
size_t max_serialized_size_community_interfaces__srv__Complain_Request(
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
  // member: duration_min
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
    using DataType = community_interfaces__srv__Complain_Request;
    is_plain =
      (
      offsetof(DataType, duration_min) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Complain_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_community_interfaces__srv__Complain_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Complain_Request = {
  "community_interfaces::srv",
  "Complain_Request",
  _Complain_Request__cdr_serialize,
  _Complain_Request__cdr_deserialize,
  _Complain_Request__get_serialized_size,
  _Complain_Request__max_serialized_size
};

static rosidl_message_type_support_t _Complain_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Complain_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, community_interfaces, srv, Complain_Request)() {
  return &_Complain_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "community_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "community_interfaces/srv/detail/complain__struct.h"
// already included above
// #include "community_interfaces/srv/detail/complain__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // feedback
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // feedback

// forward declare type support functions


using _Complain_Response__ros_msg_type = community_interfaces__srv__Complain_Response;

static bool _Complain_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Complain_Response__ros_msg_type * ros_message = static_cast<const _Complain_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: feedback
  {
    const rosidl_runtime_c__String * str = &ros_message->feedback;
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

  // Field name: expired_data
  {
    cdr << ros_message->expired_data;
  }

  // Field name: money
  {
    cdr << ros_message->money;
  }

  return true;
}

static bool _Complain_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Complain_Response__ros_msg_type * ros_message = static_cast<_Complain_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: feedback
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->feedback.data) {
      rosidl_runtime_c__String__init(&ros_message->feedback);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->feedback,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'feedback'\n");
      return false;
    }
  }

  // Field name: expired_data
  {
    cdr >> ros_message->expired_data;
  }

  // Field name: money
  {
    cdr >> ros_message->money;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_community_interfaces
size_t get_serialized_size_community_interfaces__srv__Complain_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Complain_Response__ros_msg_type * ros_message = static_cast<const _Complain_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name feedback
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->feedback.size + 1);
  // field.name expired_data
  {
    size_t item_size = sizeof(ros_message->expired_data);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name money
  {
    size_t item_size = sizeof(ros_message->money);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Complain_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_community_interfaces__srv__Complain_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_community_interfaces
size_t max_serialized_size_community_interfaces__srv__Complain_Response(
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

  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: feedback
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
  // member: expired_data
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: money
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
    using DataType = community_interfaces__srv__Complain_Response;
    is_plain =
      (
      offsetof(DataType, money) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Complain_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_community_interfaces__srv__Complain_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Complain_Response = {
  "community_interfaces::srv",
  "Complain_Response",
  _Complain_Response__cdr_serialize,
  _Complain_Response__cdr_deserialize,
  _Complain_Response__get_serialized_size,
  _Complain_Response__max_serialized_size
};

static rosidl_message_type_support_t _Complain_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Complain_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, community_interfaces, srv, Complain_Response)() {
  return &_Complain_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "community_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "community_interfaces/srv/complain.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Complain__callbacks = {
  "community_interfaces::srv",
  "Complain",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, community_interfaces, srv, Complain_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, community_interfaces, srv, Complain_Response)(),
};

static rosidl_service_type_support_t Complain__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Complain__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, community_interfaces, srv, Complain)() {
  return &Complain__handle;
}

#if defined(__cplusplus)
}
#endif
