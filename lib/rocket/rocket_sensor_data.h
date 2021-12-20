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
 * TODO add velocity
 */
typedef struct rocket_sensor_data {
  /**
   * Acceleration (m/s^2)
   */
  vector_3 acceleration = {};

  /**
   * Pressure (Pascals)
   */
  float pressure = 0;

  /**
   * Altitude (m)
   */
  float altitude = 0;

  /**
   * Temperature (celsius)
   */
  float temperature = 0;
} rocket_sensor_data;

#endif  // ROCKETRY_ROCKET_SENSOR_DATA_H
