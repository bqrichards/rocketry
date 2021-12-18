//
// Created by Brandon Richards on 12/17/21.
//

#include "telemetry.h"

void format_sensor_data_to_csv(rocket_sensor_data *data, std::string *out) {
  std::stringstream csv_stream;
  csv_stream << std::fixed << std::setprecision(2);
  csv_stream << data->acceleration.x << "," << data->acceleration.y << ","
             << data->acceleration.z << ",";
  csv_stream << data->pressure << "," << data->altitude << ","
             << data->temperature;
  *out = csv_stream.str();
}
