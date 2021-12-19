//
// Created by Brandon Richards on 12/17/21.
//

#ifndef ROCKETRY_TELEMETRY_H
#define ROCKETRY_TELEMETRY_H

#include <stdio.h>
#include <string.h>

#include "rocket_sensor_data.h"

#define TELEMETRY_MESSAGE_SIZE 150

/**
 * Formats rocket sensor data into CSV
 * @param data rocket sensor data
 * @param out the string to write
 */
void format_sensor_data_to_csv(rocket_sensor_data *data,
                               char out[TELEMETRY_MESSAGE_SIZE]);

#endif  // ROCKETRY_TELEMETRY_H
