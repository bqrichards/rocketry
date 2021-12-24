//
// Created by Brandon Richards on 12/17/21.
//

#ifndef ROCKETRY_TELEMETRY_H
#define ROCKETRY_TELEMETRY_H

#include <Arduino.h>
#include <stdio.h>
#include <string.h>

#include "rocket_sensor_data.h"

/**
 * Formats rocket sensor data into CSV
 * @param data rocket sensor data
 * @param out the string to write
 */
void format_sensor_data_to_csv(rocket_sensor_data* data, String* out);

#endif  // ROCKETRY_TELEMETRY_H
