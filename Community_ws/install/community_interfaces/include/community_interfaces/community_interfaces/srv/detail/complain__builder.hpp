// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from community_interfaces:srv/Complain.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__BUILDER_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "community_interfaces/srv/detail/complain__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace community_interfaces
{

namespace srv
{

namespace builder
{

class Init_Complain_Request_duration_min
{
public:
  explicit Init_Complain_Request_duration_min(::community_interfaces::srv::Complain_Request & msg)
  : msg_(msg)
  {}
  ::community_interfaces::srv::Complain_Request duration_min(::community_interfaces::srv::Complain_Request::_duration_min_type arg)
  {
    msg_.duration_min = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Request msg_;
};

class Init_Complain_Request_db
{
public:
  explicit Init_Complain_Request_db(::community_interfaces::srv::Complain_Request & msg)
  : msg_(msg)
  {}
  Init_Complain_Request_duration_min db(::community_interfaces::srv::Complain_Request::_db_type arg)
  {
    msg_.db = std::move(arg);
    return Init_Complain_Request_duration_min(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Request msg_;
};

class Init_Complain_Request_sound
{
public:
  Init_Complain_Request_sound()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Complain_Request_db sound(::community_interfaces::srv::Complain_Request::_sound_type arg)
  {
    msg_.sound = std::move(arg);
    return Init_Complain_Request_db(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::srv::Complain_Request>()
{
  return community_interfaces::srv::builder::Init_Complain_Request_sound();
}

}  // namespace community_interfaces


namespace community_interfaces
{

namespace srv
{

namespace builder
{

class Init_Complain_Response_money
{
public:
  explicit Init_Complain_Response_money(::community_interfaces::srv::Complain_Response & msg)
  : msg_(msg)
  {}
  ::community_interfaces::srv::Complain_Response money(::community_interfaces::srv::Complain_Response::_money_type arg)
  {
    msg_.money = std::move(arg);
    return std::move(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Response msg_;
};

class Init_Complain_Response_expired_data
{
public:
  explicit Init_Complain_Response_expired_data(::community_interfaces::srv::Complain_Response & msg)
  : msg_(msg)
  {}
  Init_Complain_Response_money expired_data(::community_interfaces::srv::Complain_Response::_expired_data_type arg)
  {
    msg_.expired_data = std::move(arg);
    return Init_Complain_Response_money(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Response msg_;
};

class Init_Complain_Response_feedback
{
public:
  explicit Init_Complain_Response_feedback(::community_interfaces::srv::Complain_Response & msg)
  : msg_(msg)
  {}
  Init_Complain_Response_expired_data feedback(::community_interfaces::srv::Complain_Response::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return Init_Complain_Response_expired_data(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Response msg_;
};

class Init_Complain_Response_success
{
public:
  Init_Complain_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Complain_Response_feedback success(::community_interfaces::srv::Complain_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Complain_Response_feedback(msg_);
  }

private:
  ::community_interfaces::srv::Complain_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::community_interfaces::srv::Complain_Response>()
{
  return community_interfaces::srv::builder::Init_Complain_Response_success();
}

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__BUILDER_HPP_
