//
// Created by Brandon Richards on 12/17/21.
//

#include "telemetry.h"

#include <Arduino.h>

void format_sensor_data_to_csv(rocket_sensor_data* data, String* out) {
  // Format data
  *out = String(
      String(data->acceleration.x, 2) + "," + String(data->acceleration.y, 2) +
      "," + String(data->acceleration.z, 2) + "," +
      String(data->orientation.x, 2) + "," + String(data->orientation.y, 2) +
      "," + String(data->orientation.z, 2) + "," +
      String(data->orientation.w, 2) + "," + String(data->pressure, 2) + "," +
      String(data->altitude, 2) + "," + String(data->temperature, 2));
}
