/**
 *
 * @file HPMA115S0.h
 * @author Felix Galindo (felixgalindo91@gmail.com)
 * @date June 2017
 * @brief Arduino Library for Honeywell's Particle Sensor (HPMA115S0-XXX)
 *
 */

#ifndef HPMA115S0_H
#define HPMA115S0_H

#include "Arduino.h"

class HPMA115S0
{
public:
    /**
     * @brief Constructor for HPMA115S0 class
     * @param  a Stream ({Software/Hardware}Serial) object.
     * @note The serial stream should be already initialized
     * @return  void
     */
    HPMA115S0(Stream& serial);

    /**
     * @brief Function that initializes sensor
     * @return  a String containing sensor response
     */
    void Init();

    /**
     * @brief Function that starts sensor measurement
     * @return  void
     */
    void StartParticleMeasurement();
    /**
     * @brief Function that stops sensor measurement
     * @return  void
     */
    void StopParticleMeasurement();

    /**
     * @brief Function that enables auto send
     * @return  void
     */
    void EnableAutoSend();

    /**
     * @brief Function that stops auto send
     * @return  void
     */
    void DisableAutoSend();

    /**
     * @brief Function that reads serial data and updates measurements
     * @return  void
     */
    void Update();

    /**
    * @brief Function that returns the latest PM 2.5 reading
    * @note Sensor reports new reading ~ every 1 sec.
    * @return  PM 2.5 reading (float)
    */
    float GetPM2_5();

    /**
    * @brief Function that returns the latest PM 10 reading
    * @note Sensor reports new reading ~ every 1 sec.
    * @return  PM 10 reading (float)
    */
    float GetPM10();

private:
    Stream& _serial;

    //Latest PM 2.5 reading
    float _pm2_5 = 0;

    //Latest PM 10 reading
    float _pm10 = 0;

    /**
     * @brief Function that sends serial command to sensor
     * @param  a char * containing the command
     * @param size of buffer
     * @return  a String containing sensor response
     */
    String SendCmd(char * command, unsigned int size);
};

#endif
