//
// Created by Brandon Richards on 12/5/21.
//

#ifndef ROCKETRY_STATEMACHINE_H
#define ROCKETRY_STATEMACHINE_H

#include <stdint.h>
#include "states/state.h"

class StateMachine {
public:
    StateMachine();

    /**
     * Gets the current state of the state machine
     * @return current state
     */
    State currentState();

    /**
     * Advance the state machine to the next state
     */
    void advance();

    /**
     * Gets if there is a state after this
     * @return if there is a state after this
     */
    bool hasNextState();
};

#endif //ROCKETRY_STATEMACHINE_H
