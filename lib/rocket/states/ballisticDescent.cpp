//
// Created by Brandon Richards on 12/7/21.
//

#include "ballisticDescent.h"

StateBallisticDescent::StateBallisticDescent() : State(3) {}

void StateBallisticDescent::begin() { State::begin(); }

bool StateBallisticDescent::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) {
  return State::shouldAdvance(sensor_data, dt);
}
