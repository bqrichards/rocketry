//
// Created by Brandon Richards on 12/7/21.
//

#include "landed.h"

void StateLanded::begin() {
    State::begin();
}

bool StateLanded::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return State::shouldAdvance(orientation, acceleration, dt);
}
