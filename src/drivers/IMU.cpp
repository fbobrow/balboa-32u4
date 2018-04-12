#include "IMU.h"
#include "Arduino.h"
#include "Wire.h"

#define ADDRESS 0x6B

IMU::IMU()
{
  accel.x_raw = 0;
  accel.y_raw = 0;
  accel.z_raw = 0;
  accel.x = 0;
  accel.y = 0;
  accel.z = 0;
}

void IMU::init()
{
  //
  Wire.begin();
  // ODR = 1000 (1.66 kHz (high performance)); FS_XL = 00 (+/-2 g full scale)
  write_register(CTRL1_XL,0b10000000);
  // ODR = 1000 (1.66 kHz (high performance)); FS_G = 00 (+/-245 dps)
  write_register(CTRL2_G,0b10000000);
}

void IMU::write_register(uint8_t reg, uint8_t data)
{
  //
  Wire.beginTransmission(ADDRESS);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t IMU::read_register(uint8_t reg)
{
  //
  uint8_t value;
  //
  Wire.beginTransmission(ADDRESS);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS,1);
  value = Wire.read();
  Wire.endTransmission();
  //
  return value;
}

void IMU::read_accel()
{
  // Read two bytes (high and low) of accelerometer data (2 x 8 bit for each axis)
  uint8_t x_raw_l = read_register(OUTX_L_XL);
  uint8_t x_raw_h = read_register(OUTX_H_XL);
  uint8_t y_raw_l = read_register(OUTY_L_XL);
  uint8_t y_raw_h = read_register(OUTY_H_XL);
  uint8_t z_raw_l = read_register(OUTZ_L_XL);
  uint8_t z_raw_h = read_register(OUTZ_H_XL);
  // Combine high and low bytes into a single accelerometer data (16 bit for each axis)
  accel.x_raw = (int16_t)(x_raw_h << 8 | x_raw_l);
  accel.y_raw = (int16_t)(y_raw_h << 8 | y_raw_l);
  accel.z_raw = (int16_t)(z_raw_h << 8 | z_raw_l);
  // Convert raw data into SI units (m/s^2)
  accel.x = accel.x_raw*(0.061/1000.0)*(9.80665);
  accel.y = accel.y_raw*(0.061/1000.0)*(9.80665);
  accel.z = accel.z_raw*(0.061/1000.0)*(9.80665);
}

void IMU::read_gyro()
{
  // Read two bytes (high and low) of accelerometer data (2 x 8 bit for each axis)
  uint8_t x_raw_l = read_register(OUTX_L_G);
  uint8_t x_raw_h = read_register(OUTX_H_G);
  uint8_t y_raw_l = read_register(OUTY_L_G);
  uint8_t y_raw_h = read_register(OUTY_H_G);
  uint8_t z_raw_l = read_register(OUTZ_L_G);
  uint8_t z_raw_h = read_register(OUTZ_H_G);
  // Combine high and low bytes into a single accelerometer data (16 bit for each axis)
  gyro.x_raw = (int16_t)(x_raw_h << 8 | x_raw_l);
  gyro.y_raw = (int16_t)(y_raw_h << 8 | y_raw_l);
  gyro.z_raw = (int16_t)(z_raw_h << 8 | z_raw_l);
  // Convert raw data into SI units (m/s^2)
  gyro.x = gyro.x_raw*(4.375/1000.0)*(3.1415/180);
  gyro.y = gyro.y_raw*(4.375/1000.0)*(3.1415/180);
  gyro.z = gyro.z_raw*(4.375/1000.0)*(3.1415/180);
}

void IMU::read()
{
  read_accel();
  read_gyro();
}
