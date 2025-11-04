#include "main.h"

LIS3DH lis3dh;

void setup()
{
  Serial.begin(SERIAL_BAUDRATE);
#if WAIT_FOR_SERIAL
  while (!Serial)
#endif
  delay(2000); 
  Serial.println("Serial connected");
  lis3dh.begin();
}

void loop()
{
  float x, y, z;
  lis3dh.readAcceleration(x, y, z);
  float relAcc = lis3dh.getRelativeAcceleration();
  Serial.print(" | Relative Acceleration: "); 
  Serial.print(relAcc); 
  Serial.println(" m/s²");

  if (lis3dh.isMoving(2.0))
      Serial.println("Device is moving");

  delay(100);
}