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
  //motors.set_voltages(2,2);
  Serial.println(imu.accel.x);
  delay(1000);
}
