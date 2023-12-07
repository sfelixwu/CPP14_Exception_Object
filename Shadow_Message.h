
#ifndef _SHADOW_MESSAGE_H_
#define _SHADOW_MESSAGE_H_

#include "Message.h"

class Shadow_Message: public Message
{
 private:
 public:
  
  Shadow_Message(std::string, std::string, std::string);
  virtual bool send(Json::Value);
  virtual bool JSON2Object(Json::Value);
  virtual Json::Value dump2JSON(void); // print the content of the object
};

#endif // _SHADOW_MESSAGE_H_
