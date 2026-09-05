#此文件用于创建自定义包
#标准消息接口std_msgs下的String类型
#std_msgs/String content
#图像消息，调用sensor_msgs下的Image类型
#sensor_msgs/Image Image
#但完成了代码的编写还不够，我们还要在CMakeLists.txt中告诉编译器，要把Novel_msg转换成Python库和C++的头文件
#原始数据类型
string content
#调用已有的消息类型
sensor_msgs/Image image