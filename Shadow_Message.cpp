
#include "Shadow_Message.h"
#include "ecs36b_Exception.h"

// JSON RPC part
#include "poclient.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

Shadow_Message::Shadow_Message
(std::string arg_host_url, std::string arg_class_id, std::string arg_object_id)
{
  this->host_url = arg_host_url;
  this->class_id = arg_class_id;
  this->object_id = arg_object_id;
  std::cout << "Shadow_Message Object created" << std::endl;
}

Json::Value
Shadow_Message::dump2JSON()
{
  HttpClient httpclient((this->host_url).c_str());
  poClient myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value result;

  try {
    result = myClient.dump2JSON("dump2JSON", (this->class_id).c_str(),
				(this->object_id).c_str());
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  
  return result;
}

bool
Shadow_Message::send
(Json::Value arg_message_json)
{
  HttpClient httpclient((this->host_url).c_str());
  poClient myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value result;
  Json::Value exception_json;

  result = myClient.send("send", (this->class_id).c_str(),
			 arg_message_json, (this->object_id).c_str());

  if ((result["status"]).isNull())
    {
      exception_json["status"] = "failed";
      exception_json["reason"] = "RPC response without status";
      throw ecs36b_Exception { exception_json };
    }
  else
    {
      if ((result["status"]).asString() == "failed")
	{
	  throw ecs36b_Exception { result };
	}
    }

  bool res;
  if ((result["result"].isNull() == true) ||
      (result["result"].isBool() != true))
    {
      res = false;
    }
  else
    {
      res = result["result"].asBool();
    }
  
  return res;
}

