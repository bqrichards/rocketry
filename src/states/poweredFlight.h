//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_POWEREDFLIGHT_H
#define ROCKETRY_POWEREDFLIGHT_H

#include "state.h"

class StagePoweredFlight : public State {
public:
    /**
     * Called when the state is first loaded
     */
    void begin() override;

    /**
     * @return whether this state is finished and the next state should run
     */
    bool shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) override;
};


#endif //ROCKETRY_POWEREDFLIGHT_H
