//
// Created by Brandon Richards on 12/7/21.
//

#include "poweredFlight.h"

StagePoweredFlight::StagePoweredFlight(String name) : State(name) {
}

void StagePoweredFlight::begin() {
    State::begin();
}

bool StagePoweredFlight::shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt) {
    return State::shouldAdvance(sensor_data, dt);
}
