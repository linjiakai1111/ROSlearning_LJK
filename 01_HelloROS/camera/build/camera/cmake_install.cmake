# Install script for directory: /home/line/ROSlearning_LJK/01_HelloROS/camera

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/line/ROSlearning_LJK/01_HelloROS/camera/install/camera")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/camera/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_generator_c/camera/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/environment" TYPE FILE FILES "/opt/ros/humble/lib/python3.10/site-packages/ament_package/template/environment_hook/library_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/environment" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/library_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_generator_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/camera/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_typesupport_fastrtps_c/camera/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/camera/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_generator_cpp/camera/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/camera/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_typesupport_fastrtps_cpp/camera/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/camera/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_typesupport_introspection_c/camera/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so"
         OLD_RPATH "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera:/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/camera/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_typesupport_introspection_cpp/camera/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/libcamera__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so"
         OLD_RPATH "/opt/ros/humble/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcamera__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/msg" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_adapter/camera/msg/RobotPoseMsg.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/msg" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/msg/RobotPoseMsg.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/camera" TYPE EXECUTABLE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/camera_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node"
         OLD_RPATH "/opt/ros/humble/lib:/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/camera_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/camera" TYPE EXECUTABLE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/machine_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node"
         OLD_RPATH "/opt/ros/humble/lib:/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/camera/machine_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE DIRECTORY FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/launch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/environment" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/environment" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_index/share/ament_index/resource_index/packages/camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_generator_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_generator_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_generator_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cppExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_generator_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_generator_cppExport.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/export_camera__rosidl_typesupport_fastrtps_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_introspection_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_introspection_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cppExport.cmake"
         "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/camera/cmake/camera__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/CMakeFiles/Export/share/camera/cmake/camera__rosidl_typesupport_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/rosidl_cmake/rosidl_cmake_aggregate_target-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera/cmake" TYPE FILE FILES
    "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_core/cameraConfig.cmake"
    "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/ament_cmake_core/cameraConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera" TYPE FILE FILES "/home/line/ROSlearning_LJK/01_HelloROS/camera/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/line/ROSlearning_LJK/01_HelloROS/camera/build/camera/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
