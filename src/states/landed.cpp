//
// Created by Brandon Richards on 12/7/21.
//

#include "landed.h"

StateLanded::StateLanded(String name) : State(name) {
}

void StateLanded::begin() {
	State::begin();
}

bool StateLanded::shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt) {
	return State::shouldAdvance(sensor_data, dt);
}
