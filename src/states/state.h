//
// Created by Brandon Richards on 12/5/21.
//

#ifndef ROCKETRY_STATE_H
#define ROCKETRY_STATE_H

#include <stdint.h>
#include <Adafruit_Sensor.h>

class State {
public:
    /**
     * Called when the state is first loaded
     */
    virtual void begin();

    /**
     * @return whether this state is finished and the next state should run
     */
    virtual bool shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt);

    /**
     * The frequency in milliseconds that the state wants the IMU to be sampled.
     * @default 10
     * @return milliseconds
     */
    virtual uint16_t imuSampleRate();
};

#endif //ROCKETRY_STATE_H
