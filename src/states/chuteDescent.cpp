//
// Created by Brandon Richards on 12/7/21.
//

#include "chuteDescent.h"

StateChuteDescent::StateChuteDescent(String name) : State(name) {
}

void StateChuteDescent::begin() {
	State::begin();
}

bool StateChuteDescent::shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt) {
	return State::shouldAdvance(sensor_data, dt);
}
