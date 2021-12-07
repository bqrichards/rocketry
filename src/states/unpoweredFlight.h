//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_UNPOWEREDFLIGHT_H
#define ROCKETRY_UNPOWEREDFLIGHT_H


#include "state.h"

class StateUnpoweredFlight : public State {
    /**
     * Called when the state is first loaded
     */
    void begin() override;

    /**
     * @return whether this state is finished and the next state should run
     */
    bool shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) override;
};


#endif //ROCKETRY_UNPOWEREDFLIGHT_H
