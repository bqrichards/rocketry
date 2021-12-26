#include "state.h"

State::State(uint8_t number) {
  this->number = number;
  Serial.print("Initialized state ");
  Serial.println(number);
}

void State::begin() {
  Serial.print("Beginning state ");
  Serial.println(this->number);
}

bool State::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) { return false; }
