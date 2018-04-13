#include "Estimators.h"
#include "Arduino.h"

Estimators::Estimators()
{
  angle = 0.0;
  _angle_accelerometer = 0.0;
  _angle_gyroscope = 0.0;
  _last_time = 0.0;
}
void Estimators::init(float a_x, float a_z, float g_y)
{
  //
  _last_time = millis()/1000.0;
  //
  estimate_angle_accelerometer(a_x,a_z);
  //
  angle = _angle_accelerometer;
}
//
void Estimators::estimate_angle_accelerometer(float a_x, float a_z)
{
  //
  _angle_accelerometer = atan2(a_z,a_x);
}
//
void Estimators::estimate_angle_gyroscope(float g_y)
{
  //
  float new_time;
  //
  new_time = millis()/1000.0;
  _angle_gyroscope = angle + g_y*(new_time-_last_time);
  //
  _last_time = new_time;
}
//
void Estimators::estimate_angle(float a_x, float a_z, float g_y)
{
  //
  estimate_angle_accelerometer(a_x,a_z);
  //
  estimate_angle_gyroscope(g_y);
  //
  angle = (PONDERATION)*_angle_accelerometer+(1-PONDERATION)*_angle_gyroscope;
}
