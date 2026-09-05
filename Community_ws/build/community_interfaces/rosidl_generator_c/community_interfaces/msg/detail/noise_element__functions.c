// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice
#include "community_interfaces/msg/detail/noise_element__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sound`
#include "rosidl_runtime_c/string_functions.h"

bool
community_interfaces__msg__NoiseElement__init(community_interfaces__msg__NoiseElement * msg)
{
  if (!msg) {
    return false;
  }
  // sound
  if (!rosidl_runtime_c__String__init(&msg->sound)) {
    community_interfaces__msg__NoiseElement__fini(msg);
    return false;
  }
  // db
  // duration_sec
  return true;
}

void
community_interfaces__msg__NoiseElement__fini(community_interfaces__msg__NoiseElement * msg)
{
  if (!msg) {
    return;
  }
  // sound
  rosidl_runtime_c__String__fini(&msg->sound);
  // db
  // duration_sec
}

bool
community_interfaces__msg__NoiseElement__are_equal(const community_interfaces__msg__NoiseElement * lhs, const community_interfaces__msg__NoiseElement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sound
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sound), &(rhs->sound)))
  {
    return false;
  }
  // db
  if (lhs->db != rhs->db) {
    return false;
  }
  // duration_sec
  if (lhs->duration_sec != rhs->duration_sec) {
    return false;
  }
  return true;
}

bool
community_interfaces__msg__NoiseElement__copy(
  const community_interfaces__msg__NoiseElement * input,
  community_interfaces__msg__NoiseElement * output)
{
  if (!input || !output) {
    return false;
  }
  // sound
  if (!rosidl_runtime_c__String__copy(
      &(input->sound), &(output->sound)))
  {
    return false;
  }
  // db
  output->db = input->db;
  // duration_sec
  output->duration_sec = input->duration_sec;
  return true;
}

community_interfaces__msg__NoiseElement *
community_interfaces__msg__NoiseElement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__msg__NoiseElement * msg = (community_interfaces__msg__NoiseElement *)allocator.allocate(sizeof(community_interfaces__msg__NoiseElement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(community_interfaces__msg__NoiseElement));
  bool success = community_interfaces__msg__NoiseElement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
community_interfaces__msg__NoiseElement__destroy(community_interfaces__msg__NoiseElement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    community_interfaces__msg__NoiseElement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
community_interfaces__msg__NoiseElement__Sequence__init(community_interfaces__msg__NoiseElement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__msg__NoiseElement * data = NULL;

  if (size) {
    data = (community_interfaces__msg__NoiseElement *)allocator.zero_allocate(size, sizeof(community_interfaces__msg__NoiseElement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = community_interfaces__msg__NoiseElement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        community_interfaces__msg__NoiseElement__fini(&data[i - 1]);
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
community_interfaces__msg__NoiseElement__Sequence__fini(community_interfaces__msg__NoiseElement__Sequence * array)
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
      community_interfaces__msg__NoiseElement__fini(&array->data[i]);
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

community_interfaces__msg__NoiseElement__Sequence *
community_interfaces__msg__NoiseElement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__msg__NoiseElement__Sequence * array = (community_interfaces__msg__NoiseElement__Sequence *)allocator.allocate(sizeof(community_interfaces__msg__NoiseElement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = community_interfaces__msg__NoiseElement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
community_interfaces__msg__NoiseElement__Sequence__destroy(community_interfaces__msg__NoiseElement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    community_interfaces__msg__NoiseElement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
community_interfaces__msg__NoiseElement__Sequence__are_equal(const community_interfaces__msg__NoiseElement__Sequence * lhs, const community_interfaces__msg__NoiseElement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!community_interfaces__msg__NoiseElement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
community_interfaces__msg__NoiseElement__Sequence__copy(
  const community_interfaces__msg__NoiseElement__Sequence * input,
  community_interfaces__msg__NoiseElement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(community_interfaces__msg__NoiseElement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    community_interfaces__msg__NoiseElement * data =
      (community_interfaces__msg__NoiseElement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!community_interfaces__msg__NoiseElement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          community_interfaces__msg__NoiseElement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!community_interfaces__msg__NoiseElement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
