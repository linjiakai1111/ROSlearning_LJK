// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from community_interfaces:srv/Rent.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__RENT__TRAITS_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__RENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "community_interfaces/srv/detail/rent__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace community_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Rent_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: ask_money
  {
    out << "ask_money: ";
    rosidl_generator_traits::value_to_yaml(msg.ask_money, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Rent_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ask_money
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ask_money: ";
    rosidl_generator_traits::value_to_yaml(msg.ask_money, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Rent_Request & msg, bool use_flow_style = false)
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
  const community_interfaces::srv::Rent_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::srv::Rent_Request & msg)
{
  return community_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::srv::Rent_Request>()
{
  return "community_interfaces::srv::Rent_Request";
}

template<>
inline const char * name<community_interfaces::srv::Rent_Request>()
{
  return "community_interfaces/srv/Rent_Request";
}

template<>
struct has_fixed_size<community_interfaces::srv::Rent_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<community_interfaces::srv::Rent_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<community_interfaces::srv::Rent_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace community_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Rent_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: pay_money
  {
    out << "pay_money: ";
    rosidl_generator_traits::value_to_yaml(msg.pay_money, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Rent_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pay_money
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pay_money: ";
    rosidl_generator_traits::value_to_yaml(msg.pay_money, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Rent_Response & msg, bool use_flow_style = false)
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
  const community_interfaces::srv::Rent_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::srv::Rent_Response & msg)
{
  return community_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::srv::Rent_Response>()
{
  return "community_interfaces::srv::Rent_Response";
}

template<>
inline const char * name<community_interfaces::srv::Rent_Response>()
{
  return "community_interfaces/srv/Rent_Response";
}

template<>
struct has_fixed_size<community_interfaces::srv::Rent_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<community_interfaces::srv::Rent_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<community_interfaces::srv::Rent_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<community_interfaces::srv::Rent>()
{
  return "community_interfaces::srv::Rent";
}

template<>
inline const char * name<community_interfaces::srv::Rent>()
{
  return "community_interfaces/srv/Rent";
}

template<>
struct has_fixed_size<community_interfaces::srv::Rent>
  : std::integral_constant<
    bool,
    has_fixed_size<community_interfaces::srv::Rent_Request>::value &&
    has_fixed_size<community_interfaces::srv::Rent_Response>::value
  >
{
};

template<>
struct has_bounded_size<community_interfaces::srv::Rent>
  : std::integral_constant<
    bool,
    has_bounded_size<community_interfaces::srv::Rent_Request>::value &&
    has_bounded_size<community_interfaces::srv::Rent_Response>::value
  >
{
};

template<>
struct is_service<community_interfaces::srv::Rent>
  : std::true_type
{
};

template<>
struct is_service_request<community_interfaces::srv::Rent_Request>
  : std::true_type
{
};

template<>
struct is_service_response<community_interfaces::srv::Rent_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__RENT__TRAITS_HPP_
