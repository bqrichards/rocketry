//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_ROCKET_SENSOR_DATA_H
#define ROCKETRY_ROCKET_SENSOR_DATA_H

typedef struct vector_3 {
  double x = 0;
  double y = 0;
  double z = 0;
} vector_3;

typedef struct vector_4 {
  double x = 0;
  double y = 0;
  double z = 0;
  double w = 0;
} vector_4;

/**
 * Sensor data from IMU and barometric pressure sensor
 */
typedef struct rocket_sensor_data {
  /**
   * Acceleration (m/s^2)
   */
  vector_3 acceleration = {};

  /**
   * Orientation (Quaternion)
   */
  vector_4 orientation = {};

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

enum SensorType { imu_sensor, bmp_sensor };

enum SensorStatus {
  /** Sensor is uninitialized */
  uninitialized = 6,

  /** Sensor is calibrating */
  pending = 7,

  /** Sensor failed to calibrate */
  fail = 8,

  /** Sensor succeeded in calibration */
  success = 9
};

#endif  // ROCKETRY_ROCKET_SENSOR_DATA_H
