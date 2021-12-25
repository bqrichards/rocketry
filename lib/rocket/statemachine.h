//
// Created by Brandon Richards on 12/5/21.
//

#ifndef ROCKETRY_STATEMACHINE_H
#define ROCKETRY_STATEMACHINE_H

#include <stdint.h>

#include "states/state.h"

class StateMachine {
 public:
  /**
   * Create an empty state machine
   */
  StateMachine();

  /**
   * Create a state machine with an array of states and a count of states
   * @param states the array of states
   * @param state_count the number of states in <code>states</code>
   */
  StateMachine(State** states, uint8_t state_count);

  /**
   * Gets the current state of the state machine
   * @return current state
   */
  State* currentState();

  /**
   * Advance the state machine to the next state
   */
  void advance();

  /**
   * Gets if there is a state after this
   * @return if there is a state after this
   */
  [[nodiscard]] bool hasNextState() const;

 protected:
  State** states;
  uint8_t state_count = 0;
  uint8_t current_state = 0;
};

#endif  // ROCKETRY_STATEMACHINE_H
