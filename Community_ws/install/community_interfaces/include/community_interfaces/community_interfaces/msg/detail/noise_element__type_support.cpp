// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "community_interfaces/msg/detail/noise_element__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace community_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void NoiseElement_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) community_interfaces::msg::NoiseElement(_init);
}

void NoiseElement_fini_function(void * message_memory)
{
  auto typed_message = static_cast<community_interfaces::msg::NoiseElement *>(message_memory);
  typed_message->~NoiseElement();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NoiseElement_message_member_array[3] = {
  {
    "sound",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(community_interfaces::msg::NoiseElement, sound),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "db",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(community_interfaces::msg::NoiseElement, db),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "duration_sec",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(community_interfaces::msg::NoiseElement, duration_sec),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NoiseElement_message_members = {
  "community_interfaces::msg",  // message namespace
  "NoiseElement",  // message name
  3,  // number of fields
  sizeof(community_interfaces::msg::NoiseElement),
  NoiseElement_message_member_array,  // message members
  NoiseElement_init_function,  // function to initialize message memory (memory has to be allocated)
  NoiseElement_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NoiseElement_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NoiseElement_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace community_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<community_interfaces::msg::NoiseElement>()
{
  return &::community_interfaces::msg::rosidl_typesupport_introspection_cpp::NoiseElement_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, community_interfaces, msg, NoiseElement)() {
  return &::community_interfaces::msg::rosidl_typesupport_introspection_cpp::NoiseElement_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
