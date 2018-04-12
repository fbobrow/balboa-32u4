#include "Motors.h"
#include "Arduino.h"

// Class constructor
Motors::Motors()
{
  // Initialize the digital pins as outputs
  pinMode(DIR_L, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  // Initialize direction and pwm variables
  _direction_left = 0;
  _direction_right = 0;
  _pwm_left = 0;
  _pwm_right = 0;
}
// Set the direction of a specific motor (left: motor = 0 / right: motor = 1)
void Motors::actuate()
{
  //
  digitalWrite(DIR_L, _direction_left);
  analogWrite(PWM_L, _pwm_left);
  digitalWrite(DIR_R, _direction_right);
  analogWrite(PWM_R, _pwm_right);
}
// Set direction of a specific motor (left: motor = 0 / right: motor = 1)
void Motors::set_direction(bool motor, bool direction)
{
  // Check
  if (motor == 0)
  {
    _direction_left = direction;
  }
  else if (motor == 1)
  {
    _direction_right = direction;
  }
  actuate();
}
// Set PWM of a specific motor (left: motor = 0 / right: motor = 1)
void Motors::set_pwm(bool motor, uint8_t pwm)
{
  // Check
  if (motor == 0)
  {
    _pwm_left = pwm;
  }
  else if (motor == 1)
  {
    _pwm_right = pwm;
  }
  actuate();
}
// Set voltage of a specific motor (left: motor = 0 / right: motor = 1)
void Motors::set_voltage(bool motor, float voltage)
{
  // Local auxiliary variable for direction
  bool direction = 0;
  // Local auxiliary variable for pwm
  uint8_t pwm;
  // If speed is negative, reverse the speed and change direction
  if (voltage < 0)
  {
    voltage = -voltage;
    direction = 1;
  }
  // If voltage is higher that the maximum allowed saturate the speed
  if (voltage > 9)
  {
    pwm = 9;
  }
  // Convert voltage into PWM value (assuming 9 volts is maximum value)
  pwm = voltage*(255/9.0);
  // Set the direction and PWM of this given motor
  set_direction(motor, direction);
  set_pwm(motor, pwm);
}
// Set voltages of both motors simultaneously
void Motors::set_voltages(float left_voltage, float right_voltage)
{
  set_voltage(0, left_voltage);
  set_voltage(1, right_voltage);
}
