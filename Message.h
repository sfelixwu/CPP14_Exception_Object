
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

// Message.h -- a simple message format between Teams
#include "ecs36b_Common.h"
#include "Core.h"
#include "Commutable.h"
#include "Team.h"
#include "SP_Person.h"

// call by value       (copy/clone)
// call by reference   (using the same memory space/ change the original copy)
// call by name

// is the content of "from" the same between option #1 and #2?

class Message : public Core
{
 private:
 protected:
 public:
  Commutable& from;   // Another& from;
  Commutable& to;     // Another& to;
  Json::Value content;

  Message(Commutable& _f, Commutable& _t): from {_f}, to {_t} {};
  
  virtual bool send(Json::Value);
  virtual Json::Value dump2JSON(void);
  virtual bool JSON2Object(Json::Value);
};

#endif /* _MESSAGE_H_ */
