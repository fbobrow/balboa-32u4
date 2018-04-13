#ifndef Estimators_h
#define Estimators_h

#include "Arduino.h"

#define PONDERATION 0.02

class Estimators
{
  public:
    // Class constructor
    Estimators();
    // Initialize class
    void init(float a_x, float a_z, float g_y);
    // Estimate angle given accelerometer readings
    void estimate_angle_accelerometer(float a_x, float a_z);
    // Estimate angle given gyroscope reading
    void estimate_angle_gyroscope(float g_y);
    // Estimate angle given accelerometer and gyroscope readings
    void estimate_angle(float a_x, float a_z, float g_y);
    // 
    float angle;
  private:
    float _angle_accelerometer;
    float _angle_gyroscope;
    float _last_time;
};

#endif
