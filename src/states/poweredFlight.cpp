//
// Created by Brandon Richards on 12/7/21.
//

#include "poweredFlight.h"

StagePoweredFlight::StagePoweredFlight() : State("Powered Flight") {}

void StagePoweredFlight::begin() { State::begin(); }

bool StagePoweredFlight::shouldAdvance(rocket_sensor_data *sensor_data,
                                       unsigned long dt) {
  // Only check every 250 ms
  if (!t_check(&this->altitude_check_interval)) {
    return false;
  }

  t_reset(&this->altitude_check_interval);

  // Check if rocket is falling
  bool is_falling = sensor_data->altitude < this->last_altitude;
  this->last_altitude = sensor_data->altitude;

  return is_falling;
}
