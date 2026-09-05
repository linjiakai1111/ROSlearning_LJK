# （此Markdown用于CMake的学习）
- **注释：**
采用#进行注释，使用#[[content]]#进行块注释
- **命令**
  + `cmake_minimum_required(VERSION 3.0)`
  用于指定cmake的最低版本，不是必须要加的，但不加可能会有警告
  + `project(name)`
  用于指定工程名称，版本，描述，web主页地址，支持的语言等，除了名字都是可选项
  ```CMAKE
  project(<PROJECT-NAME>
          [VERSION <major>[,<minor>,[<patch>[,<tweak>]]]]
          [DESCRIPTION <project-description-string>]
          [HOMEPAGE_URL <url-string>]
          [LANGUAGE <language-name>])
  ```
  + `add_executable(可执行程序名 源文件名)`
  定义工程会生成一个可执行程序，这里的程序名与上面的`project`没有任何关系
  源文件可以是多个，此时用` `或 `;`进行分隔
  **在CMakeLists.txt同级目录下创建==build==文件夹，就可以自动把一些构建生成的文件塞到build文件里了**
  + `set(可执行程序名 源文件名)`用于给程序声明包含哪些源文件
  常常与`set_executable()`一起使用：
  ```CMAKE
  set(src calc.cpp mult.cpp sub.cpp)
  add_executable(app ${src})
  ```
  `${ }`表示取值，src代表一个变量表示符
  或者也可以给一些系统中已经定义好的宏赋值：
  ```CMAKE
  set(EXECUTABLE_OUTPUT_PATH ~/git/HelloCMake)
  set(CMAKE_CXX_STANDARD 11)
  ```
  ==EXECUTABLE_OUTPUT_PATH==为.exe文件输出路径
  ==LIBRARY_OUTPUT_PATH==为库文件输出路径
  CMAKE_CXX_STANDARD为C++版本
  除了set,还可以在使用命令行时给宏赋值：
  `cmake /path/to/app -D_宏名_=_值_`
  + `aux_source_directory(< dir > < variable >)`
  这个代码会将路径dir下的所有文件都读取出来，然后生成一个源文件列表赋值给dir
  + `file(GLOB/GLOB_RECURSE` 变量名 想要搜索的文件路径和文件类型)
  参数1：若为**GLOB**则表示在当前路径下搜索；若为**GLOB_RECURSE**则表示进行递归搜索
  参数2：变量名，即variable
  参数3：路径+文件类型，一般为/PATH/TO/FILE/*.cpp,或者.h,.c都行，*表示通配符
  补充：`CMAKE_CURRENT_SOURCE_DIR`是一个宏，表示CMakeLists.txt所在的路径，可用`${ }`进行取值
  eg:
  ```
  flie(GLOB_RECURSE MAIN_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
  file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_FILE}/include/*.hpp)
  ```
  
  + `include_directories(头文件路径)`
  eg:`include_directories(${CMAKE_CURRENT_SOURCE_FILE}/include)`表示在当前路径下找到一个include文件夹，而.h文件就在这个文件夹里
  + `add_library(库名称 STATIC/SHARED 源文件1 源文件2 ...)`
  **STATIC**表示的是制作静态库，而**SHARED**表示制作动态库
  用于制作库，库全名的组成包含3部分：
  1.lib
  2.库名称
  3.类型名后缀，linux系统里静态库是.a，动态库是.so；windows系统里是.lib
  add_library中只用填入库名称即可，另外两部分会自动生成
  eg:
  ```
  file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp)
  add_librarty(SRC STATIC ${SRC})
  ```
  **动态库有可以执行权限**
  