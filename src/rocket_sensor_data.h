//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_ROCKET_SENSOR_DATA_H
#define ROCKETRY_ROCKET_SENSOR_DATA_H

typedef struct vector_3 {
  double x;
  double y;
  double z;
} vector_3;

/**
 * Sensor data from IMU and barometric pressure sensor
 */
typedef struct rocket_sensor_data {
  /**
   * Acceleration (m/s^2)
   */
  vector_3 acceleration = {};

  /**
   * Temperature (celsius)
   */
  float temperature = 0;

  /**
   * Altitude (m)
   */
  float altitude = 0;

  /**
   * Pressure (Pascals)
   */
  float pressure = 0;
} rocket_sensor_data;

#endif  // ROCKETRY_ROCKET_SENSOR_DATA_H
