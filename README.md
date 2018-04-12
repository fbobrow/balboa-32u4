# Balboa 32U4

Algorithm to control the mobile inverted pendulum Pololu Balboa 32U4 containing:

* C++ libraries (./src/drv) to access the on-board hardware

* C++ libraries (./src/mod) with estimator and control algorithms

## Folder description:
```
./                        | Root
 balboa-32u4.ino          | Main program
 + src                    | Source files
 |  + drv                 | Drivers files
    |   Encoders.h        | Encoders header
    |   Encoders.cpp      | Encoders source code
    |   IMU.h             | IMU header
    |   IMU.cpp           | IMU source code
    |   Motors.h          | Motors header
    |   Motors.cpp        | Motors source code
 |  + mod                 | Modules files
    |   Estimator.h       | Estimator header
    |   Estimator.cpp     | Estimator source code
    |   Controller.h      | Controller header
    |   Controller.cpp    | Controller source code
```
