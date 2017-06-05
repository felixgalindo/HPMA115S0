/**
 * @file example.ino
 * @author Felix Galindo
 * @date June 2017
 * @brief Example using HPMA115S0 sensor library on a Feather 32u4
 * @license MIT
 */

 #include <HPMA115S0.h>
 #include <SoftwareSerial.h>
SoftwareSerial hpmaSerial(5, 2); // RX, TX

//create an instance of the hpma115S0 library
HPMA115S0 hpma115S0(hpmaSerial);
 
void setup() {
  hpma115S0.Init();
  hpma115S0.StartParticleMeasurement();
}

void loop() {
  hpma115S0.Update();
  delay(1000);
}