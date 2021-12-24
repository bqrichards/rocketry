//
// Created by Brandon Richards on 12/24/21.
//
#include "test_state.h"
#include "test_statemachine.h"
#include "test_t_interval.h"
#include "test_telemetry.h"

void run_tests() {
  // State
  RUN_TEST(test_get_name);

  // State machine
  RUN_TEST(test_current_state);
  RUN_TEST(test_advance);
  RUN_TEST(test_has_next_state);

  // t_interval
  RUN_TEST(test_interval);

  // Telemetry
  RUN_TEST(test_empty_sensor_data);
  RUN_TEST(test_acceleration);
  RUN_TEST(test_orientation);
  RUN_TEST(test_pressure);
  RUN_TEST(test_altitude);
  RUN_TEST(test_temperature);
  RUN_TEST(test_all);
}

void setup() {
  UNITY_BEGIN();

  run_tests();

  UNITY_END();
}

void loop() {}
