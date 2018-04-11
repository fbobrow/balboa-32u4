#include "src/drv/Motors.h"
#include "src/drv/IMU.h"

Motors motors;
IMU imu;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //motors.setSpeeds(50,0);
  Serial.println(imu.accel.x);
  delay(1000);
}
