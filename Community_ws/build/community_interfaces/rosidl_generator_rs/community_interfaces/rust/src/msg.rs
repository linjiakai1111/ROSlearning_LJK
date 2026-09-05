#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to community_interfaces__msg__NoiseElement
/// ROS2字段名要求必须全部是小写并且不能以下划线结尾和连续下划线,对于声明字段文件不能在文件名中加入下划线，且文件名开头需大写

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NoiseElement {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sound: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub db: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration_sec: u16,

}



impl Default for NoiseElement {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NoiseElement::default())
  }
}

impl rosidl_runtime_rs::Message for NoiseElement {
  type RmwMsg = super::msg::rmw::NoiseElement;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sound: msg.sound.as_str().into(),
        db: msg.db,
        duration_sec: msg.duration_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sound: msg.sound.as_str().into(),
      db: msg.db,
      duration_sec: msg.duration_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sound: msg.sound.to_string(),
      db: msg.db,
      duration_sec: msg.duration_sec,
    }
  }
}


