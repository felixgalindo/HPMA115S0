/**
 * @file example.ino
 * @author Felix Galindo
 * @date June 2017
 * @brief Example using HPMA115S0 sensor library on a Feather 32u4
 * @license MIT
 */

 #include <HPMA115S0.h>
// #define hpmaSerial Serial1


 #include <SoftwareSerial.h>
SoftwareSerial hpmaSerial(10, 11); // Feather TX, Feather RX

//create an instance of the hpma115S0 library
HPMA115S0 hpma115S0(hpmaSerial);
 
void setup() {
  Serial.begin(57600);
  hpmaSerial.begin(9600); 
  delay(5000);
  Serial.println("Starting...");
  hpma115S0.Init();
  hpma115S0.StartParticleMeasurement();
}

void loop() {
  hpma115S0.ReadParticleMeasurement();
  delay(1000);
}