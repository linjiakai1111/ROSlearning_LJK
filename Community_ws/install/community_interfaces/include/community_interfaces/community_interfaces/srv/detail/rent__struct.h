// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from community_interfaces:srv/Rent.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__RENT__STRUCT_H_
#define COMMUNITY_INTERFACES__SRV__DETAIL__RENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Rent in the package community_interfaces.
typedef struct community_interfaces__srv__Rent_Request
{
  uint16_t ask_money;
} community_interfaces__srv__Rent_Request;

// Struct for a sequence of community_interfaces__srv__Rent_Request.
typedef struct community_interfaces__srv__Rent_Request__Sequence
{
  community_interfaces__srv__Rent_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} community_interfaces__srv__Rent_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Rent in the package community_interfaces.
typedef struct community_interfaces__srv__Rent_Response
{
  uint16_t pay_money;
} community_interfaces__srv__Rent_Response;

// Struct for a sequence of community_interfaces__srv__Rent_Response.
typedef struct community_interfaces__srv__Rent_Response__Sequence
{
  community_interfaces__srv__Rent_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} community_interfaces__srv__Rent_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__RENT__STRUCT_H_
