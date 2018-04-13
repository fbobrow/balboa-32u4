#include "IMU.h"
#include "Arduino.h"
#include "Wire.h"

// Class constructor
IMU::IMU()
{
  // Initialize accelerometer data
  a.x_raw = 0;
  a.y_raw = 0;
  a.z_raw = 0;
  a.x_raw_bias = 0;
  a.y_raw_bias = 0;
  a.z_raw_bias = 0;
  a.x = 0.0;
  a.y = 0.0;
  a.z = 0.0;
  // Initialize gyroscope data
  g.x_raw = 0;
  g.y_raw = 0;
  g.z_raw = 0;
  g.x_raw_bias = 0;
  g.y_raw_bias = 0;
  g.z_raw_bias = 0;
  g.x = 0.0;
  g.y = 0.0;
  g.z = 0.0;
}

// Write data into a specific register
void IMU::write_register(uint8_t register_address, uint8_t data)
{
  //
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(register_address);
  Wire.write(data);
  Wire.endTransmission();
}

// Read data from a specific register
uint8_t IMU::read_register(uint8_t register_address)
{
  //
  uint8_t data;
  //
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(register_address);
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADDRESS,1);
  data = Wire.read();
  Wire.endTransmission();
  //
  return data;
}

// Initialize class
void IMU::init()
{
  // Begin I2C comunication
  Wire.begin();
  // ODR = 1000 (1.66 kHz (high performance)); FS_XL = 00 (+/-2 g full scale)
  write_register(CTRL1_XL,0b10000000);
  // ODR = 1000 (1.66 kHz (high performance)); FS_G = 10 (+/-1000 dps)
  write_register(CTRL2_G,0b10000100);
  //
  delay(100);
  //
  int32_t x_raw_bias = 0;
  int32_t y_raw_bias = 0;
  int32_t z_raw_bias = 0;
  for(uint8_t i=0; i<100; i++)
  {
    read_gyroscope();
    x_raw_bias += g.x_raw;
    y_raw_bias += g.y_raw;
    z_raw_bias += g.z_raw;
    delay(1);
  }
  g.x_raw_bias = x_raw_bias/100;
  g.y_raw_bias = y_raw_bias/100;
  g.z_raw_bias = z_raw_bias/100;
}

// Read accelerometer data
void IMU::read_accelerometer()
{
  // Read two bytes (2 x 8 bit) of acellerometer data for each axis
  uint8_t x_raw_l = read_register(OUTX_L_XL);
  uint8_t x_raw_h = read_register(OUTX_H_XL);
  uint8_t y_raw_l = read_register(OUTY_L_XL);
  uint8_t y_raw_h = read_register(OUTY_H_XL);
  uint8_t z_raw_l = read_register(OUTZ_L_XL);
  uint8_t z_raw_h = read_register(OUTZ_H_XL);
  // Combine high and low bytes into a single (16 bit) acellerometer data for each axis
  a.x_raw = (int16_t)(x_raw_h << 8 | x_raw_l);
  a.y_raw = (int16_t)(y_raw_h << 8 | y_raw_l);
  a.z_raw = (int16_t)(z_raw_h << 8 | z_raw_l);
  // Convert raw data into SI units (m/s^2)
  a.x = a.x_raw*(0.061/1000.0)*(9.80665);
  a.y = a.y_raw*(0.061/1000.0)*(9.80665);
  a.z = a.z_raw*(0.061/1000.0)*(9.80665);
}

// Read gyroscope data
void IMU::read_gyroscope()
{
  // Read two bytes (2 x 8 bit) of gyroscope data for each axis
  uint8_t x_raw_l = read_register(OUTX_L_G);
  uint8_t x_raw_h = read_register(OUTX_H_G);
  uint8_t y_raw_l = read_register(OUTY_L_G);
  uint8_t y_raw_h = read_register(OUTY_H_G);
  uint8_t z_raw_l = read_register(OUTZ_L_G);
  uint8_t z_raw_h = read_register(OUTZ_H_G);
  // Combine high and low bytes into a single (16 bit) gyroscope data for each axis
  g.x_raw = (int16_t)(x_raw_h << 8 | x_raw_l);
  g.y_raw = (int16_t)(y_raw_h << 8 | y_raw_l);
  g.z_raw = (int16_t)(z_raw_h << 8 | z_raw_l);
  // Convert raw values into SI units (rad/s)
  g.x = (g.x_raw-g.x_raw_bias)*(17.5/1000.0)*(3.1415/180);
  g.y = (g.y_raw-g.y_raw_bias)*(17.5/1000.0)*(3.1415/180);
  g.z = (g.z_raw-g.z_raw_bias)*(17.5/1000.0)*(3.1415/180);
}

// Read accelerometer and gyroscope data simultaneously
void IMU::read()
{
  //
  read_accelerometer();
  read_gyroscope();
}
