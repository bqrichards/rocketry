//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_POWEREDFLIGHT_H
#define ROCKETRY_POWEREDFLIGHT_H

#include "state.h"
#include "../t_interval.h"

class StagePoweredFlight : public State {
 public:
  explicit StagePoweredFlight();

  /**
   * Called when the state is first loaded
   */
  void begin() override;

  /**
   * @return whether this state is finished and the next state should run
   */
  bool shouldAdvance(rocket_sensor_data *sensor_data,
                     unsigned long dt) override;

 private:
  float last_altitude = 0;

  t_interval altitude_check_interval = {0, 250};
};

#endif  // ROCKETRY_POWEREDFLIGHT_H
