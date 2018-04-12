#ifndef IMU_h
#define IMU_h

#include "Arduino.h"

class IMU
{
  public:
    // Custom structure
    struct vector
    {
      int16_t x_raw;
      int16_t y_raw;
      int16_t z_raw;
      float x;
      float y;
      float z;
    };
    // Register addresses (pages 38-40 from LSM6DS33 datasheet)
    enum reg_addr
    {// Accelerometer and gyroscope control registers
      CTRL1_XL          = 0x10,
      CTRL2_G           = 0x11,
      // Gyroscope output register
      OUTX_L_G          = 0x22,
      OUTX_H_G          = 0x23,
      OUTY_L_G          = 0x24,
      OUTY_H_G          = 0x25,
      OUTZ_L_G          = 0x26,
      OUTZ_H_G          = 0x27,
      // Accelerometer output register
      OUTX_L_XL         = 0x28,
      OUTX_H_XL         = 0x29,
      OUTY_L_XL         = 0x2A,
      OUTY_H_XL         = 0x2B,
      OUTZ_L_XL         = 0x2C,
      OUTZ_H_XL         = 0x2D,
    };
    // Accelerometer readings
    vector accel;
    // Gyroscope readings
    vector gyro;
    // Initialize class
    IMU();
    //
    void init();
    //
    void write_register(uint8_t reg, uint8_t data);
    //
    uint8_t read_register(uint8_t reg);
    //
    void read_accel();
    //
    void read_gyro();
    //
    void read();
};

#endif
