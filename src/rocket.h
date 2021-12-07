//
// Created by Brandon Richards on 12/6/21.
//

#ifndef ROCKETRY_ROCKET_H
#define ROCKETRY_ROCKET_H

#include "statemachine.h"
#include "states/groundIdle.h"
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>

class rocket {
public:
    rocket();

    /**
     * Update the rocket's state
     * @return whether the rocket is done executing
     */
    bool tick();

protected:
    /**
     * Update sensor events from sensors
     */
    void pollSensors();

    StateMachine stateMachine = StateMachine();
    Adafruit_BNO055 imu;
    Adafruit_BMP280 barometer;
    sensors_event_t orientation;
    sensors_event_t acceleration;
    double dt;
};


#endif //ROCKETRY_ROCKET_H
