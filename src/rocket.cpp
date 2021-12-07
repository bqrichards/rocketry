//
// Created by Brandon Richards on 12/6/21.
//

#include "rocket.h"

rocket::rocket() {
    // Initialize imu
    this->imu = Adafruit_BNO055(55);

    // Initialize barometer
    this->barometer = Adafruit_BMP280();

    // Create states
    this->states = new State*[6]{
            new StageGroundIdle(),
            new StagePoweredFlight(),
            new StateUnpoweredFlight(),
            new StateBallisticDescent(),
            new StateChuteDescent(),
            new StateLanded()
    };

    // Create state machine
    this->stateMachine = StateMachine(this->states, 6);
}

bool rocket::tick() {
    this->pollSensors();

    bool stateDone = this->stateMachine.currentState()->shouldAdvance(this->orientation, this->acceleration, this->dt);
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

