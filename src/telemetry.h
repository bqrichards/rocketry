//
// Created by Brandon Richards on 12/17/21.
//

#ifndef ROCKETRY_TELEMETRY_H
#define ROCKETRY_TELEMETRY_H

#include <cstdio>
#include <cstring>

#include "rocket_sensor_data.h"

/**
 * Formats rocket sensor data into CSV
 * @param data rocket sensor data
 * @param out the string to write
 */
void format_sensor_data_to_csv(rocket_sensor_data *data, char *out);

#endif  // ROCKETRY_TELEMETRY_H
