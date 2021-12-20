//
// Created by Brandon Richards on 12/19/21.
//
#include <telemetry.h>
#include <unity.h>

char out[TELEMETRY_MESSAGE_SIZE];

void run_tests();
void test_empty_sensor_data() {
  rocket_sensor_data sensor_data;
  format_sensor_data_to_csv(&sensor_data, out);

  TEST_ASSERT_EQUAL_STRING("0.00,0.00,0.00,0.00,0.00,0.00", out);
}

void test_acceleration() {
  rocket_sensor_data sensor_data;
  sensor_data.acceleration.x = 0.72335392;
  sensor_data.acceleration.y = 0.1257192825;
  sensor_data.acceleration.z = 10.000000001;
  format_sensor_data_to_csv(&sensor_data, out);

  TEST_ASSERT_EQUAL_STRING("0.72,0.13,10.00,0.00,0.00,0.00", out);
}

void test_pressure() {
  rocket_sensor_data sensor_data;
  sensor_data.pressure = -0.35392;
  format_sensor_data_to_csv(&sensor_data, out);

  TEST_ASSERT_EQUAL_STRING("0.00,0.00,0.00,-0.35,0.00,0.00", out);
}

void test_altitude() {
  rocket_sensor_data sensor_data;
  sensor_data.altitude = 122.21;
  format_sensor_data_to_csv(&sensor_data, out);

  TEST_ASSERT_EQUAL_STRING("0.00,0.00,0.00,0.00,122.21,0.00", out);
}

void test_temperature() {
  rocket_sensor_data sensor_data;
  sensor_data.temperature = 30.99;
  format_sensor_data_to_csv(&sensor_data, out);

  TEST_ASSERT_EQUAL_STRING("0.00,0.00,0.00,0.00,0.00,30.99", out);
}

void test_all() {
  rocket_sensor_data sensor_data;
  sensor_data.acceleration.x = -1.112;
  sensor_data.acceleration.y = 1.916;
  sensor_data.acceleration.z = 6.431123;
  sensor_data.pressure = 10135.99;
  sensor_data.altitude = 4.2;
  sensor_data.temperature = 21.8;
  format_sensor_data_to_csv(&sensor_data, out);

  TEST_ASSERT_EQUAL_STRING("-1.11,1.92,6.43,10135.99,4.20,21.80", out);
}

void run_tests() {
  RUN_TEST(test_empty_sensor_data);
  RUN_TEST(test_acceleration);
  RUN_TEST(test_pressure);
  RUN_TEST(test_altitude);
  RUN_TEST(test_temperature);
  RUN_TEST(test_all);
}

int main() {
  UNITY_BEGIN();

  run_tests();

  UNITY_END();

  return 0;
}
