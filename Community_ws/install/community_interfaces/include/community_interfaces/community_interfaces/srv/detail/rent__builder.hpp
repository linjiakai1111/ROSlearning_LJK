// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from community_interfaces:srv/Rent.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__RENT__BUILDER_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__RENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "community_interfaces/srv/detail/rent__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace community_interfaces
{

namespace srv
{

namespace builder
{

class Init_Rent_Request_ask_money
{
public:
  Init_Rent_Request_ask_money()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::community_interfaces::srv::Rent_Request ask_money(::community_interfaces::srv::Rent_Request::_ask_money_type arg)
  {
    msg_.ask_money = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::srv::Rent_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::srv::Rent_Request>()
{
  return community_interfaces::srv::builder::Init_Rent_Request_ask_money();
}

}  // namespace community_interfaces


namespace community_interfaces
{

namespace srv
{

namespace builder
{

class Init_Rent_Response_pay_money
{
public:
  Init_Rent_Response_pay_money()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::community_interfaces::srv::Rent_Response pay_money(::community_interfaces::srv::Rent_Response::_pay_money_type arg)
  {
    msg_.pay_money = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::srv::Rent_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::srv::Rent_Response>()
{
  return community_interfaces::srv::builder::Init_Rent_Response_pay_money();
}

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__RENT__BUILDER_HPP_
