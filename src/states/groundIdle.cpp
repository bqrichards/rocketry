//
// Created by Brandon Richards on 12/6/21.
//

#include "groundIdle.h"

StageGroundIdle::StageGroundIdle() : State("Ground Idle") {
}

void StageGroundIdle::begin() {
	State::begin();
}

bool StageGroundIdle::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) {
	bool isAccelerating = sensor_data->acceleration.z >= this->ACCELERATION_THRESHOLD;
	if (!isAccelerating) {
		accelerationStartedMillis = millis();
		return false;
	}

	unsigned long now = millis();

	// Check if we've been accelerating for longer than threshold
	return (now - accelerationStartedMillis) >= ACCELERATION_DURATION_THRESHOLD;
}
