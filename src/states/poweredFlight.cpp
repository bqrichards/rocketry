//
// Created by Brandon Richards on 12/7/21.
//

#include "poweredFlight.h"

void StagePoweredFlight::begin() {
    State::begin();
}

bool StagePoweredFlight::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return State::shouldAdvance(orientation, acceleration, dt);
}
