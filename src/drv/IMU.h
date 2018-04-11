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
    {
      // Embedded functions configuration register
      FUNC_CFG_ACCESS   = 0x01,
      // FIFO configuration registers
      FIFO_CTRL1        = 0x06,
      FIFO_CTRL2        = 0x07,
      FIFO_CTRL3        = 0x08,
      FIFO_CTRL4        = 0x09,
      FIFO_CTRL5        = 0x0A,
      //
      ORIENT_CFG_G      = 0x0B,
      // INT1 pin control register
      INT1_CTRL         = 0x0D,
      // INT2 pin control register
      INT2_CTRL         = 0x0E,
      // Who I am ID
      WHO_AM_I          = 0x0F,
      // Accelerometer and gyroscope control registers
      CTRL1_XL          = 0x10,
      CTRL2_G           = 0x11,
      CTRL3_C           = 0x12,
      CTRL4_C           = 0x13,
      CTRL5_C           = 0x14,
      CTRL6_C           = 0x15,
      CTRL7_G           = 0x16,
      CTRL8_XL          = 0x17,
      CTRL9_XL          = 0x18,
      CTRL10_C          = 0x19,
      // Interrupts registers
      WAKE_UP_SRC       = 0x1B,
      TAP_SRC           = 0x1C,
      D6D_SRC           = 0x1D,
      // Status data register
      STATUS_REG        = 0x1E,
      // Temperature output data register
      OUT_TEMP_L        = 0x20,
      OUT_TEMP_H        = 0x21,
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
      // FIFO status registers
      FIFO_STATUS1      = 0x3A,
      FIFO_STATUS2      = 0x3B,
      FIFO_STATUS3      = 0x3C,
      FIFO_STATUS4      = 0x3D,
      // FIFO data output registers
      FIFO_DATA_OUT_L   = 0x3E,
      FIFO_DATA_OUT_H   = 0x3F,
      // Timestamp output registers
      TIMESTAMP0_REG    = 0x40,
      TIMESTAMP1_REG    = 0x41,
      TIMESTAMP2_REG    = 0x42,
      // Step counter timestamp registers
      STEP_TIMESTAMP_L  = 0x49,
      STEP_TIMESTAMP_H  = 0x4A,
      // Step counter output registers
      STEP_COUNTER_L    = 0x4B,
      STEP_COUNTER_H    = 0x4C,
      // Interrupt register
      FUNC_SRC          = 0x53,
      // Interrupt registers
      TAP_CFG           = 0x58,
      TAP_THS_6D        = 0x59,
      INT_DUR2          = 0x5A,
      WAKE_UP_THS       = 0x5B,
      WAKE_UP_DUR       = 0x5C,
      FREE_FALL         = 0x5D,
      MD1_CFG           = 0x5E,
      MD2_CFG           = 0x5F,
    };
    // Accelerometer readings
    vector accel;
    // Gyroscope readings
    vector gyro;
    // Initialize class
    IMU();

    void read_accel();
    void read_gyro();
    void read();
};

#endif
