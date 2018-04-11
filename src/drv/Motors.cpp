#include "Arduino.h"
#include "Motors.h"

#define DIR_L 16
#define PWM_L 10
#define DIR_R 15
#define PWM_R 9

Motors::Motors()
{
  // Initialize the digital pins as outputs
  pinMode(DIR_L, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(PWM_R, OUTPUT);
}

void Motors::setLeftSpeed(int speed)
{
  // Auxiliary variable for direction
  bool direction = 0;

  // If speed is negative, reverse the speed and change direction
  if (speed < 0)
  {
    speed = -speed;
    direction = 1;
  }

  // If speed is higher that the maximum allowed saturate the speed
  if (speed > 255)
  {
    speed = 255;
  }

  // Actuate motor with given speed and calculated direction
  digitalWrite(DIR_L, direction);
  analogWrite(PWM_L, speed);
}

void Motors::setRightSpeed(int speed)
{
  // Auxiliary variable for direction
  bool direction = 0;

  // If speed is negative, reverse the speed and change direction
  if (speed < 0)
  {
    speed = -speed;
    direction = 1;
  }

  // If speed is higher that the maximum allowed saturate the speed
  if (speed > 255)
  {
    speed = 255;
  }

  // Actuate motor with given speed and calculated direction
  digitalWrite(DIR_R, direction);
  analogWrite(PWM_R, speed);
}

void Motors::setSpeeds(int leftSpeed, int rightSpeed)
{
  // Actuate left motor with given speed
  setLeftSpeed(leftSpeed);
  // Actuate right motor with given speed
  setRightSpeed(rightSpeed);
}
