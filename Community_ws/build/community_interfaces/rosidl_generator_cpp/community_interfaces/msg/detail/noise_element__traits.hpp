// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__TRAITS_HPP_
#define COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "community_interfaces/msg/detail/noise_element__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace community_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NoiseElement & msg,
  std::ostream & out)
{
  out << "{";
  // member: sound
  {
    out << "sound: ";
    rosidl_generator_traits::value_to_yaml(msg.sound, out);
    out << ", ";
  }

  // member: db
  {
    out << "db: ";
    rosidl_generator_traits::value_to_yaml(msg.db, out);
    out << ", ";
  }

  // member: duration_sec
  {
    out << "duration_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_sec, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NoiseElement & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sound
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sound: ";
    rosidl_generator_traits::value_to_yaml(msg.sound, out);
    out << "\n";
  }

  // member: db
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "db: ";
    rosidl_generator_traits::value_to_yaml(msg.db, out);
    out << "\n";
  }

  // member: duration_sec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_sec, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NoiseElement & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace community_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use community_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const community_interfaces::msg::NoiseElement & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::msg::NoiseElement & msg)
{
  return community_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::msg::NoiseElement>()
{
  return "community_interfaces::msg::NoiseElement";
}

template<>
inline const char * name<community_interfaces::msg::NoiseElement>()
{
  return "community_interfaces/msg/NoiseElement";
}

template<>
struct has_fixed_size<community_interfaces::msg::NoiseElement>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<community_interfaces::msg::NoiseElement>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<community_interfaces::msg::NoiseElement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__TRAITS_HPP_
