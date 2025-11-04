# LIS3DH Lib

## Features

* Leichte C++-Wrapper-Klasse `LIS3DH` für den Adafruit LIS3DH Beschleunigungssensor
* Unterstützte Schnittstellen: I2C (Standard). I2C-Adresse konfigurierbar in `include/config.h` (Default: 0x18)
* Einfache Initialisierung über `begin()` mit Verfügbarkeitstest des Sensors
* Standard-Konfiguration: ±2g Range, 100 Hz Datenrate (gesetzt in `begin()`)
* Direkter Zugriff auf Roh-Beschleunigungswerte: `readAcceleration(float &x, float &y, float &z)` (Werte in m/s²)
* Berechnung der relativen Beschleunigung gegenüber der Erdbeschleunigung: `getRelativeAcceleration()`
* Einfache Bewegungserkennung: `isMoving(float threshold = 0.5)` (konfigurierbarer Schwellenwert in m/s²)

## Benötigte Lib

```
adafruit/Adafruit LIS3DH@^1.3.0
```