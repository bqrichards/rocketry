//
// Created by Brandon Richards on 12/7/21.
//

#include "poweredFlight.h"

StagePoweredFlight::StagePoweredFlight() : State("Powered Flight") {
}

void StagePoweredFlight::begin() {
	State::begin();
}

bool StagePoweredFlight::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) {
	return State::shouldAdvance(sensor_data, dt);
}
