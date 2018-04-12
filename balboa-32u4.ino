#include "src/drv/Motors.h"
#include "src/drv/IMU.h"

Motors motors;
IMU imu;

void setup()
{
  imu.init();
}

void loop()
{
  //motors.set_voltages(2,2);
  imu.read();
  Serial.print("X: ");
  Serial.print(imu.accel.x);
  Serial.print("  |  Y: ");
  Serial.print(imu.accel.y);
  Serial.print("  |  Z: ");
  Serial.println(imu.accel.z);
  Serial.print("X: ");
  Serial.print(imu.gyro.x);
  Serial.print("  |  Y: ");
  Serial.print(imu.gyro.y);
  Serial.print("  |  Z: ");
  Serial.println(imu.gyro.z);
  Serial.println("");
  delay(1000);
}
