#ifndef Motors_h
#define Motors_h

#include "Arduino.h"

class Motors
{
  public:
    // Initialize class
    Motors();
    // Set left motor speed from -255 to 255 (lower or higher values will be saturated)
    void setLeftSpeed(int speed);
    // Set left motor speed from -255 to 255 (lower or higher values will be saturated)
    void setRightSpeed(int speed);
    // Set left and right motors speeds from -255 to 255 (lower or higher values will be saturated)
    void setSpeeds(int leftSpeed, int rightSpeed);
};

#endif



