// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__STRUCT_H_
#define COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__STRUCT_H_

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

/// Struct defined in msg/NoiseElement in the package community_interfaces.
/**
  * ROS2字段名要求必须全部是小写并且不能以下划线结尾和连续下划线,对于声明字段文件不能在文件名中加入下划线，且文件名开头需大写
 */
typedef struct community_interfaces__msg__NoiseElement
{
  rosidl_runtime_c__String sound;
  uint8_t db;
  uint16_t duration_sec;
} community_interfaces__msg__NoiseElement;

// Struct for a sequence of community_interfaces__msg__NoiseElement.
typedef struct community_interfaces__msg__NoiseElement__Sequence
{
  community_interfaces__msg__NoiseElement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} community_interfaces__msg__NoiseElement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__STRUCT_H_
