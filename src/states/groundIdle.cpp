//
// Created by Brandon Richards on 12/6/21.
//

#include "groundIdle.h"

void StageGroundIdle::begin() {
    State::begin();
}

bool StageGroundIdle::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return State::shouldAdvance(orientation, acceleration, dt);
}
