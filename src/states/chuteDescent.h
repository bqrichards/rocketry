//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_CHUTEDESCENT_H
#define ROCKETRY_CHUTEDESCENT_H


#include "state.h"

class StateChuteDescent : public State {
public:
	explicit StateChuteDescent(String name);

	/**
     * Called when the state is first loaded
     */
	void begin() override;

	/**
     * @return whether this state is finished and the next state should run
     */
	bool shouldAdvance(rocket_sensor_data sensor_data, unsigned long dt) override;
};


#endif//ROCKETRY_CHUTEDESCENT_H
