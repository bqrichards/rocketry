//
// Created by Brandon Richards on 12/24/21.
//
#include <Arduino.h>
#include <unity.h>

#include "statemachine.h"
#include "states/state.h"

void test_interval() {
  State* states[] = {new State("1")};
  StateMachine stateMachine(states, 1);

  TEST_ASSERT_EQUAL_STRING("1", stateMachine.currentState()->getName().c_str());

  free(states[0]);
}

void test_advance() {
  State* states[] = {new State("1"), new State("2")};
  StateMachine stateMachine(states, 2);

  TEST_ASSERT_EQUAL_STRING("1", stateMachine.currentState()->getName().c_str());

  stateMachine.advance();

  TEST_ASSERT_EQUAL_STRING("2", stateMachine.currentState()->getName().c_str());

  free(states[0]);
  free(states[1]);
}

void test_advance_no_next_state() {
  //  State* states[] = {new State("1")};
  //  StateMachine stateMachine(states, 1);
  //
  //  // TODO - test for throw
  //  stateMachine.advance();
  //
  //  free(states[0]);

  TEST_FAIL_MESSAGE("Not implemented");
}

void test_has_next_state() {
  State* states[] = {new State("1"), new State("2")};
  StateMachine stateMachine(states, 2);

  TEST_ASSERT_TRUE(stateMachine.hasNextState());

  stateMachine.advance();

  TEST_ASSERT_FALSE(stateMachine.hasNextState());

  free(states[0]);
  free(states[1]);
}

void run_tests() {
  RUN_TEST(test_interval);
  RUN_TEST(test_advance);
  RUN_TEST(test_advance_no_next_state);
  RUN_TEST(test_has_next_state);
}

void setup() {
  UNITY_BEGIN();

  run_tests();

  UNITY_END();
}

void loop() {}
