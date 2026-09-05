// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__BUILDER_HPP_
#define COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "community_interfaces/msg/detail/noise_element__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace community_interfaces
{

namespace msg
{

namespace builder
{

class Init_NoiseElement_duration_sec
{
public:
  explicit Init_NoiseElement_duration_sec(::community_interfaces::msg::NoiseElement & msg)
  : msg_(msg)
  {}
  ::community_interfaces::msg::NoiseElement duration_sec(::community_interfaces::msg::NoiseElement::_duration_sec_type arg)
  {
    msg_.duration_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::msg::NoiseElement msg_;
};

class Init_NoiseElement_db
{
public:
  explicit Init_NoiseElement_db(::community_interfaces::msg::NoiseElement & msg)
  : msg_(msg)
  {}
  Init_NoiseElement_duration_sec db(::community_interfaces::msg::NoiseElement::_db_type arg)
  {
    msg_.db = std::move(arg);
    return Init_NoiseElement_duration_sec(msg_);
  }

private:
  ::community_interfaces::msg::NoiseElement msg_;
};

class Init_NoiseElement_sound
{
public:
  Init_NoiseElement_sound()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NoiseElement_db sound(::community_interfaces::msg::NoiseElement::_sound_type arg)
  {
    msg_.sound = std::move(arg);
    return Init_NoiseElement_db(msg_);
  }

private:
  ::community_interfaces::msg::NoiseElement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::msg::NoiseElement>()
{
  return community_interfaces::msg::builder::Init_NoiseElement_sound();
}

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__BUILDER_HPP_
