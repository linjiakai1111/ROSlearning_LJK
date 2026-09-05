// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from community_interfaces:srv/Rent.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "community_interfaces/srv/detail/rent__struct.h"
#include "community_interfaces/srv/detail/rent__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool community_interfaces__srv__rent__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("community_interfaces.srv._rent.Rent_Request", full_classname_dest, 43) == 0);
  }
  community_interfaces__srv__Rent_Request * ros_message = _ros_message;
  {  // ask_money
    PyObject * field = PyObject_GetAttrString(_pymsg, "ask_money");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ask_money = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * community_interfaces__srv__rent__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Rent_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("community_interfaces.srv._rent");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Rent_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  community_interfaces__srv__Rent_Request * ros_message = (community_interfaces__srv__Rent_Request *)raw_ros_message;
  {  // ask_money
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ask_money);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ask_money", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "community_interfaces/srv/detail/rent__struct.h"
// already included above
// #include "community_interfaces/srv/detail/rent__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool community_interfaces__srv__rent__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("community_interfaces.srv._rent.Rent_Response", full_classname_dest, 44) == 0);
  }
  community_interfaces__srv__Rent_Response * ros_message = _ros_message;
  {  // pay_money
    PyObject * field = PyObject_GetAttrString(_pymsg, "pay_money");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pay_money = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * community_interfaces__srv__rent__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Rent_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("community_interfaces.srv._rent");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Rent_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  community_interfaces__srv__Rent_Response * ros_message = (community_interfaces__srv__Rent_Response *)raw_ros_message;
  {  // pay_money
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pay_money);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pay_money", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
