//
// Created by Brandon Richards on 12/17/21.
//

#include "telemetry.h"

#include <Arduino.h>

void format_sensor_data(rocket_sensor_data* data, String* out) {
  *out = String("SD[" + String(data->acceleration.x, 2) + "," + String(data->acceleration.y, 2) + "," +
                String(data->acceleration.z, 2) + "," + String(data->orientation.x, 2) + "," +
                String(data->orientation.y, 2) + "," + String(data->orientation.z, 2) + "," +
                String(data->orientation.w, 2) + "," + String(data->pressure, 2) + "," + String(data->altitude, 2) +
                "," + String(data->temperature, 2) + "]");
}

void format_sensor_status(SensorType sensor_type, SensorStatus status, String* out) {
  String sensor_name;
  switch (sensor_type) {
    case imu_sensor:
      sensor_name = "imu";
      break;
    case bmp_sensor:
      sensor_name = "bmp";
      break;
  }

  String sensor_status;
  switch (status) {
    case uninitialized:
      sensor_status = "uninitialized";
      break;
    case pending:
      sensor_status = "pending";
      break;
    case success:
      sensor_status = "success";
      break;
    case fail:
      sensor_status = "fail";
      break;
  }

  *out = String("SS[" + sensor_name + "," + sensor_status + "]");
}
