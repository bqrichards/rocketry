//
// Created by Brandon Richards on 12/5/21.
//

#ifndef ROCKETRY_STATE_H
#define ROCKETRY_STATE_H

#include <stdint.h>
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "../rocket_sensor_data.h"

class State {
public:
	/**
	 * A normal state.
	 * @param name the name of the state
	 */
	explicit State(String name);

    /**
     * Called when the state is first loaded
     */
    virtual void begin();

	/**
	 * Update state
	 * @param sensor_data all sensor data
	 * @param dt the difference in time since last call in microseconds
	 * @return whether this state is finished and the next state should run
	 */
    [[nodiscard]] virtual bool shouldAdvance(const rocket_sensor_data sensor_data, unsigned long dt);

    /**
     * The frequency in milliseconds that the state wants the IMU to be sampled.
     * @default 10
     * @return milliseconds
     */
    [[nodiscard]] virtual uint16_t imuSampleRate();

protected:
	/**
	 * Name of the state
	 */
	String name;
};

#endif //ROCKETRY_STATE_H
