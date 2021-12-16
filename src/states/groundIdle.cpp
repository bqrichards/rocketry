//
// Created by Brandon Richards on 12/6/21.
//

#include "groundIdle.h"

StageGroundIdle::StageGroundIdle(String name) : State(name) {
}

void StageGroundIdle::begin() {
	State::begin();
}

bool StageGroundIdle::shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt) {
	return State::shouldAdvance(sensor_data, dt);
}
