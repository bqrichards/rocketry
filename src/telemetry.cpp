//
// Created by Brandon Richards on 12/17/21.
//

#include "telemetry.h"

void format_sensor_data_to_csv(rocket_sensor_data *data,
                               char out[TELEMETRY_MESSAGE_SIZE]) {
  // Clear string
  memset(out, 0, TELEMETRY_MESSAGE_SIZE * sizeof(char));

  // Format data
  sprintf(out, "%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f", data->acceleration.x,
          data->acceleration.y, data->acceleration.z, data->pressure,
          data->altitude, data->temperature);
}
