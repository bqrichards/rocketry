//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_ROCKET_SENSOR_DATA_H
#define ROCKETRY_ROCKET_SENSOR_DATA_H

#include <Adafruit_Sensor.h>
#include "utility/vector.h"

/**
 * Sensor data from IMU and barometric pressure sensor
 */
typedef struct rocket_sensor_data {
	/**
	 * Acceleration (m/s^2)
	 */
	imu::Vector<3> acceleration = imu::Vector<3>();

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

#endif//ROCKETRY_ROCKET_SENSOR_DATA_H
