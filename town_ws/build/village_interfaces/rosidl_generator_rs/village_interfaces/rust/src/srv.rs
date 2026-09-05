#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to village_interfaces__srv__BorrowMoney_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BorrowMoney_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u32,

}



impl Default for BorrowMoney_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::BorrowMoney_Request::default())
  }
}

impl rosidl_runtime_rs::Message for BorrowMoney_Request {
  type RmwMsg = super::srv::rmw::BorrowMoney_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        money: msg.money,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
      money: msg.money,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      money: msg.money,
    }
  }
}


// Corresponds to village_interfaces__srv__BorrowMoney_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::BorrowMoney_Response::default())
  }
}

impl rosidl_runtime_rs::Message for BorrowMoney_Response {
  type RmwMsg = super::srv::rmw::BorrowMoney_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        money: msg.money,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      money: msg.money,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      money: msg.money,
    }
  }
}


// Corresponds to village_interfaces__srv__SellNovel_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SellNovel_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub money: u32,

}



impl Default for SellNovel_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SellNovel_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SellNovel_Request {
  type RmwMsg = super::srv::rmw::SellNovel_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        money: msg.money,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      money: msg.money,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      money: msg.money,
    }
  }
}


// Corresponds to village_interfaces__srv__SellNovel_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SellNovel_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub novel: Vec<std::string::String>,

}



impl Default for SellNovel_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SellNovel_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SellNovel_Response {
  type RmwMsg = super::srv::rmw::SellNovel_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        novel: msg.novel
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        novel: msg.novel
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      novel: msg.novel
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
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


