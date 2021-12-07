//
// Created by Brandon Richards on 12/6/21.
//

#ifndef ROCKETRY_GROUNDIDLE_H
#define ROCKETRY_GROUNDIDLE_H

#include "state.h"

class StageGroundIdle : public State {
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

#endif //ROCKETRY_GROUNDIDLE_H
