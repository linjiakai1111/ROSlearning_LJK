#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__msg__NoiseElement() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__msg__NoiseElement__init(msg: *mut NoiseElement) -> bool;
    fn community_interfaces__msg__NoiseElement__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NoiseElement>, size: usize) -> bool;
    fn community_interfaces__msg__NoiseElement__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NoiseElement>);
    fn community_interfaces__msg__NoiseElement__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NoiseElement>, out_seq: *mut rosidl_runtime_rs::Sequence<NoiseElement>) -> bool;
}

// Corresponds to community_interfaces__msg__NoiseElement
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ROS2字段名要求必须全部是小写并且不能以下划线结尾和连续下划线,对于声明字段文件不能在文件名中加入下划线，且文件名开头需大写

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NoiseElement {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sound: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub db: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration_sec: u16,

}



impl Default for NoiseElement {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__msg__NoiseElement__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__msg__NoiseElement__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NoiseElement {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__msg__NoiseElement__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__msg__NoiseElement__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__msg__NoiseElement__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NoiseElement {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NoiseElement where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/msg/NoiseElement";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__msg__NoiseElement() }
  }
}


