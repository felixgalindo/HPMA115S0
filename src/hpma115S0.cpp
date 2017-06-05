/**
 * @file HPMA115S0.cpp
 * @author Felix Galindo
 * @date June 2017
 * @brief Arduino Library for Honeywell's Particle Sensor (HPMA115S0-XXX)
 *
 */

#include "Arduino.h"
#include "HPMA115S0.h"

extern "C" {
#include <string.h>
#include <stdlib.h>
}

/**
 * @brief Constructor for HPMA115S0 class
 * @param  a Stream ({Software/Hardware}Serial) object.
 * @note The serial stream should be already initialized
 * @return  void
 */
HPMA115S0::HPMA115S0(Stream& serial):
  _serial(serial)
{
  _serial.setTimeout(250);
}

/**
 * @brief Function that initializes sensor
 * @return  a String containing sensor response
 */
void HPMA115S0::Init() {
  Serial.println("PS: initializing...");
  StartParticleMeasurement();
  EnableAutoSend();
}

/**
 * @brief Function that sends serial command to sensor
 * @param  a char * containing the command
 * @param size of buffer
 * @return  a String containing sensor response
 */
String HPMA115S0::SendCmd(char * command, unsigned int size) {
  Serial.println("PS Cmd:" + command);
  while (_serial.available())
    _serial.read();

  unsigned int index = 0;
  for (index = 0; index < size; index++) {
    _serial.write(command[index]);
  }
  String ret = ""; //TODO: return response
  return ret;
}

/**
 * @brief Function that starts sensor measurement
 * @return  void
 */
void HPMA115S0::StartParticleMeasurement() {
  const char cmd[] = {0x68, 0x01, 0x01, 0x96};
  SendCmd(cmd, 4);
}

/**
 * @brief Function that stops sensor measurement
 * @return  void
 */
void HPMA115S0::StopParticleMeasurement() {
  const char cmd[] = {0x68, 0x01, 0x02, 0x95};
  SendCmd(cmd, 4);
}

/**
 * @brief Function that enables auto send
 * @return  void
 */
void HPMA115S0::EnableAutoSend() {
  const char cmd[] = {0x68, 0x01, 0x40, 0x57};
  SendCmd(cmd, 4);
}

/**
 * @brief Function that stops auto send
 * @return  void
 */
void HPMA115S0::DisableAutoSend() {
  const char cmd[] = {0x68, 0x01, 0x20, 0x77};
  SendCmd(cmd, 4);
}

/**
 * @brief Function that reads serial data and updates measurements
 * @return  void
 */
void HPMA115S0::Update() {
  int incomingByte = 0;   // for incoming serial data
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}
