// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from community_interfaces:srv/Complain.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__STRUCT_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__community_interfaces__srv__Complain_Request __attribute__((deprecated))
#else
# define DEPRECATED__community_interfaces__srv__Complain_Request __declspec(deprecated)
#endif

namespace community_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Complain_Request_
{
  using Type = Complain_Request_<ContainerAllocator>;

  explicit Complain_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sound = "";
      this->db = 0;
      this->duration_min = 0;
    }
  }

  explicit Complain_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sound(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sound = "";
      this->db = 0;
      this->duration_min = 0;
    }
  }

  // field types and members
  using _sound_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sound_type sound;
  using _db_type =
    uint8_t;
  _db_type db;
  using _duration_min_type =
    uint16_t;
  _duration_min_type duration_min;

  // setters for named parameter idiom
  Type & set__sound(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sound = _arg;
    return *this;
  }
  Type & set__db(
    const uint8_t & _arg)
  {
    this->db = _arg;
    return *this;
  }
  Type & set__duration_min(
    const uint16_t & _arg)
  {
    this->duration_min = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    community_interfaces::srv::Complain_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const community_interfaces::srv::Complain_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Complain_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Complain_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__community_interfaces__srv__Complain_Request
    std::shared_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__community_interfaces__srv__Complain_Request
    std::shared_ptr<community_interfaces::srv::Complain_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Complain_Request_ & other) const
  {
    if (this->sound != other.sound) {
      return false;
    }
    if (this->db != other.db) {
      return false;
    }
    if (this->duration_min != other.duration_min) {
      return false;
    }
    return true;
  }
  bool operator!=(const Complain_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Complain_Request_

// alias to use template instance with default allocator
using Complain_Request =
  community_interfaces::srv::Complain_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace community_interfaces


#ifndef _WIN32
# define DEPRECATED__community_interfaces__srv__Complain_Response __attribute__((deprecated))
#else
# define DEPRECATED__community_interfaces__srv__Complain_Response __declspec(deprecated)
#endif

namespace community_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Complain_Response_
{
  using Type = Complain_Response_<ContainerAllocator>;

  explicit Complain_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->feedback = "";
      this->expired_data = 0;
      this->money = 0;
    }
  }

  explicit Complain_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feedback(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->feedback = "";
      this->expired_data = 0;
      this->money = 0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _feedback_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feedback_type feedback;
  using _expired_data_type =
    uint16_t;
  _expired_data_type expired_data;
  using _money_type =
    uint16_t;
  _money_type money;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__feedback(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }
  Type & set__expired_data(
    const uint16_t & _arg)
  {
    this->expired_data = _arg;
    return *this;
  }
  Type & set__money(
    const uint16_t & _arg)
  {
    this->money = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    community_interfaces::srv::Complain_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const community_interfaces::srv::Complain_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Complain_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Complain_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__community_interfaces__srv__Complain_Response
    std::shared_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__community_interfaces__srv__Complain_Response
    std::shared_ptr<community_interfaces::srv::Complain_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Complain_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    if (this->expired_data != other.expired_data) {
      return false;
    }
    if (this->money != other.money) {
      return false;
    }
    return true;
  }
  bool operator!=(const Complain_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Complain_Response_

// alias to use template instance with default allocator
using Complain_Response =
  community_interfaces::srv::Complain_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace community_interfaces

namespace community_interfaces
{

namespace srv
{

struct Complain
{
  using Request = community_interfaces::srv::Complain_Request;
  using Response = community_interfaces::srv::Complain_Response;
};

}  // namespace srv

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__COMPLAIN__STRUCT_HPP_
