#include "src/drv/IMU.h"
//#include "src/drv/Encoders.h"
#include "src/drv/Motors.h"
#include "src/mod/Estimators.h"
#include "src/mod/Controllers.h"

IMU imu;
//Encoders encoders;
Motors motors;
Estimators estimators;
//Controllers controllers;

void setup()
{
  imu.init();
  imu.read();
  estimators.init(imu.a.x,imu.a.z,imu.g.y);
}

float angle;

void loop()
{
  //motors.set_voltages(2,2);
  imu.read();
  estimators.estimate_angle(imu.a.x,imu.a.z,imu.g.y);
  Serial.println(estimators.angle*180/PI);
  delay(100);
}
