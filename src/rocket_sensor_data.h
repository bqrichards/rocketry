//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_ROCKET_SENSOR_DATA_H
#define ROCKETRY_ROCKET_SENSOR_DATA_H

#include <Adafruit_Sensor.h>

/**
 * Sensor data from IMU and barometric pressure sensor
 */
typedef struct rocket_sensor_data {
	/**
	 * Sensor data from IMU
	 */
	sensors_event_t imu;

	/**
	 * Sensor data from temperature sensor
	 */
	sensors_event_t temperature;

	/**
	 * Sensor data from barometer
	 */
	sensors_event_t altitude;
} rocket_sensor_data;

#endif//ROCKETRY_ROCKET_SENSOR_DATA_H
