#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to community_interfaces__srv__Complain_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Complain_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sound: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub db: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration_min: u16,

}



impl Default for Complain_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Complain_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Complain_Request {
  type RmwMsg = super::srv::rmw::Complain_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sound: msg.sound.as_str().into(),
        db: msg.db,
        duration_min: msg.duration_min,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sound: msg.sound.as_str().into(),
      db: msg.db,
      duration_min: msg.duration_min,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sound: msg.sound.to_string(),
      db: msg.db,
      duration_min: msg.duration_min,
    }
  }
}


// Corresponds to community_interfaces__srv__Complain_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Complain_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub expired_data: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u16,

}



impl Default for Complain_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Complain_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Complain_Response {
  type RmwMsg = super::srv::rmw::Complain_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        feedback: msg.feedback.as_str().into(),
        expired_data: msg.expired_data,
        money: msg.money,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        feedback: msg.feedback.as_str().into(),
      expired_data: msg.expired_data,
      money: msg.money,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      feedback: msg.feedback.to_string(),
      expired_data: msg.expired_data,
      money: msg.money,
    }
  }
}


// Corresponds to community_interfaces__srv__Command_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: std::string::String,

}



impl Default for Command_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Command_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Command_Request {
  type RmwMsg = super::srv::rmw::Command_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command.to_string(),
    }
  }
}


// Corresponds to community_interfaces__srv__Command_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Command_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Command_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Command_Response {
  type RmwMsg = super::srv::rmw::Command_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to community_interfaces__srv__Rent_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Rent_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub ask_money: u16,

}



impl Default for Rent_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Rent_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Rent_Request {
  type RmwMsg = super::srv::rmw::Rent_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        ask_money: msg.ask_money,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      ask_money: msg.ask_money,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      ask_money: msg.ask_money,
    }
  }
}


// Corresponds to community_interfaces__srv__Rent_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Rent_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pay_money: u16,

}



impl Default for Rent_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Rent_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Rent_Response {
  type RmwMsg = super::srv::rmw::Rent_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pay_money: msg.pay_money,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pay_money: msg.pay_money,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pay_money: msg.pay_money,
    }
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


