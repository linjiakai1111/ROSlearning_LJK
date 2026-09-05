// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from community_interfaces:srv/Rent.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__SRV__DETAIL__RENT__STRUCT_HPP_
#define COMMUNITY_INTERFACES__SRV__DETAIL__RENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__community_interfaces__srv__Rent_Request __attribute__((deprecated))
#else
# define DEPRECATED__community_interfaces__srv__Rent_Request __declspec(deprecated)
#endif

namespace community_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Rent_Request_
{
  using Type = Rent_Request_<ContainerAllocator>;

  explicit Rent_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ask_money = 0;
    }
  }

  explicit Rent_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ask_money = 0;
    }
  }

  // field types and members
  using _ask_money_type =
    uint16_t;
  _ask_money_type ask_money;

  // setters for named parameter idiom
  Type & set__ask_money(
    const uint16_t & _arg)
  {
    this->ask_money = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    community_interfaces::srv::Rent_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const community_interfaces::srv::Rent_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Rent_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Rent_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__community_interfaces__srv__Rent_Request
    std::shared_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__community_interfaces__srv__Rent_Request
    std::shared_ptr<community_interfaces::srv::Rent_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Rent_Request_ & other) const
  {
    if (this->ask_money != other.ask_money) {
      return false;
    }
    return true;
  }
  bool operator!=(const Rent_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Rent_Request_

// alias to use template instance with default allocator
using Rent_Request =
  community_interfaces::srv::Rent_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace community_interfaces


#ifndef _WIN32
# define DEPRECATED__community_interfaces__srv__Rent_Response __attribute__((deprecated))
#else
# define DEPRECATED__community_interfaces__srv__Rent_Response __declspec(deprecated)
#endif

namespace community_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Rent_Response_
{
  using Type = Rent_Response_<ContainerAllocator>;

  explicit Rent_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pay_money = 0;
    }
  }

  explicit Rent_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pay_money = 0;
    }
  }

  // field types and members
  using _pay_money_type =
    uint16_t;
  _pay_money_type pay_money;

  // setters for named parameter idiom
  Type & set__pay_money(
    const uint16_t & _arg)
  {
    this->pay_money = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    community_interfaces::srv::Rent_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const community_interfaces::srv::Rent_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Rent_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      community_interfaces::srv::Rent_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__community_interfaces__srv__Rent_Response
    std::shared_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__community_interfaces__srv__Rent_Response
    std::shared_ptr<community_interfaces::srv::Rent_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Rent_Response_ & other) const
  {
    if (this->pay_money != other.pay_money) {
      return false;
    }
    return true;
  }
  bool operator!=(const Rent_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Rent_Response_

// alias to use template instance with default allocator
using Rent_Response =
  community_interfaces::srv::Rent_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace community_interfaces

namespace community_interfaces
{

namespace srv
{

struct Rent
{
  using Request = community_interfaces::srv::Rent_Request;
  using Response = community_interfaces::srv::Rent_Response;
};

}  // namespace srv

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__SRV__DETAIL__RENT__STRUCT_HPP_
