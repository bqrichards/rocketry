//
// Created by Brandon Richards on 12/24/21.
//

#include "test_statemachine.h"

void test_current_state() {
  State* states[] = {new State(1)};
  StateMachine stateMachine(states, 1);

  TEST_ASSERT_EQUAL(1, stateMachine.currentState()->getNumber());

  free(states[0]);
}

void test_advance() {
  State* states[] = {new State(1), new State(2)};
  StateMachine stateMachine(states, 2);

  TEST_ASSERT_EQUAL(1, stateMachine.currentState()->getNumber());

  stateMachine.advance();

  TEST_ASSERT_EQUAL(2, stateMachine.currentState()->getNumber());

  free(states[0]);
  free(states[1]);
}

void test_has_next_state() {
  State* states[] = {new State(1), new State(2)};
  StateMachine stateMachine(states, 2);

  TEST_ASSERT_TRUE(stateMachine.hasNextState());

  stateMachine.advance();

  TEST_ASSERT_FALSE(stateMachine.hasNextState());

  free(states[0]);
  free(states[1]);
}
