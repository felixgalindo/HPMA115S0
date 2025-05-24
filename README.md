
# HPMA115S0

Simple Arduino-compatible C++ library for the Honeywell HPMA115S0 particulate matter sensor.

## Overview

The **HPMA115S0** library enables straightforward communication with the Honeywell HPMA115S0 PM2.5 sensor via UART. It provides basic functions to:

- Initialize the sensor
- Start and stop measurements
- Read particle concentration data
- Reset the sensor if needed

## Example

A typical usage example:

```cpp
#include <HPMA115S0.h>

HPMA115S0 sensor(Serial1);

void setup() {
  Serial.begin(9600);
  sensor.begin();
  sensor.startMeasurement();
}

void loop() {
  if (sensor.readParticleMeasurement()) {
    Serial.print("PM2.5: ");
    Serial.print(sensor.getPM2_5());
    Serial.print(" μg/m3 | PM10: ");
    Serial.print(sensor.getPM10());
    Serial.println(" μg/m3");
  }
  delay(1000);
}
```

## Installation

1. Clone the repository or download the ZIP.  
2. Add the library folder to your Arduino `libraries/` directory.  
3. Include it in your project with `#include <HPMA115S0.h>`.

## License

MIT License

---

Feel free to fork, contribute, or open issues!

---
