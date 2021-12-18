//
// Created by Brandon Richards on 12/6/21.
//

#include "Rocket.h"

Rocket::Rocket() {
  // Initialize imu
  this->imu = Adafruit_BNO055(55);

  // Initialize barometer
  this->barometer = Adafruit_BMP280();

  // Create states
  this->states = new State *[6] {
    new StageGroundIdle(), new StagePoweredFlight(), new StateUnpoweredFlight(),
        new StateBallisticDescent(), new StateChuteDescent(), new StateLanded()
  };

  // Create state machine
  this->stateMachine = StateMachine(this->states, 6);

  this->last_micro = micros();
}

bool Rocket::tick() {
  this->update_time();
  this->poll_sensors();

  if (t_check(&this->telemetry_interval)) {
    this->send_telemetry();
    t_reset(&this->telemetry_interval);
  }

  bool stateDone = this->stateMachine.currentState()->shouldAdvance(
      &this->sensor_data, this->dt);
  if (!stateDone) return false;

  if (this->stateMachine.hasNextState()) {
    this->stateMachine.advance();
    return false;
  } else {
    return true;
  }
}

void Rocket::update_time() {
  unsigned long now = micros();
  this->dt = now - this->last_micro;
  this->last_micro = now;
}

void Rocket::poll_sensors() {
  if (t_check(&this->imu_interval)) {
    t_reset(&this->imu_interval);
    imu::Vector<3> data =
        this->imu.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
    this->sensor_data.acceleration.x = data.x();
    this->sensor_data.acceleration.y = data.y();
    this->sensor_data.acceleration.z = data.z();
  }

  if (t_check(&this->barometer_interval)) {
    t_reset(&this->barometer_interval);
    this->sensor_data.temperature = this->barometer.readTemperature();
    this->sensor_data.altitude = this->barometer.readAltitude();
    this->sensor_data.pressure = this->barometer.readPressure();
  }
}

void Rocket::send_telemetry() {
  // Format data
  format_sensor_data_to_csv(&this->sensor_data, &this->telemetry_message);

  // Log data local
  Serial.println(this->telemetry_message.c_str());

  // Send data remote
  this->radio.send(
      reinterpret_cast<const uint8_t *>(this->telemetry_message.c_str()),
      this->telemetry_message.length());
}
