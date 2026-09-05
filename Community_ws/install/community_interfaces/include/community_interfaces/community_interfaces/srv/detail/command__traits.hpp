// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from community_interfaces:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__COMMAND__TRAITS_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "community_interfaces/srv/detail/command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace community_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Command_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Command_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Command_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace community_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use community_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const community_interfaces::srv::Command_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::srv::Command_Request & msg)
{
  return community_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::srv::Command_Request>()
{
  return "community_interfaces::srv::Command_Request";
}

template<>
inline const char * name<community_interfaces::srv::Command_Request>()
{
  return "community_interfaces/srv/Command_Request";
}

template<>
struct has_fixed_size<community_interfaces::srv::Command_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<community_interfaces::srv::Command_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<community_interfaces::srv::Command_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace community_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Command_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Command_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Command_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace community_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use community_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const community_interfaces::srv::Command_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::srv::Command_Response & msg)
{
  return community_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::srv::Command_Response>()
{
  return "community_interfaces::srv::Command_Response";
}

template<>
inline const char * name<community_interfaces::srv::Command_Response>()
{
  return "community_interfaces/srv/Command_Response";
}

template<>
struct has_fixed_size<community_interfaces::srv::Command_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<community_interfaces::srv::Command_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<community_interfaces::srv::Command_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<community_interfaces::srv::Command>()
{
  return "community_interfaces::srv::Command";
}

template<>
inline const char * name<community_interfaces::srv::Command>()
{
  return "community_interfaces/srv/Command";
}

template<>
struct has_fixed_size<community_interfaces::srv::Command>
  : std::integral_constant<
    bool,
    has_fixed_size<community_interfaces::srv::Command_Request>::value &&
    has_fixed_size<community_interfaces::srv::Command_Response>::value
  >
{
};

template<>
struct has_bounded_size<community_interfaces::srv::Command>
  : std::integral_constant<
    bool,
    has_bounded_size<community_interfaces::srv::Command_Request>::value &&
    has_bounded_size<community_interfaces::srv::Command_Response>::value
  >
{
};

template<>
struct is_service<community_interfaces::srv::Command>
  : std::true_type
{
};

template<>
struct is_service_request<community_interfaces::srv::Command_Request>
  : std::true_type
{
};

template<>
struct is_service_response<community_interfaces::srv::Command_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__COMMAND__TRAITS_HPP_
