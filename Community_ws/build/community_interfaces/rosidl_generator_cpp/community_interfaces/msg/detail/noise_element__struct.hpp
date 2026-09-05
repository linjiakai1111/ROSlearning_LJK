// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from community_interfaces:msg/NoiseElement.idl
// generated code does not contain a copyright notice

#ifndef COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__STRUCT_HPP_
#define COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__community_interfaces__msg__NoiseElement __attribute__((deprecated))
#else
# define DEPRECATED__community_interfaces__msg__NoiseElement __declspec(deprecated)
#endif

namespace community_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NoiseElement_
{
  using Type = NoiseElement_<ContainerAllocator>;

  explicit NoiseElement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sound = "";
      this->db = 0;
      this->duration_sec = 0;
    }
  }

  explicit NoiseElement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sound(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sound = "";
      this->db = 0;
      this->duration_sec = 0;
    }
  }

  // field types and members
  using _sound_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sound_type sound;
  using _db_type =
    uint8_t;
  _db_type db;
  using _duration_sec_type =
    uint16_t;
  _duration_sec_type duration_sec;

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
  Type & set__duration_sec(
    const uint16_t & _arg)
  {
    this->duration_sec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    community_interfaces::msg::NoiseElement_<ContainerAllocator> *;
  using ConstRawPtr =
    const community_interfaces::msg::NoiseElement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      community_interfaces::msg::NoiseElement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      community_interfaces::msg::NoiseElement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__community_interfaces__msg__NoiseElement
    std::shared_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__community_interfaces__msg__NoiseElement
    std::shared_ptr<community_interfaces::msg::NoiseElement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NoiseElement_ & other) const
  {
    if (this->sound != other.sound) {
      return false;
    }
    if (this->db != other.db) {
      return false;
    }
    if (this->duration_sec != other.duration_sec) {
      return false;
    }
    return true;
  }
  bool operator!=(const NoiseElement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NoiseElement_

// alias to use template instance with default allocator
using NoiseElement =
  community_interfaces::msg::NoiseElement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace community_interfaces

#endif  // COMMUNITY_INTERFACES__MSG__DETAIL__NOISE_ELEMENT__STRUCT_HPP_
