#include "IMU.h"
#include "Arduino.h"
#include "Wire.h"

#define address 0b1101011

IMU::IMU()
{
  accel.x_raw = 0;
  accel.y_raw = 0;
  accel.z_raw = 0;
  accel.x = 0;
  accel.y = 0;
  accel.z = 0;
}

void IMU::write_register(uint8_t reg, uint8_t data)
{
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t IMU::read_register(uint8_t reg)
{
  uint8_t value;

  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)1);
  value = Wire.read();
  Wire.endTransmission();

  return value;
}

void IMU::read_accel()
{
uint8_t xla = read_register(OUTX_L_XL);
uint8_t xha = read_register(OUTX_H_XL);
uint8_t yla = read_register(OUTY_L_XL);
uint8_t yha = read_register(OUTY_H_XL);
uint8_t zla = read_register(OUTZ_L_XL);
uint8_t zha = read_register(OUTZ_H_XL);

// combine high and low bytes
accel.x_raw = (int16_t)(xha << 8 | xla);
accel.y_raw = (int16_t)(yha << 8 | yla);
accel.z_raw = (int16_t)(zha << 8 | zla);
}
