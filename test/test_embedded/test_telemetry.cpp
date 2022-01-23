//
// Created by Brandon Richards on 12/19/21.
//

#include "test_telemetry.h"

String out;

void test_empty_sensor_data() {
  rocket_sensor_data sensor_data;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00]", out.c_str());
}

void test_acceleration() {
  rocket_sensor_data sensor_data;
  sensor_data.acceleration.x = 0.72335392;
  sensor_data.acceleration.y = 0.1257192825;
  sensor_data.acceleration.z = 10.000000001;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[0.72,0.13,10.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00]", out.c_str());
}

void test_orientation() {
  rocket_sensor_data sensor_data;
  sensor_data.orientation.x = 0.72335392;
  sensor_data.orientation.y = 0.1257192825;
  sensor_data.orientation.z = 10.000000001;
  sensor_data.orientation.w = 4.127145119;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[0.00,0.00,0.00,0.72,0.13,10.00,4.13,0.00,0.00,0.00]", out.c_str());
}

void test_pressure() {
  rocket_sensor_data sensor_data;
  sensor_data.pressure = -0.35392;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[0.00,0.00,0.00,0.00,0.00,0.00,0.00,-0.35,0.00,0.00]", out.c_str());
}

void test_altitude() {
  rocket_sensor_data sensor_data;
  sensor_data.altitude = 122.21;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,122.21,0.00]", out.c_str());
}

void test_temperature() {
  rocket_sensor_data sensor_data;
  sensor_data.temperature = 30.99;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,30.99]", out.c_str());
}

void test_all_data() {
  rocket_sensor_data sensor_data;
  sensor_data.acceleration.x = -1.112;
  sensor_data.acceleration.y = 1.916;
  sensor_data.acceleration.z = 6.431123;
  sensor_data.orientation.x = 1.1725123;
  sensor_data.orientation.y = 8.1761512;
  sensor_data.orientation.z = 7.151122;
  sensor_data.orientation.w = -0.17142;
  sensor_data.pressure = 10135.99;
  sensor_data.altitude = 4.2;
  sensor_data.temperature = 21.8;
  format_sensor_data(&sensor_data, &out);

  TEST_ASSERT_EQUAL_STRING("SD[-1.11,1.92,6.43,1.17,8.18,7.15,-0.17,10135.99,4.20,21.80]", out.c_str());
}

void test_imu_status() {
  format_sensor_status(imu_sensor, uninitialized, &out);
  TEST_ASSERT_EQUAL_STRING("SS[imu,uninitialized]", out.c_str());

  format_sensor_status(imu_sensor, pending, &out);
  TEST_ASSERT_EQUAL_STRING("SS[imu,pending]", out.c_str());

  format_sensor_status(imu_sensor, success, &out);
  TEST_ASSERT_EQUAL_STRING("SS[imu,success]", out.c_str());

  format_sensor_status(imu_sensor, fail, &out);
  TEST_ASSERT_EQUAL_STRING("SS[imu,fail]", out.c_str());
}

void test_bmp_status() {
  format_sensor_status(bmp_sensor, uninitialized, &out);
  TEST_ASSERT_EQUAL_STRING("SS[bmp,uninitialized]", out.c_str());

  format_sensor_status(bmp_sensor, pending, &out);
  TEST_ASSERT_EQUAL_STRING("SS[bmp,pending]", out.c_str());

  format_sensor_status(bmp_sensor, success, &out);
  TEST_ASSERT_EQUAL_STRING("SS[bmp,success]", out.c_str());

  format_sensor_status(bmp_sensor, fail, &out);
  TEST_ASSERT_EQUAL_STRING("SS[bmp,fail]", out.c_str());
}

void test_ground_altitude_false() {
  format_ground_altitude(false, 0, &out);
  TEST_ASSERT_EQUAL_STRING("GA[f,0]", out.c_str());
}

void test_ground_altitude_true() {
  format_ground_altitude(false, 291.711791, &out);
  TEST_ASSERT_EQUAL_STRING("GA[t,291.71]", out.c_str());
}
