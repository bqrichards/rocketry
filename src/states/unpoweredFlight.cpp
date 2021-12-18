//
// Created by Brandon Richards on 12/7/21.
//

#include "unpoweredFlight.h"

StateUnpoweredFlight::StateUnpoweredFlight() : State("Unpowered Flight") {}

void StateUnpoweredFlight::begin() { State::begin(); }

bool StateUnpoweredFlight::shouldAdvance(rocket_sensor_data *sensor_data,
                                         unsigned long dt) {
  return State::shouldAdvance(sensor_data, dt);
}
