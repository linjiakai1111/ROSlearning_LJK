// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "community_interfaces/msg/detail/noise_element__rosidl_typesupport_introspection_c.h"
#include "community_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "community_interfaces/msg/detail/noise_element__functions.h"
#include "community_interfaces/msg/detail/noise_element__struct.h"


// Include directives for member types
// Member `sound`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  community_interfaces__msg__NoiseElement__init(message_memory);
}

void community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_fini_function(void * message_memory)
{
  community_interfaces__msg__NoiseElement__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_member_array[3] = {
  {
    "sound",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(community_interfaces__msg__NoiseElement, sound),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "db",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(community_interfaces__msg__NoiseElement, db),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration_sec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(community_interfaces__msg__NoiseElement, duration_sec),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_members = {
  "community_interfaces__msg",  // message namespace
  "NoiseElement",  // message name
  3,  // number of fields
  sizeof(community_interfaces__msg__NoiseElement),
  community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_member_array,  // message members
  community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_init_function,  // function to initialize message memory (memory has to be allocated)
  community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_type_support_handle = {
  0,
  &community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_community_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, community_interfaces, msg, NoiseElement)() {
  if (!community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_type_support_handle.typesupport_identifier) {
    community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &community_interfaces__msg__NoiseElement__rosidl_typesupport_introspection_c__NoiseElement_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
