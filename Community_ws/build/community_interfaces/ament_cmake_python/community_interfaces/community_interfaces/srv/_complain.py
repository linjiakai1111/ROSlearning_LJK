# generated from rosidl_generator_py/resource/_idl.py.em
# with input from community_interfaces:srv/Complain.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Complain_Request(type):
    """Metaclass of message 'Complain_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('community_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'community_interfaces.srv.Complain_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__complain__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__complain__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__complain__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__complain__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__complain__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Complain_Request(metaclass=Metaclass_Complain_Request):
    """Message class 'Complain_Request'."""

    __slots__ = [
        '_sound',
        '_db',
        '_duration_min',
    ]

    _fields_and_field_types = {
        'sound': 'string',
        'db': 'uint8',
        'duration_min': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sound = kwargs.get('sound', str())
        self.db = kwargs.get('db', int())
        self.duration_min = kwargs.get('duration_min', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.sound != other.sound:
            return False
        if self.db != other.db:
            return False
        if self.duration_min != other.duration_min:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sound(self):
        """Message field 'sound'."""
        return self._sound

    @sound.setter
    def sound(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sound' field must be of type 'str'"
        self._sound = value

    @builtins.property
    def db(self):
        """Message field 'db'."""
        return self._db

    @db.setter
    def db(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'db' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'db' field must be an unsigned integer in [0, 255]"
        self._db = value

    @builtins.property
    def duration_min(self):
        """Message field 'duration_min'."""
        return self._duration_min

    @duration_min.setter
    def duration_min(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration_min' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'duration_min' field must be an unsigned integer in [0, 65535]"
        self._duration_min = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Complain_Response(type):
    """Metaclass of message 'Complain_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('community_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'community_interfaces.srv.Complain_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__complain__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__complain__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__complain__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__complain__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__complain__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Complain_Response(metaclass=Metaclass_Complain_Response):
    """Message class 'Complain_Response'."""

    __slots__ = [
        '_success',
        '_feedback',
        '_expired_data',
        '_money',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'feedback': 'string',
        'expired_data': 'uint16',
        'money': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.feedback = kwargs.get('feedback', str())
        self.expired_data = kwargs.get('expired_data', int())
        self.money = kwargs.get('money', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.feedback != other.feedback:
            return False
        if self.expired_data != other.expired_data:
            return False
        if self.money != other.money:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'feedback' field must be of type 'str'"
        self._feedback = value

    @builtins.property
    def expired_data(self):
        """Message field 'expired_data'."""
        return self._expired_data

    @expired_data.setter
    def expired_data(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'expired_data' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'expired_data' field must be an unsigned integer in [0, 65535]"
        self._expired_data = value

    @builtins.property
    def money(self):
        """Message field 'money'."""
        return self._money

    @money.setter
    def money(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'money' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'money' field must be an unsigned integer in [0, 65535]"
        self._money = value


class Metaclass_Complain(type):
    """Metaclass of service 'Complain'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('community_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'community_interfaces.srv.Complain')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__complain

            from community_interfaces.srv import _complain
            if _complain.Metaclass_Complain_Request._TYPE_SUPPORT is None:
                _complain.Metaclass_Complain_Request.__import_type_support__()
            if _complain.Metaclass_Complain_Response._TYPE_SUPPORT is None:
                _complain.Metaclass_Complain_Response.__import_type_support__()


class Complain(metaclass=Metaclass_Complain):
    from community_interfaces.srv._complain import Complain_Request as Request
    from community_interfaces.srv._complain import Complain_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
