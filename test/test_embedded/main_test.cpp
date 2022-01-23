//
// Created by Brandon Richards on 12/24/21.
//
#include "test_state.h"
#include "test_statemachine.h"
#include "test_t_interval.h"
#include "test_telemetry.h"

void run_tests() {
  // State
  RUN_TEST(test_get_number);

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
  RUN_TEST(test_all_data);
  RUN_TEST(test_imu_status);
  RUN_TEST(test_bmp_status);
  RUN_TEST(test_ground_altitude_true);
  RUN_TEST(test_ground_altitude_false);
}

void setup() {
  UNITY_BEGIN();

  run_tests();

  UNITY_END();
}

void loop() {}
