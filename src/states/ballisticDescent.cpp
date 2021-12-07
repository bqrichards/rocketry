//
// Created by Brandon Richards on 12/7/21.
//

#include "ballisticDescent.h"

void StateBallisticDescent::begin() {
    State::begin();
}

bool StateBallisticDescent::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return State::shouldAdvance(orientation, acceleration, dt);
}
