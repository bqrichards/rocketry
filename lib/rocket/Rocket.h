//
// Created by Brandon Richards on 12/6/21.
//

#ifndef ROCKETRY_ROCKET_H
#define ROCKETRY_ROCKET_H

#include <SPI.h>

#include "Adafruit_BMP280.h"
#include "Adafruit_BNO055.h"
#include "RH_RF22.h"
#include "statemachine.h"
#include "states/states.h"
#include "t_interval.h"
#include "telemetry.h"

#define NUM_ROCKET_STAGES 6

class Rocket {
 public:
  Rocket();

  /**
   * Begins sensor boot
   */
  void boot();

  /**
   * Update the rocket's state
   * @return whether the rocket is done executing
   */
  bool tick();

 protected:
  /**
   * Takes samples from altitude on launchpad and
   * sets the ground-level altitude
   */
  void calibrate_altitude();

  /**
   * Update sensor events from sensors
   */
  void poll_sensors();

  /**
   * Update dt and last_micro
   */
  void update_time();

  /**
   * Send data to telemetry
   */
  void send_telemetry();

  /**
   * The current telemetry message
   */
  String telemetry_message = "";

  /**
   * The interval to update the IMU
   */
  t_interval imu_interval = {0, 10};

  /**
   * The interval to update the bmp
   */
  t_interval barometer_interval = {0, 10};

  /**
   * The interval to send telemetry data
   */
  t_interval telemetry_interval = {0, 10};

  /**
   * Array of pointers to states of the rocket
   */
  State* states[NUM_ROCKET_STAGES];

  /**
   * The state machine of the rocket
   */
  StateMachine stateMachine = StateMachine();

  /**
   * IMU sensor
   */
  Adafruit_BNO055 imu;

  /**
   * Barometric pressure sensor
   */
  Adafruit_BMP280 bmp;

  /**
   * Telemetry radio.
   */
  RH_RF22* telemetry_radio;

  /**
   * Sensor data from all sensors
   */
  rocket_sensor_data sensor_data;

  /**
   * The delta time in microseconds since last tick
   */
  unsigned long dt = 0L;

  /**
   * The microsecond of the last tick
   */
  unsigned long last_micro = 0L;

  /**
   * The altitude of ground
   */
  float ground_altitude = 0;
};

#endif  // ROCKETRY_ROCKET_H
