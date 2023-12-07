
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

#include "Core.h"

using namespace std;

class GPS_DD : public Core
{
 private:
 protected:
 public:
  double latitude;
  double longitude;

  GPS_DD();
  GPS_DD(double, double);
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  bool operator==(GPS_DD& another);
  
  virtual Json::Value dump2JSON(void);
  virtual bool JSON2Object(Json::Value);
};

#endif /* _GPS_H_ */
