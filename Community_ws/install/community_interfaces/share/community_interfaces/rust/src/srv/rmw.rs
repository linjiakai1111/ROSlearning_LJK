#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Complain_Request() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__srv__Complain_Request__init(msg: *mut Complain_Request) -> bool;
    fn community_interfaces__srv__Complain_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Complain_Request>, size: usize) -> bool;
    fn community_interfaces__srv__Complain_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Complain_Request>);
    fn community_interfaces__srv__Complain_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Complain_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Complain_Request>) -> bool;
}

// Corresponds to community_interfaces__srv__Complain_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Complain_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sound: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub db: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration_min: u16,

}



impl Default for Complain_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__srv__Complain_Request__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__srv__Complain_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Complain_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Complain_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Complain_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Complain_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Complain_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Complain_Request where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/srv/Complain_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Complain_Request() }
  }
}


#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Complain_Response() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__srv__Complain_Response__init(msg: *mut Complain_Response) -> bool;
    fn community_interfaces__srv__Complain_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Complain_Response>, size: usize) -> bool;
    fn community_interfaces__srv__Complain_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Complain_Response>);
    fn community_interfaces__srv__Complain_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Complain_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Complain_Response>) -> bool;
}

// Corresponds to community_interfaces__srv__Complain_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Complain_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expired_data: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u16,

}



impl Default for Complain_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__srv__Complain_Response__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__srv__Complain_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Complain_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Complain_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Complain_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Complain_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Complain_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Complain_Response where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/srv/Complain_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Complain_Response() }
  }
}


#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Command_Request() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__srv__Command_Request__init(msg: *mut Command_Request) -> bool;
    fn community_interfaces__srv__Command_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Command_Request>, size: usize) -> bool;
    fn community_interfaces__srv__Command_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Command_Request>);
    fn community_interfaces__srv__Command_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Command_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Command_Request>) -> bool;
}

// Corresponds to community_interfaces__srv__Command_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: rosidl_runtime_rs::String,

}



impl Default for Command_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__srv__Command_Request__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__srv__Command_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Command_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Command_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Command_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Command_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Command_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Command_Request where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/srv/Command_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Command_Request() }
  }
}


#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Command_Response() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__srv__Command_Response__init(msg: *mut Command_Response) -> bool;
    fn community_interfaces__srv__Command_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Command_Response>, size: usize) -> bool;
    fn community_interfaces__srv__Command_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Command_Response>);
    fn community_interfaces__srv__Command_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Command_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Command_Response>) -> bool;
}

// Corresponds to community_interfaces__srv__Command_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Command_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__srv__Command_Response__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__srv__Command_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Command_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Command_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Command_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Command_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Command_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Command_Response where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/srv/Command_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Command_Response() }
  }
}


#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Rent_Request() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__srv__Rent_Request__init(msg: *mut Rent_Request) -> bool;
    fn community_interfaces__srv__Rent_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Rent_Request>, size: usize) -> bool;
    fn community_interfaces__srv__Rent_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Rent_Request>);
    fn community_interfaces__srv__Rent_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Rent_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Rent_Request>) -> bool;
}

// Corresponds to community_interfaces__srv__Rent_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Rent_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub ask_money: u16,

}



impl Default for Rent_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__srv__Rent_Request__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__srv__Rent_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Rent_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Rent_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Rent_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Rent_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Rent_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Rent_Request where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/srv/Rent_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Rent_Request() }
  }
}


#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Rent_Response() -> *const std::ffi::c_void;
}

#[link(name = "community_interfaces__rosidl_generator_c")]
extern "C" {
    fn community_interfaces__srv__Rent_Response__init(msg: *mut Rent_Response) -> bool;
    fn community_interfaces__srv__Rent_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Rent_Response>, size: usize) -> bool;
    fn community_interfaces__srv__Rent_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Rent_Response>);
    fn community_interfaces__srv__Rent_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Rent_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Rent_Response>) -> bool;
}

// Corresponds to community_interfaces__srv__Rent_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Rent_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pay_money: u16,

}



impl Default for Rent_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !community_interfaces__srv__Rent_Response__init(&mut msg as *mut _) {
        panic!("Call to community_interfaces__srv__Rent_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Rent_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Rent_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Rent_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { community_interfaces__srv__Rent_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Rent_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Rent_Response where Self: Sized {
  const TYPE_NAME: &'static str = "community_interfaces/srv/Rent_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__community_interfaces__srv__Rent_Response() }
  }
}






#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__community_interfaces__srv__Complain() -> *const std::ffi::c_void;
}

// Corresponds to community_interfaces__srv__Complain
#[allow(missing_docs, non_camel_case_types)]
pub struct Complain;

impl rosidl_runtime_rs::Service for Complain {
    type Request = Complain_Request;
    type Response = Complain_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__community_interfaces__srv__Complain() }
    }
}




#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__community_interfaces__srv__Command() -> *const std::ffi::c_void;
}

// Corresponds to community_interfaces__srv__Command
#[allow(missing_docs, non_camel_case_types)]
pub struct Command;

impl rosidl_runtime_rs::Service for Command {
    type Request = Command_Request;
    type Response = Command_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__community_interfaces__srv__Command() }
    }
}




#[link(name = "community_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__community_interfaces__srv__Rent() -> *const std::ffi::c_void;
}

// Corresponds to community_interfaces__srv__Rent
#[allow(missing_docs, non_camel_case_types)]
pub struct Rent;

impl rosidl_runtime_rs::Service for Rent {
    type Request = Rent_Request;
    type Response = Rent_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__community_interfaces__srv__Rent() }
    }
}


