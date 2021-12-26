//
// Created by Brandon Richards on 12/5/21.
//

#ifndef ROCKETRY_STATE_H
#define ROCKETRY_STATE_H

#include <Arduino.h>
#include <stdint.h>

#include "Adafruit_Sensor.h"
#include "rocket_sensor_data.h"

class State {
 public:
  /**
   * A normal state.
   * @param state_number the number of the state
   */
  explicit State(uint8_t state_number);

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
  [[nodiscard]] virtual bool shouldAdvance(rocket_sensor_data* sensor_data, unsigned long dt);

  uint8_t getNumber() { return number; }

 protected:
  /**
   * Number of the state
   */
  uint8_t number;
};

#endif  // ROCKETRY_STATE_H
