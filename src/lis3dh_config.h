#ifndef _LIS3DH_CONFIG_H
#define _LIS3DH_CONFIG_H

#include <stdint.h>

// Default I2C address (SDO/SA0 pin low). Use 0x19 if SDO is pulled high.
// Can be overridden per call with begin(address) or globally with
// -D LIS3DH_I2C_ADDRESS=0x19 in the build flags.
#ifndef LIS3DH_I2C_ADDRESS
#define LIS3DH_I2C_ADDRESS 0x18
#endif

#endif // _LIS3DH_CONFIG_H
