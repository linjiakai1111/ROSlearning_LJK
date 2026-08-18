// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice

#ifndef CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__STRUCT_H_
#define CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
#include "std_msgs/msg/detail/float32__struct.h"
// Member 'angles'
#include "std_msgs/msg/detail/float32_multi_array__struct.h"

/// Struct defined in msg/RobotPoseMsg in the package camera.
typedef struct camera__msg__RobotPoseMsg
{
  /// 坐标x
  std_msgs__msg__Float32 x;
  /// 坐标y
  std_msgs__msg__Float32 y;
  /// 坐标z
  std_msgs__msg__Float32 z;
  /// roll,pitch,yaw
  std_msgs__msg__Float32MultiArray angles;
} camera__msg__RobotPoseMsg;

// Struct for a sequence of camera__msg__RobotPoseMsg.
typedef struct camera__msg__RobotPoseMsg__Sequence
{
  camera__msg__RobotPoseMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} camera__msg__RobotPoseMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__STRUCT_H_
