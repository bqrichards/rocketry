//
// Created by Brandon Richards on 12/6/21.
//

#ifndef ROCKETRY_ROCKET_H
#define ROCKETRY_ROCKET_H

#include "statemachine.h"
#include "states/states.h"
#include "rocket_sensor_data.h"
#include "t_interval.h"
#include <Adafruit_BNO055.h>
#include <Adafruit_BMP280.h>

class rocket {
public:
    rocket();

    /**
     * Update the rocket's state
     * @return whether the rocket is done executing
     */
    bool tick();

protected:
    /**
     * Update sensor events from sensors
     */
    void poll_sensors();

	/**
	 * Update dt and last_micro
	 */
	void update_time();

	/**
	 * Send data to telemetry
	 */
	void send_telemetry();

	/**
	 * The current telemetry message
	 */
	char telemetry_message[200] = "";

	/**
	 * The interval to update the IMU
	 */
	t_interval imu_interval = {0, 10};

	/**
	 * The interval to update the barometer
	 */
	t_interval barometer_interval = {0, 10};

	/**
	 * The interval to send telemetry data
	 */
	t_interval telemetry_interval = {0, 10};

	/**
	 * Array of pointers to states of the rocket
	 */
    State** states;

	/**
	 * The state machine of the rocket
	 */
    StateMachine stateMachine = StateMachine();

	/**
	 * IMU sensor
	 */
    Adafruit_BNO055 imu;

	/**
	 * Barometric pressure sensor
	 */
    Adafruit_BMP280 barometer;

	/**
	 * Sensor data from all sensors
	 */
	rocket_sensor_data sensor_data = {
			{},
			{},
			{}
	};

	/**
	 * The delta time in microseconds since last tick
	 */
    unsigned long dt = 0L;

	/**
	 * The microsecond of the last tick
	 */
	unsigned long last_micro = 0L;


};


#endif //ROCKETRY_ROCKET_H
