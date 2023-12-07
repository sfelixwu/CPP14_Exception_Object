
#include "Labeled_GPS.h"
#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"

using namespace std;

int
main
(void)
{
  Json::Value json_object_1001;
  
  char *fname_ptr = strdup("objects/Labeled_GPS_1001.json");

  int rc;
  rc = myFile2JSON(fname_ptr, &json_object_1001);
  if (rc != 0)
    {
      std::cout << "error[" << rc << "] myFile2JSON\n";
    }

  Labeled_GPS object_1001;
  if (object_1001.JSON2Object(json_object_1001) != true)
    {
      std::cout << "error JSON2Object\n";
    }

  std::cout << object_1001.dump2JSON() << std::endl;

  return 0;
}
