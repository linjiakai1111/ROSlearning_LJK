// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from community_interfaces:srv/Complain.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__TRAITS_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "community_interfaces/srv/detail/complain__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace community_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Complain_Request & msg,
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

  // member: duration_min
  {
    out << "duration_min: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_min, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Complain_Request & msg,
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

  // member: duration_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration_min: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_min, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Complain_Request & msg, bool use_flow_style = false)
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
  const community_interfaces::srv::Complain_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::srv::Complain_Request & msg)
{
  return community_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::srv::Complain_Request>()
{
  return "community_interfaces::srv::Complain_Request";
}

template<>
inline const char * name<community_interfaces::srv::Complain_Request>()
{
  return "community_interfaces/srv/Complain_Request";
}

template<>
struct has_fixed_size<community_interfaces::srv::Complain_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<community_interfaces::srv::Complain_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<community_interfaces::srv::Complain_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace community_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Complain_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback, out);
    out << ", ";
  }

  // member: expired_data
  {
    out << "expired_data: ";
    rosidl_generator_traits::value_to_yaml(msg.expired_data, out);
    out << ", ";
  }

  // member: money
  {
    out << "money: ";
    rosidl_generator_traits::value_to_yaml(msg.money, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Complain_Response & msg,
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

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback, out);
    out << "\n";
  }

  // member: expired_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "expired_data: ";
    rosidl_generator_traits::value_to_yaml(msg.expired_data, out);
    out << "\n";
  }

  // member: money
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "money: ";
    rosidl_generator_traits::value_to_yaml(msg.money, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Complain_Response & msg, bool use_flow_style = false)
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
  const community_interfaces::srv::Complain_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  community_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use community_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const community_interfaces::srv::Complain_Response & msg)
{
  return community_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<community_interfaces::srv::Complain_Response>()
{
  return "community_interfaces::srv::Complain_Response";
}

template<>
inline const char * name<community_interfaces::srv::Complain_Response>()
{
  return "community_interfaces/srv/Complain_Response";
}

template<>
struct has_fixed_size<community_interfaces::srv::Complain_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<community_interfaces::srv::Complain_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<community_interfaces::srv::Complain_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<community_interfaces::srv::Complain>()
{
  return "community_interfaces::srv::Complain";
}

template<>
inline const char * name<community_interfaces::srv::Complain>()
{
  return "community_interfaces/srv/Complain";
}

template<>
struct has_fixed_size<community_interfaces::srv::Complain>
  : std::integral_constant<
    bool,
    has_fixed_size<community_interfaces::srv::Complain_Request>::value &&
    has_fixed_size<community_interfaces::srv::Complain_Response>::value
  >
{
};

template<>
struct has_bounded_size<community_interfaces::srv::Complain>
  : std::integral_constant<
    bool,
    has_bounded_size<community_interfaces::srv::Complain_Request>::value &&
    has_bounded_size<community_interfaces::srv::Complain_Response>::value
  >
{
};

template<>
struct is_service<community_interfaces::srv::Complain>
  : std::true_type
{
};

template<>
struct is_service_request<community_interfaces::srv::Complain_Request>
  : std::true_type
{
};

template<>
struct is_service_response<community_interfaces::srv::Complain_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__TRAITS_HPP_
