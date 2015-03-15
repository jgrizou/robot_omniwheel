#ifndef _ROS_roslego_motor_action_h
#define _ROS_roslego_motor_action_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roslego
{

  class motor_action : public ros::Msg
  {
    public:
      uint8_t motor_id;
      uint8_t option;
      uint32_t value;
      uint8_t speed;
      bool direction;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      *(outbuffer + offset + 0) = (this->option >> (8 * 0)) & 0xFF;
      offset += sizeof(this->option);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      *(outbuffer + offset + 0) = (this->speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        bool real;
        uint8_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->motor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor_id);
      this->option =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->option);
      this->value =  ((uint32_t) (*(inbuffer + offset)));
      this->value |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->value |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->value |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->value);
      this->speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed);
      union {
        bool real;
        uint8_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return "roslego/motor_action"; };
    const char * getMD5(){ return "a9cd8a8245ed8f77485f23b78d324966"; };

  };

}
#endif