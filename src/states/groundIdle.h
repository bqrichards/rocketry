//
// Created by Brandon Richards on 12/6/21.
//

#ifndef ROCKETRY_GROUNDIDLE_H
#define ROCKETRY_GROUNDIDLE_H

#include "state.h"

class StageGroundIdle : public State {
public:
	explicit StageGroundIdle(String name);

	/**
     * Called when the state is first loaded
     */
	void begin() override;

	/**
     * @return whether this state is finished and the next state should run
     */
	bool shouldAdvance(rocket_sensor_data sensor_data, unsigned long dt) override;
};

#endif//ROCKETRY_GROUNDIDLE_H
