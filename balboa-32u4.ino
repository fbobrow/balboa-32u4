#include "src/drivers/Motors.h"
#include "src/drivers/IMU.h"

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
