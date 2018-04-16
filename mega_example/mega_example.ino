/**
 * @file example.ino
 * @author Felix Galindo
 * @edited by James Moessis
 * @date June 2017
 * @brief Example using HPMA115S0 sensor library on a Feather 32u4
 * @license MIT
 */

#include "Arduino.h"
#include <hpma115S0.h>

HPMA115S0 hpma115S0(Serial1);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(2000);
  Serial.println("Starting...");
  hpma115S0.Init();
  hpma115S0.StartParticleMeasurement();
}

void loop() {
  unsigned int pm2_5, pm10;
  if (hpma115S0.ReadParticleMeasurement(&pm2_5, &pm10)) {
  Serial.println("PM 2.5: " + String(pm2_5) + " ug/m3" );
  Serial.println("PM 10: " + String(pm10) + " ug/m3" );
  }
}
