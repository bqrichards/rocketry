//
// Created by Brandon Richards on 12/7/21.
//

#include "unpoweredFlight.h"

StateUnpoweredFlight::StateUnpoweredFlight(String name) : State(name) {
}

void StateUnpoweredFlight::begin() {
	State::begin();
}

bool StateUnpoweredFlight::shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt) {
	return State::shouldAdvance(sensor_data, dt);
}
