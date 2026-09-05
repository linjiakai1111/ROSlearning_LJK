// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from community_interfaces:srv/Complain.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__STRUCT_H_
#define COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sound'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Complain in the package community_interfaces.
typedef struct community_interfaces__srv__Complain_Request
{
  rosidl_runtime_c__String sound;
  uint8_t db;
  uint16_t duration_min;
} community_interfaces__srv__Complain_Request;

// Struct for a sequence of community_interfaces__srv__Complain_Request.
typedef struct community_interfaces__srv__Complain_Request__Sequence
{
  community_interfaces__srv__Complain_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} community_interfaces__srv__Complain_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Complain in the package community_interfaces.
typedef struct community_interfaces__srv__Complain_Response
{
  bool success;
  rosidl_runtime_c__String feedback;
  uint16_t expired_data;
  uint16_t money;
} community_interfaces__srv__Complain_Response;

// Struct for a sequence of community_interfaces__srv__Complain_Response.
typedef struct community_interfaces__srv__Complain_Response__Sequence
{
  community_interfaces__srv__Complain_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} community_interfaces__srv__Complain_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__STRUCT_H_
