// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__FUNCTIONS_H_
#define COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "community_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "community_interfaces/msg/detail/noise_element__struct.h"

/// Initialize msg/NoiseElement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * community_interfaces__msg__NoiseElement
 * )) before or use
 * community_interfaces__msg__NoiseElement__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
bool
community_interfaces__msg__NoiseElement__init(community_interfaces__msg__NoiseElement * msg);

/// Finalize msg/NoiseElement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
void
community_interfaces__msg__NoiseElement__fini(community_interfaces__msg__NoiseElement * msg);

/// Create msg/NoiseElement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * community_interfaces__msg__NoiseElement__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
community_interfaces__msg__NoiseElement *
community_interfaces__msg__NoiseElement__create();

/// Destroy msg/NoiseElement message.
/**
 * It calls
 * community_interfaces__msg__NoiseElement__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
void
community_interfaces__msg__NoiseElement__destroy(community_interfaces__msg__NoiseElement * msg);

/// Check for msg/NoiseElement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
bool
community_interfaces__msg__NoiseElement__are_equal(const community_interfaces__msg__NoiseElement * lhs, const community_interfaces__msg__NoiseElement * rhs);

/// Copy a msg/NoiseElement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
bool
community_interfaces__msg__NoiseElement__copy(
  const community_interfaces__msg__NoiseElement * input,
  community_interfaces__msg__NoiseElement * output);

/// Initialize array of msg/NoiseElement messages.
/**
 * It allocates the memory for the number of elements and calls
 * community_interfaces__msg__NoiseElement__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
bool
community_interfaces__msg__NoiseElement__Sequence__init(community_interfaces__msg__NoiseElement__Sequence * array, size_t size);

/// Finalize array of msg/NoiseElement messages.
/**
 * It calls
 * community_interfaces__msg__NoiseElement__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
void
community_interfaces__msg__NoiseElement__Sequence__fini(community_interfaces__msg__NoiseElement__Sequence * array);

/// Create array of msg/NoiseElement messages.
/**
 * It allocates the memory for the array and calls
 * community_interfaces__msg__NoiseElement__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
community_interfaces__msg__NoiseElement__Sequence *
community_interfaces__msg__NoiseElement__Sequence__create(size_t size);

/// Destroy array of msg/NoiseElement messages.
/**
 * It calls
 * community_interfaces__msg__NoiseElement__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
void
community_interfaces__msg__NoiseElement__Sequence__destroy(community_interfaces__msg__NoiseElement__Sequence * array);

/// Check for msg/NoiseElement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
bool
community_interfaces__msg__NoiseElement__Sequence__are_equal(const community_interfaces__msg__NoiseElement__Sequence * lhs, const community_interfaces__msg__NoiseElement__Sequence * rhs);

/// Copy an array of msg/NoiseElement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_community_interfaces
bool
community_interfaces__msg__NoiseElement__Sequence__copy(
  const community_interfaces__msg__NoiseElement__Sequence * input,
  community_interfaces__msg__NoiseElement__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__FUNCTIONS_H_
