/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/motor_action.msg
 *
 */


#ifndef ROSLEGO_MESSAGE_MOTOR_ACTION_H
#define ROSLEGO_MESSAGE_MOTOR_ACTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace roslego
{
template <class ContainerAllocator>
struct motor_action_
{
  typedef motor_action_<ContainerAllocator> Type;

  motor_action_()
    : motor_id(0)
    , option(0)
    , value(0)
    , speed(0)
    , direction(false)  {
    }
  motor_action_(const ContainerAllocator& _alloc)
    : motor_id(0)
    , option(0)
    , value(0)
    , speed(0)
    , direction(false)  {
    }



   typedef uint8_t _motor_id_type;
  _motor_id_type motor_id;

   typedef uint8_t _option_type;
  _option_type option;

   typedef uint32_t _value_type;
  _value_type value;

   typedef uint8_t _speed_type;
  _speed_type speed;

   typedef uint8_t _direction_type;
  _direction_type direction;




  typedef boost::shared_ptr< ::roslego::motor_action_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roslego::motor_action_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct motor_action_

typedef ::roslego::motor_action_<std::allocator<void> > motor_action;

typedef boost::shared_ptr< ::roslego::motor_action > motor_actionPtr;
typedef boost::shared_ptr< ::roslego::motor_action const> motor_actionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roslego::motor_action_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roslego::motor_action_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roslego

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/groovy/share/std_msgs/msg'], 'roslego': ['/home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roslego::motor_action_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roslego::motor_action_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roslego::motor_action_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roslego::motor_action_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roslego::motor_action_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roslego::motor_action_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roslego::motor_action_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a9cd8a8245ed8f77485f23b78d324966";
  }

  static const char* value(const ::roslego::motor_action_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa9cd8a8245ed8f77ULL;
  static const uint64_t static_value2 = 0x485f23b78d324966ULL;
};

template<class ContainerAllocator>
struct DataType< ::roslego::motor_action_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roslego/motor_action";
  }

  static const char* value(const ::roslego::motor_action_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roslego::motor_action_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 motor_id\n\
uint8 option\n\
uint32 value\n\
uint8 speed\n\
bool direction\n\
\n\
\n\
";
  }

  static const char* value(const ::roslego::motor_action_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roslego::motor_action_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.motor_id);
      stream.next(m.option);
      stream.next(m.value);
      stream.next(m.speed);
      stream.next(m.direction);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct motor_action_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roslego::motor_action_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roslego::motor_action_<ContainerAllocator>& v)
  {
    s << indent << "motor_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motor_id);
    s << indent << "option: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.option);
    s << indent << "value: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.value);
    s << indent << "speed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.speed);
    s << indent << "direction: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.direction);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSLEGO_MESSAGE_MOTOR_ACTION_H
