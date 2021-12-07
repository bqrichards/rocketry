//
// Created by Brandon Richards on 12/7/21.
//

#include "chuteDescent.h"

void StateChuteDescent::begin() {
    State::begin();
}

bool StateChuteDescent::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return State::shouldAdvance(orientation, acceleration, dt);
}
