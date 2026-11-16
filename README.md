# LIS3DH

[![Build](https://github.com/mblees/LIS3DH/actions/workflows/build.yml/badge.svg)](https://github.com/mblees/LIS3DH/actions/workflows/build.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

A small C++ wrapper around the [Adafruit LIS3DH](https://github.com/adafruit/Adafruit_LIS3DH)
library for the LIS3DH 3-axis accelerometer. It reduces setup to a single `begin()`
call and adds a simple orientation-independent motion check.
Works with PlatformIO and the Arduino IDE.

## Features

- One-call initialization over I²C with a presence check: `begin()` returns `false`
  if no sensor answers.
- Fixed default configuration: ±2 g range, 100 Hz data rate.
- Acceleration per axis in m/s²: `readAcceleration(x, y, z)`.
- Deviation of the total acceleration from standard gravity: `getRelativeAcceleration()`.
  It is ≈ 0 at rest no matter how the sensor is oriented.
- Motion detection with a configurable threshold: `isMoving(threshold)`.

## Installation

**PlatformIO**, in `platformio.ini`:

```ini
lib_deps =
    https://github.com/mblees/LIS3DH.git
```

The Adafruit dependencies are installed automatically.

**Arduino IDE:** *Sketch → Include Library → Add .ZIP Library…* with the
repository ZIP, then install *Adafruit LIS3DH* and *Adafruit Unified Sensor*
from the Library Manager.

## Usage

```cpp
#include <lis3dh.h>

LIS3DH sensor;

void setup() {
  Serial.begin(115200);
  if (!sensor.begin()) {           // or sensor.begin(0x19)
    Serial.println("LIS3DH not found");
    while (true) delay(1000);
  }
}

void loop() {
  float x, y, z;
  sensor.readAcceleration(x, y, z);  // m/s²

  if (sensor.isMoving(2.0)) {        // more than 2 m/s² away from 1 g
    Serial.println("moving");
  }
  delay(100);
}
```

A complete example is in [`examples/BasicDemo`](examples/BasicDemo/BasicDemo.ino).

## API

| Method | Returns |
|---|---|
| `bool begin(uint8_t address = 0x18)` | `true` if the sensor was found and configured |
| `void readAcceleration(float &x, float &y, float &z)` | acceleration per axis in m/s² |
| `float getRelativeAcceleration()` | \|‖a‖ − g\| in m/s² |
| `bool isMoving(float threshold = 0.5)` | `true` if `getRelativeAcceleration() > threshold` |

## Wiring

| LIS3DH | Microcontroller |
|---|---|
| VIN | 3V3 |
| GND | GND |
| SDA | I²C SDA |
| SCL | I²C SCL |
| SDO | GND → address `0x18` (default), 3V3 → `0x19` |

The default address can also be changed globally with `-D LIS3DH_I2C_ADDRESS=0x19`.

## License

[MIT](LICENSE)
