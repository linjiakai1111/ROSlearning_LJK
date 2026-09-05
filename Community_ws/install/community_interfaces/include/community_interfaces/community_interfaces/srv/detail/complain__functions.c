// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from community_interfaces:srv/Complain.idl
// generated code does not contain a copyright notice
#include "community_interfaces/srv/detail/complain__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `sound`
#include "rosidl_runtime_c/string_functions.h"

bool
community_interfaces__srv__Complain_Request__init(community_interfaces__srv__Complain_Request * msg)
{
  if (!msg) {
    return false;
  }
  // sound
  if (!rosidl_runtime_c__String__init(&msg->sound)) {
    community_interfaces__srv__Complain_Request__fini(msg);
    return false;
  }
  // db
  // duration_min
  return true;
}

void
community_interfaces__srv__Complain_Request__fini(community_interfaces__srv__Complain_Request * msg)
{
  if (!msg) {
    return;
  }
  // sound
  rosidl_runtime_c__String__fini(&msg->sound);
  // db
  // duration_min
}

bool
community_interfaces__srv__Complain_Request__are_equal(const community_interfaces__srv__Complain_Request * lhs, const community_interfaces__srv__Complain_Request * rhs)
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
  // duration_min
  if (lhs->duration_min != rhs->duration_min) {
    return false;
  }
  return true;
}

bool
community_interfaces__srv__Complain_Request__copy(
  const community_interfaces__srv__Complain_Request * input,
  community_interfaces__srv__Complain_Request * output)
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
  // duration_min
  output->duration_min = input->duration_min;
  return true;
}

community_interfaces__srv__Complain_Request *
community_interfaces__srv__Complain_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__srv__Complain_Request * msg = (community_interfaces__srv__Complain_Request *)allocator.allocate(sizeof(community_interfaces__srv__Complain_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(community_interfaces__srv__Complain_Request));
  bool success = community_interfaces__srv__Complain_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
community_interfaces__srv__Complain_Request__destroy(community_interfaces__srv__Complain_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    community_interfaces__srv__Complain_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
community_interfaces__srv__Complain_Request__Sequence__init(community_interfaces__srv__Complain_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__srv__Complain_Request * data = NULL;

  if (size) {
    data = (community_interfaces__srv__Complain_Request *)allocator.zero_allocate(size, sizeof(community_interfaces__srv__Complain_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = community_interfaces__srv__Complain_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        community_interfaces__srv__Complain_Request__fini(&data[i - 1]);
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
community_interfaces__srv__Complain_Request__Sequence__fini(community_interfaces__srv__Complain_Request__Sequence * array)
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
      community_interfaces__srv__Complain_Request__fini(&array->data[i]);
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

community_interfaces__srv__Complain_Request__Sequence *
community_interfaces__srv__Complain_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__srv__Complain_Request__Sequence * array = (community_interfaces__srv__Complain_Request__Sequence *)allocator.allocate(sizeof(community_interfaces__srv__Complain_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = community_interfaces__srv__Complain_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
community_interfaces__srv__Complain_Request__Sequence__destroy(community_interfaces__srv__Complain_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    community_interfaces__srv__Complain_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
community_interfaces__srv__Complain_Request__Sequence__are_equal(const community_interfaces__srv__Complain_Request__Sequence * lhs, const community_interfaces__srv__Complain_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!community_interfaces__srv__Complain_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
community_interfaces__srv__Complain_Request__Sequence__copy(
  const community_interfaces__srv__Complain_Request__Sequence * input,
  community_interfaces__srv__Complain_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(community_interfaces__srv__Complain_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    community_interfaces__srv__Complain_Request * data =
      (community_interfaces__srv__Complain_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!community_interfaces__srv__Complain_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          community_interfaces__srv__Complain_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!community_interfaces__srv__Complain_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `feedback`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
community_interfaces__srv__Complain_Response__init(community_interfaces__srv__Complain_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // feedback
  if (!rosidl_runtime_c__String__init(&msg->feedback)) {
    community_interfaces__srv__Complain_Response__fini(msg);
    return false;
  }
  // expired_data
  // money
  return true;
}

void
community_interfaces__srv__Complain_Response__fini(community_interfaces__srv__Complain_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // feedback
  rosidl_runtime_c__String__fini(&msg->feedback);
  // expired_data
  // money
}

bool
community_interfaces__srv__Complain_Response__are_equal(const community_interfaces__srv__Complain_Response * lhs, const community_interfaces__srv__Complain_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  // expired_data
  if (lhs->expired_data != rhs->expired_data) {
    return false;
  }
  // money
  if (lhs->money != rhs->money) {
    return false;
  }
  return true;
}

bool
community_interfaces__srv__Complain_Response__copy(
  const community_interfaces__srv__Complain_Response * input,
  community_interfaces__srv__Complain_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // feedback
  if (!rosidl_runtime_c__String__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  // expired_data
  output->expired_data = input->expired_data;
  // money
  output->money = input->money;
  return true;
}

community_interfaces__srv__Complain_Response *
community_interfaces__srv__Complain_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__srv__Complain_Response * msg = (community_interfaces__srv__Complain_Response *)allocator.allocate(sizeof(community_interfaces__srv__Complain_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(community_interfaces__srv__Complain_Response));
  bool success = community_interfaces__srv__Complain_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
community_interfaces__srv__Complain_Response__destroy(community_interfaces__srv__Complain_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    community_interfaces__srv__Complain_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
community_interfaces__srv__Complain_Response__Sequence__init(community_interfaces__srv__Complain_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__srv__Complain_Response * data = NULL;

  if (size) {
    data = (community_interfaces__srv__Complain_Response *)allocator.zero_allocate(size, sizeof(community_interfaces__srv__Complain_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = community_interfaces__srv__Complain_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        community_interfaces__srv__Complain_Response__fini(&data[i - 1]);
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
community_interfaces__srv__Complain_Response__Sequence__fini(community_interfaces__srv__Complain_Response__Sequence * array)
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
      community_interfaces__srv__Complain_Response__fini(&array->data[i]);
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

community_interfaces__srv__Complain_Response__Sequence *
community_interfaces__srv__Complain_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  community_interfaces__srv__Complain_Response__Sequence * array = (community_interfaces__srv__Complain_Response__Sequence *)allocator.allocate(sizeof(community_interfaces__srv__Complain_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = community_interfaces__srv__Complain_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
community_interfaces__srv__Complain_Response__Sequence__destroy(community_interfaces__srv__Complain_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    community_interfaces__srv__Complain_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
community_interfaces__srv__Complain_Response__Sequence__are_equal(const community_interfaces__srv__Complain_Response__Sequence * lhs, const community_interfaces__srv__Complain_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!community_interfaces__srv__Complain_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
community_interfaces__srv__Complain_Response__Sequence__copy(
  const community_interfaces__srv__Complain_Response__Sequence * input,
  community_interfaces__srv__Complain_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(community_interfaces__srv__Complain_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    community_interfaces__srv__Complain_Response * data =
      (community_interfaces__srv__Complain_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!community_interfaces__srv__Complain_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          community_interfaces__srv__Complain_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!community_interfaces__srv__Complain_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
