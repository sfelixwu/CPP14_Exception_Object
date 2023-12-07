
#include "Core.h"

unsigned int Core::core_count { };

Core::Core(void)
{
  core_count++;
}

Core::Core(std::string arg_host_url, std::string arg_class_name, std::string arg_object_id)
 : host_url { arg_host_url }, class_name { arg_class_name }, 
   object_id { arg_object_id }
{
  core_count++; 
}

Json::Value
Core::dump2JSON
(void)
{
  Json::Value result;
  result["host url"]    = this->host_url;
  result["class name"]  = this->class_name;
  result["object id"]   = this->object_id;
  return result;
}

bool
Core::JSON2Object
(Json::Value arg_json_value)
{
  if ((arg_json_value["host url"].isNull() == true) ||
      (arg_json_value["host url"].isString() == false))
    {
      // throw something
    }
  else
    {
      this->host_url = (arg_json_value["host url"]).asString();
    }

  if ((arg_json_value["class name"].isNull() == true) ||
      (arg_json_value["class name"].isString() == false))
    {
      // throw something
    }
  else
    {
      this->class_name = (arg_json_value["class name"]).asString();
    }

  if ((arg_json_value["object id"].isNull() == true) ||
      (arg_json_value["object id"].isString() == false))
    {
      // throw something
    }
  else
    {
      this->object_id = (arg_json_value["object id"]).asString();
    }

  return true;
}
