#ifndef _ROS_capabilities_CapabilityEvent_h
#define _ROS_capabilities_CapabilityEvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace capabilities
{

  class CapabilityEvent : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* capability;
      const char* provider;
      const char* type;
      int32_t pid;
      enum { LAUNCHED = "launched" };
      enum { STOPPED = "stopped" };
      enum { TERMINATED = "terminated" };
      enum { SERVER_READY = "server_ready" };

    CapabilityEvent():
      header(),
      capability(""),
      provider(""),
      type(""),
      pid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_capability = strlen(this->capability);
      memcpy(outbuffer + offset, &length_capability, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->capability, length_capability);
      offset += length_capability;
      uint32_t length_provider = strlen(this->provider);
      memcpy(outbuffer + offset, &length_provider, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->provider, length_provider);
      offset += length_provider;
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      union {
        int32_t real;
        uint32_t base;
      } u_pid;
      u_pid.real = this->pid;
      *(outbuffer + offset + 0) = (u_pid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_capability;
      memcpy(&length_capability, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_capability; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_capability-1]=0;
      this->capability = (char *)(inbuffer + offset-1);
      offset += length_capability;
      uint32_t length_provider;
      memcpy(&length_provider, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_provider; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_provider-1]=0;
      this->provider = (char *)(inbuffer + offset-1);
      offset += length_provider;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      union {
        int32_t real;
        uint32_t base;
      } u_pid;
      u_pid.base = 0;
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pid = u_pid.real;
      offset += sizeof(this->pid);
     return offset;
    }

    const char * getType(){ return "capabilities/CapabilityEvent"; };
    const char * getMD5(){ return "5a0d82ee1a8e7a5d0b058f0b20305b18"; };

  };

}
#endif