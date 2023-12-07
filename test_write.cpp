
#include "Labeled_GPS.h"
#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"

using namespace std;

int
main
(void)
{
  Labeled_GPS object_1001 { 38.672215864622636, -121.72280111121437, "Costco, Woodland" };

  std::cout << object_1001.dump2JSON() << std::endl;

  Json::Value json_object_1001 = object_1001.dump2JSON();
  char *fname_ptr = strdup("objects/Labeled_GPS_1001.json");

  int rc;
  rc = myJSON2File(fname_ptr, &json_object_1001);
  if (rc != 0)
    {
      std::cout << "error[" << rc << "] myJSON2File\n";
    }

  return 0;
}
