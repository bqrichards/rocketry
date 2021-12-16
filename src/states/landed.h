//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_LANDED_H
#define ROCKETRY_LANDED_H


#include "state.h"

class StateLanded : public State {
public:
	explicit StateLanded(String name);

	/**
     * Called when the state is first loaded
     */
	void begin() override;

	/**
     * @return whether this state is finished and the next state should run
     */
	bool shouldAdvance(rocket_sensor_data sensor_data, unsigned long dt) override;
};


#endif//ROCKETRY_LANDED_H
