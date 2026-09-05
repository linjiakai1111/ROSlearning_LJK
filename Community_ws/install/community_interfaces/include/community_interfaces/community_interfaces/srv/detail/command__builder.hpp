// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from community_interfaces:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__COMMAND__BUILDER_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "community_interfaces/srv/detail/command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace community_interfaces
{

namespace srv
{

namespace builder
{

class Init_Command_Request_command
{
public:
  Init_Command_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::community_interfaces::srv::Command_Request command(::community_interfaces::srv::Command_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::srv::Command_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::srv::Command_Request>()
{
  return community_interfaces::srv::builder::Init_Command_Request_command();
}

}  // namespace community_interfaces


namespace community_interfaces
{

namespace srv
{

namespace builder
{

class Init_Command_Response_success
{
public:
  Init_Command_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::community_interfaces::srv::Command_Response success(::community_interfaces::srv::Command_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::srv::Command_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::srv::Command_Response>()
{
  return community_interfaces::srv::builder::Init_Command_Response_success();
}

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__COMMAND__BUILDER_HPP_
