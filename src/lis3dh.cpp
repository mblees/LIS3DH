#include "lis3dh.h"

LIS3DH::LIS3DH() {}

bool LIS3DH::begin() {
    if (!lis3dh.begin(LIS3DH_I2C_ADDRESS)) {
        Serial.println("Could not find LIS3DH sensor!");
        return false;
    }

    lis3dh.setRange(LIS3DH_RANGE_2_G);
    lis3dh.setDataRate(LIS3DH_DATARATE_100_HZ);

    Serial.println("LIS3DH initialized successfully!");
    return true;
}

void LIS3DH::readAcceleration(float &x, float &y, float &z) {
    sensors_event_t event;
    lis3dh.getEvent(&event);

    x = event.acceleration.x;
    y = event.acceleration.y;
    z = event.acceleration.z;
}

float LIS3DH::getRelativeAcceleration() {
    sensors_event_t event;
    lis3dh.getEvent(&event);
    float total_acc = sqrt(event.acceleration.x * event.acceleration.x +
                            event.acceleration.y * event.acceleration.y +
                            event.acceleration.z * event.acceleration.z);
    total_acc = fabs(total_acc - 9.81);
    return total_acc;
}

bool LIS3DH::isMoving(float threshold) {
    if (getRelativeAcceleration() > threshold) 
        return true;
    return false;
}