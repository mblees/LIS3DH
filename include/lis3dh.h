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
    bool begin();
    void readAcceleration(float &x, float &y, float &z);
    float getRelativeAcceleration();
    bool isMoving(float threshold = 0.5);

private:
    Adafruit_LIS3DH lis3dh;
};

#endif // LIS3DH_H
