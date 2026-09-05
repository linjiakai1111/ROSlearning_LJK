#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to village_interfaces__msg__Novel
/// 此文件用于创建自定义包
/// 标准消息接口std_msgs下的String类型
/// std_msgs/String content
/// 图像消息，调用sensor_msgs下的Image类型
/// sensor_msgs/Image Image
/// 但完成了代码的编写还不够，我们还要在CMakeLists.txt中告诉编译器，要把Novel_msg转换成Python库和C++的头文件
/// 原始数据类型

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Novel {

    // This member is not documented.
    #[allow(missing_docs)]
    pub content: std::string::String,

    /// 调用已有的消息类型
    pub image: sensor_msgs::msg::Image,

}



impl Default for Novel {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Novel::default())
  }
}

impl rosidl_runtime_rs::Message for Novel {
  type RmwMsg = super::msg::rmw::Novel;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        content: msg.content.as_str().into(),
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(msg.image)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        content: msg.content.as_str().into(),
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(&msg.image)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      content: msg.content.to_string(),
      image: sensor_msgs::msg::Image::from_rmw_message(msg.image),
    }
  }
}


