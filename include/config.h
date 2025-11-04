#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

// Serial Configuration
#define SERIAL_BAUDRATE 115200
#define WAIT_FOR_SERIAL true

// LIS3DH Configuration
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
#define LIS3DH_CS 10

#define LIS3DH_I2C_ADDRESS 0x18

#endif // CONFIG_H