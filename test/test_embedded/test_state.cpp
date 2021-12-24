//
// Created by Brandon Richards on 12/24/21.
//
#include <Arduino.h>
#include <unity.h>

#include "states/state.h"

void test_interval() {
  State state("State 1");

  TEST_ASSERT_EQUAL_STRING("State 1", state.getName().c_str());
}

void run_tests() { RUN_TEST(test_interval); }

void setup() {
  UNITY_BEGIN();

  run_tests();

  UNITY_END();
}

void loop() {}
