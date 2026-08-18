// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from camera:msg/RobotPoseMsg.idl
// generated code does not contain a copyright notice

#ifndef CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__STRUCT_HPP_
#define CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
#include "std_msgs/msg/detail/float32__struct.hpp"
// Member 'angles'
#include "std_msgs/msg/detail/float32_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__camera__msg__RobotPoseMsg __attribute__((deprecated))
#else
# define DEPRECATED__camera__msg__RobotPoseMsg __declspec(deprecated)
#endif

namespace camera
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotPoseMsg_
{
  using Type = RobotPoseMsg_<ContainerAllocator>;

  explicit RobotPoseMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : x(_init),
    y(_init),
    z(_init),
    angles(_init)
  {
    (void)_init;
  }

  explicit RobotPoseMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : x(_alloc, _init),
    y(_alloc, _init),
    z(_alloc, _init),
    angles(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _x_type =
    std_msgs::msg::Float32_<ContainerAllocator>;
  _x_type x;
  using _y_type =
    std_msgs::msg::Float32_<ContainerAllocator>;
  _y_type y;
  using _z_type =
    std_msgs::msg::Float32_<ContainerAllocator>;
  _z_type z;
  using _angles_type =
    std_msgs::msg::Float32MultiArray_<ContainerAllocator>;
  _angles_type angles;

  // setters for named parameter idiom
  Type & set__x(
    const std_msgs::msg::Float32_<ContainerAllocator> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std_msgs::msg::Float32_<ContainerAllocator> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const std_msgs::msg::Float32_<ContainerAllocator> & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__angles(
    const std_msgs::msg::Float32MultiArray_<ContainerAllocator> & _arg)
  {
    this->angles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    camera::msg::RobotPoseMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const camera::msg::RobotPoseMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      camera::msg::RobotPoseMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      camera::msg::RobotPoseMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__camera__msg__RobotPoseMsg
    std::shared_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__camera__msg__RobotPoseMsg
    std::shared_ptr<camera::msg::RobotPoseMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotPoseMsg_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->angles != other.angles) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotPoseMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotPoseMsg_

// alias to use template instance with default allocator
using RobotPoseMsg =
  camera::msg::RobotPoseMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace camera

#endif  // CAMERA__MSG__DETAIL__ROBOT_POSE_MSG__STRUCT_HPP_
