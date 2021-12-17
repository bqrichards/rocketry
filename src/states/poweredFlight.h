//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_POWEREDFLIGHT_H
#define ROCKETRY_POWEREDFLIGHT_H

#include "state.h"

class StagePoweredFlight : public State {
public:
	explicit StagePoweredFlight(String name);

	/**
     * Called when the state is first loaded
     */
	void begin() override;

	/**
     * @return whether this state is finished and the next state should run
     */
	bool shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt) override;
};


#endif//ROCKETRY_POWEREDFLIGHT_H
