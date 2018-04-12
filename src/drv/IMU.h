#ifndef IMU_h
#define IMU_h

#include "Arduino.h"

// IMU I2C address
#define I2C_ADDRESS 0x6B
// Accelerometer and gyroscope control registers addresses
#define CTRL1_XL 0x10
#define CTRL2_G 0x11
// Gyroscope output register addresses
#define OUTX_L_G 0x22
#define OUTX_H_G 0x23
#define OUTY_L_G 0x24
#define OUTY_H_G 0x25
#define OUTZ_L_G 0x26
#define OUTZ_H_G 0x27
// Accelerometer output register addresses
#define OUTX_L_XL 0x28
#define OUTX_H_XL 0x29
#define OUTY_L_XL 0x2A
#define OUTY_H_XL 0x2B
#define OUTZ_L_XL 0x2C
#define OUTZ_H_XL 0x2D

// Custom structure for storing multiple axis values
struct vector
{
  // Raw data provided by IMU (integer)
  int16_t x_raw;
  int16_t y_raw;
  int16_t z_raw;
  // SI data (float)
  float x;
  float y;
  float z;
  // Conversion ration from raw data (integer) to SI data (float)
};

class IMU
{
  public:
    // Class constructor
    IMU();
    // Write data into a specific register
    void write_register(uint8_t register_address, uint8_t data);
    // Read data from a specific register
    uint8_t read_register(uint8_t register_address);
    // Initialize class
    void init();
    // Read accelerometer data
    void read_accelerometer();
    // Read gyroscope data
    void read_gyroscope();
    // Read accelerometer and gyroscope data simultaneously
    void read();
    // Accelerometer data
    vector a;
    // Gyroscope data
    vector g;
  private:
    float _accelerometer_resolution;
    float _gyroscope_resolution;
};

#endif
