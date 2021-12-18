//
// Created by Brandon Richards on 12/17/21.
//

#include "telemetry.h"

void format_sensor_data_to_csv(rocket_sensor_data *data, char *out) {
  // Clear string
  memset(out, 0, strlen(out));

  // Format data
  sprintf(out, "%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f", data->acceleration.x,
          data->acceleration.y, data->acceleration.z, data->pressure,
          data->altitude, data->temperature);
}
