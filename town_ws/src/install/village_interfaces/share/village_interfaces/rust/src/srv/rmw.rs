#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "village_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__BorrowMoney_Request() -> *const std::ffi::c_void;
}

#[link(name = "village_interfaces__rosidl_generator_c")]
extern "C" {
    fn village_interfaces__srv__BorrowMoney_Request__init(msg: *mut BorrowMoney_Request) -> bool;
    fn village_interfaces__srv__BorrowMoney_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BorrowMoney_Request>, size: usize) -> bool;
    fn village_interfaces__srv__BorrowMoney_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BorrowMoney_Request>);
    fn village_interfaces__srv__BorrowMoney_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BorrowMoney_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<BorrowMoney_Request>) -> bool;
}

// Corresponds to village_interfaces__srv__BorrowMoney_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BorrowMoney_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u32,

}



impl Default for BorrowMoney_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !village_interfaces__srv__BorrowMoney_Request__init(&mut msg as *mut _) {
        panic!("Call to village_interfaces__srv__BorrowMoney_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BorrowMoney_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__BorrowMoney_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__BorrowMoney_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__BorrowMoney_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BorrowMoney_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BorrowMoney_Request where Self: Sized {
  const TYPE_NAME: &'static str = "village_interfaces/srv/BorrowMoney_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__BorrowMoney_Request() }
  }
}


#[link(name = "village_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__BorrowMoney_Response() -> *const std::ffi::c_void;
}

#[link(name = "village_interfaces__rosidl_generator_c")]
extern "C" {
    fn village_interfaces__srv__BorrowMoney_Response__init(msg: *mut BorrowMoney_Response) -> bool;
    fn village_interfaces__srv__BorrowMoney_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BorrowMoney_Response>, size: usize) -> bool;
    fn village_interfaces__srv__BorrowMoney_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BorrowMoney_Response>);
    fn village_interfaces__srv__BorrowMoney_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BorrowMoney_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<BorrowMoney_Response>) -> bool;
}

// Corresponds to village_interfaces__srv__BorrowMoney_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BorrowMoney_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u32,

}



impl Default for BorrowMoney_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !village_interfaces__srv__BorrowMoney_Response__init(&mut msg as *mut _) {
        panic!("Call to village_interfaces__srv__BorrowMoney_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BorrowMoney_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__BorrowMoney_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__BorrowMoney_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__BorrowMoney_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BorrowMoney_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BorrowMoney_Response where Self: Sized {
  const TYPE_NAME: &'static str = "village_interfaces/srv/BorrowMoney_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__BorrowMoney_Response() }
  }
}


#[link(name = "village_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__SellNovel_Request() -> *const std::ffi::c_void;
}

#[link(name = "village_interfaces__rosidl_generator_c")]
extern "C" {
    fn village_interfaces__srv__SellNovel_Request__init(msg: *mut SellNovel_Request) -> bool;
    fn village_interfaces__srv__SellNovel_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SellNovel_Request>, size: usize) -> bool;
    fn village_interfaces__srv__SellNovel_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SellNovel_Request>);
    fn village_interfaces__srv__SellNovel_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SellNovel_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SellNovel_Request>) -> bool;
}

// Corresponds to village_interfaces__srv__SellNovel_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SellNovel_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u32,

}



impl Default for SellNovel_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !village_interfaces__srv__SellNovel_Request__init(&mut msg as *mut _) {
        panic!("Call to village_interfaces__srv__SellNovel_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SellNovel_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__SellNovel_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__SellNovel_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__SellNovel_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SellNovel_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SellNovel_Request where Self: Sized {
  const TYPE_NAME: &'static str = "village_interfaces/srv/SellNovel_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__SellNovel_Request() }
  }
}


#[link(name = "village_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__SellNovel_Response() -> *const std::ffi::c_void;
}

#[link(name = "village_interfaces__rosidl_generator_c")]
extern "C" {
    fn village_interfaces__srv__SellNovel_Response__init(msg: *mut SellNovel_Response) -> bool;
    fn village_interfaces__srv__SellNovel_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SellNovel_Response>, size: usize) -> bool;
    fn village_interfaces__srv__SellNovel_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SellNovel_Response>);
    fn village_interfaces__srv__SellNovel_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SellNovel_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SellNovel_Response>) -> bool;
}

// Corresponds to village_interfaces__srv__SellNovel_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SellNovel_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub novel: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for SellNovel_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !village_interfaces__srv__SellNovel_Response__init(&mut msg as *mut _) {
        panic!("Call to village_interfaces__srv__SellNovel_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SellNovel_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__SellNovel_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__SellNovel_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { village_interfaces__srv__SellNovel_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SellNovel_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SellNovel_Response where Self: Sized {
  const TYPE_NAME: &'static str = "village_interfaces/srv/SellNovel_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__village_interfaces__srv__SellNovel_Response() }
  }
}






#[link(name = "village_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__village_interfaces__srv__BorrowMoney() -> *const std::ffi::c_void;
}

// Corresponds to village_interfaces__srv__BorrowMoney
#[allow(missing_docs, non_camel_case_types)]
pub struct BorrowMoney;

impl rosidl_runtime_rs::Service for BorrowMoney {
    type Request = BorrowMoney_Request;
    type Response = BorrowMoney_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__village_interfaces__srv__BorrowMoney() }
    }
}




#[link(name = "village_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__village_interfaces__srv__SellNovel() -> *const std::ffi::c_void;
}

// Corresponds to village_interfaces__srv__SellNovel
#[allow(missing_docs, non_camel_case_types)]
pub struct SellNovel;

impl rosidl_runtime_rs::Service for SellNovel {
    type Request = SellNovel_Request;
    type Response = SellNovel_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__village_interfaces__srv__SellNovel() }
    }
}


