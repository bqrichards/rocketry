#include "state.h"

State::State(String name) {
	this->name = name;
}

void State::begin() {
	Serial.println("Beginning state " + this->name);
}

bool State::shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt) {
	char debugMessage[200];
	unsigned long now = micros();

	sprintf(debugMessage, "Advance %s - $lu", this->name.c_str(), now);
	Serial.println(debugMessage);

	return false;
}
