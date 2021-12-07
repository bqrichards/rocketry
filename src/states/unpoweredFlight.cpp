//
// Created by Brandon Richards on 12/7/21.
//

#include "unpoweredFlight.h"

void StateUnpoweredFlight::begin() {
    State::begin();
}

bool StateUnpoweredFlight::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return State::shouldAdvance(orientation, acceleration, dt);
}
