//
// Created by Brandon Richards on 12/7/21.
//

#include "chuteDescent.h"

StateChuteDescent::StateChuteDescent() : State(4) {}

void StateChuteDescent::begin() { State::begin(); }

bool StateChuteDescent::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) {
  bool landed = sensor_data->altitude < this->ALTITUDE_LANDED_THRESHOLD;

  if (!landed) {
    this->landed_started_millis = millis();
    return false;
  }

  unsigned long now = millis();

  // Check if we've been landed for longer than threshold
  return (now - this->landed_started_millis) >= this->LANDED_DURATION_THRESHOLD;
}
