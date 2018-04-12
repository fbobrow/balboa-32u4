#ifndef Motors_h
#define Motors_h

#include "Arduino.h"

class Motors
{
  public:
    // Initialize class
    Motors();
    // Actuate motors
    void actuate();
    // Set direction of a specific motor (left: motor = 0 / right: motor = 1)
    void set_direction(bool motor, bool direction);
    // Set PWM of a specific motor (left: motor = 0 / right: motor = 1)
    void set_pwm(bool motor, uint8_t pwm);
    // Set voltage of a specific motor (left: motor = 0 / right: motor = 1)
    void set_voltage(bool motor, float voltage);
    // Set voltages of both motors simultaneously
    void set_voltages(float left_voltage, float right_voltage);
  private:
    // Direction variables for local storage
    bool _direction_left;
    bool _direction_right;
    // PWM variables for local storage
    uint8_t _pwm_left;
    uint8_t _pwm_right;
};

#endif
