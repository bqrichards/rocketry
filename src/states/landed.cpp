//
// Created by Brandon Richards on 12/7/21.
//

#include "landed.h"

StateLanded::StateLanded() : State("Landed") {}

void StateLanded::begin() { State::begin(); }

bool StateLanded::shouldAdvance(rocket_sensor_data *sensor_data,
                                unsigned long dt) {
  return State::shouldAdvance(sensor_data, dt);
}
