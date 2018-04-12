#include "src/drv/IMU.h"
//#include "src/drv/Encoders.h"
#include "src/drv/Motors.h"

IMU imu;
//Encoders encoders;
Motors motors;

void setup()
{
  imu.init();
}

void loop()
{
  //motors.set_voltages(2,2);
  imu.read();
  Serial.print("X: ");
  Serial.print(imu.a.x);
  Serial.print("  |  Y: ");
  Serial.print(imu.a.y);
  Serial.print("  |  Z: ");
  Serial.println(imu.a.z);
  delay(200);
}
