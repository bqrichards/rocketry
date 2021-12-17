//
// Created by Brandon Richards on 12/7/21.
//

#include "chuteDescent.h"

StateChuteDescent::StateChuteDescent() : State("Chute Descent") {
}

void StateChuteDescent::begin() {
	State::begin();
}

bool StateChuteDescent::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) {
	return State::shouldAdvance(sensor_data, dt);
}
