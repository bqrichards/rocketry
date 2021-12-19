//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_CHUTEDESCENT_H
#define ROCKETRY_CHUTEDESCENT_H

#include "state.h"

class StateChuteDescent : public State {
 public:
  explicit StateChuteDescent();

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
  const float ALTITUDE_LANDED_THRESHOLD = 5;

  const unsigned long LANDED_DURATION_THRESHOLD = 1000;

  unsigned long landed_started_millis = 0;
};

#endif  // ROCKETRY_CHUTEDESCENT_H
