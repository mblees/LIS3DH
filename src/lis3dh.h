#ifndef LIS3DH_H
#define LIS3DH_H

#include <Arduino.h>
#include "lis3dh_config.h"

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

class LIS3DH {
public:
    LIS3DH();

    // Initialises the sensor over I2C (±2 g, 100 Hz).
    // Returns false if no sensor answers at the given address.
    bool begin(uint8_t address = LIS3DH_I2C_ADDRESS);

    // Acceleration per axis in m/s².
    void readAcceleration(float &x, float &y, float &z);

    // Deviation of the total acceleration from standard gravity in m/s²
    // (~0 when the sensor is at rest, regardless of its orientation).
    float getRelativeAcceleration();

    // true if getRelativeAcceleration() exceeds threshold (m/s²).
    bool isMoving(float threshold = 0.5);

private:
    Adafruit_LIS3DH lis3dh;
};

#endif // LIS3DH_H
