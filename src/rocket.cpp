//
// Created by Brandon Richards on 12/6/21.
//

#include "rocket.h"

rocket::rocket() {
    // TODO - initialize imu
    // TODO - initialize barometer

    // Create states
    State states[] = {
            StageGroundIdle()
    };

    // Create state machine
    this->stateMachine = StateMachine();
}

bool rocket::tick() {
    this->pollSensors();

    bool stateDone = this->stateMachine.currentState().shouldAdvance(this->orientation, this->acceleration, this->dt);
    if (stateDone) {
        if (this->stateMachine.hasNextState()) {
            this->stateMachine.advance();
        } else {
            return true;
        }
    }

    return false;
}

void rocket::pollSensors() {
    // TODO
}

