#include "Arduino.h"
#include "IMU.h"

IMU::IMU()
{
  accel.x_raw = 12;
  accel.y_raw = 12;
  accel.z_raw = 12;
  accel.x = 123.45;
  accel.y = 123.45;
  accel.z = 123.45;
}
