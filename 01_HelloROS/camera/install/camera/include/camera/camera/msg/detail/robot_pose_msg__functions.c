// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice
#include "camera/msg/detail/robot_pose_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
#include "std_msgs/msg/detail/float32__functions.h"
// Member `angles`
#include "std_msgs/msg/detail/float32_multi_array__functions.h"

bool
camera__msg__RobotPoseMsg__init(camera__msg__RobotPoseMsg * msg)
{
  if (!msg) {
    return false;
  }
  // x
  if (!std_msgs__msg__Float32__init(&msg->x)) {
    camera__msg__RobotPoseMsg__fini(msg);
    return false;
  }
  // y
  if (!std_msgs__msg__Float32__init(&msg->y)) {
    camera__msg__RobotPoseMsg__fini(msg);
    return false;
  }
  // z
  if (!std_msgs__msg__Float32__init(&msg->z)) {
    camera__msg__RobotPoseMsg__fini(msg);
    return false;
  }
  // angles
  if (!std_msgs__msg__Float32MultiArray__init(&msg->angles)) {
    camera__msg__RobotPoseMsg__fini(msg);
    return false;
  }
  return true;
}

void
camera__msg__RobotPoseMsg__fini(camera__msg__RobotPoseMsg * msg)
{
  if (!msg) {
    return;
  }
  // x
  std_msgs__msg__Float32__fini(&msg->x);
  // y
  std_msgs__msg__Float32__fini(&msg->y);
  // z
  std_msgs__msg__Float32__fini(&msg->z);
  // angles
  std_msgs__msg__Float32MultiArray__fini(&msg->angles);
}

bool
camera__msg__RobotPoseMsg__are_equal(const camera__msg__RobotPoseMsg * lhs, const camera__msg__RobotPoseMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (!std_msgs__msg__Float32__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!std_msgs__msg__Float32__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // z
  if (!std_msgs__msg__Float32__are_equal(
      &(lhs->z), &(rhs->z)))
  {
    return false;
  }
  // angles
  if (!std_msgs__msg__Float32MultiArray__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  return true;
}

bool
camera__msg__RobotPoseMsg__copy(
  const camera__msg__RobotPoseMsg * input,
  camera__msg__RobotPoseMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  if (!std_msgs__msg__Float32__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!std_msgs__msg__Float32__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // z
  if (!std_msgs__msg__Float32__copy(
      &(input->z), &(output->z)))
  {
    return false;
  }
  // angles
  if (!std_msgs__msg__Float32MultiArray__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  return true;
}

camera__msg__RobotPoseMsg *
camera__msg__RobotPoseMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera__msg__RobotPoseMsg * msg = (camera__msg__RobotPoseMsg *)allocator.allocate(sizeof(camera__msg__RobotPoseMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(camera__msg__RobotPoseMsg));
  bool success = camera__msg__RobotPoseMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
camera__msg__RobotPoseMsg__destroy(camera__msg__RobotPoseMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    camera__msg__RobotPoseMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
camera__msg__RobotPoseMsg__Sequence__init(camera__msg__RobotPoseMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera__msg__RobotPoseMsg * data = NULL;

  if (size) {
    data = (camera__msg__RobotPoseMsg *)allocator.zero_allocate(size, sizeof(camera__msg__RobotPoseMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = camera__msg__RobotPoseMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        camera__msg__RobotPoseMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
camera__msg__RobotPoseMsg__Sequence__fini(camera__msg__RobotPoseMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      camera__msg__RobotPoseMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

camera__msg__RobotPoseMsg__Sequence *
camera__msg__RobotPoseMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  camera__msg__RobotPoseMsg__Sequence * array = (camera__msg__RobotPoseMsg__Sequence *)allocator.allocate(sizeof(camera__msg__RobotPoseMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = camera__msg__RobotPoseMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
camera__msg__RobotPoseMsg__Sequence__destroy(camera__msg__RobotPoseMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    camera__msg__RobotPoseMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
camera__msg__RobotPoseMsg__Sequence__are_equal(const camera__msg__RobotPoseMsg__Sequence * lhs, const camera__msg__RobotPoseMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!camera__msg__RobotPoseMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
camera__msg__RobotPoseMsg__Sequence__copy(
  const camera__msg__RobotPoseMsg__Sequence * input,
  camera__msg__RobotPoseMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(camera__msg__RobotPoseMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    camera__msg__RobotPoseMsg * data =
      (camera__msg__RobotPoseMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!camera__msg__RobotPoseMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          camera__msg__RobotPoseMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!camera__msg__RobotPoseMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
