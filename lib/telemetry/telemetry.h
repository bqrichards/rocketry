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
 * Formats sensor data
 * @param data rocket sensor data
 * @param out the string to write
 */
void format_sensor_data(rocket_sensor_data* data, String* out);

/**
 * Formats sensor status
 * @param sensor_type the sensor being reported on
 * @param sensor_status the sensor status
 * @param out the string to write
 */
void format_sensor_status(SensorType sensor_type, SensorStatus status, String* out);

/**
 * Format ground altitude message
 * @param calibrating
 * @param altitude
 */
void format_ground_altitude(bool calibrating, float altitude, String* out);

#endif  // ROCKETRY_TELEMETRY_H
