//
// Created by Brandon Richards on 12/7/21.
//

#include "landed.h"

StateLanded::StateLanded() : State(5) {}

void StateLanded::begin() { State::begin(); }

bool StateLanded::shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) { return true; }
