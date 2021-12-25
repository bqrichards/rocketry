//
// Created by Brandon Richards on 12/6/21.
//

#include "Rocket.h"

Rocket::Rocket() {
  // Initialize IMU
  this->imu = Adafruit_BNO055(55);

  // Initialize bmp
  this->bmp = Adafruit_BMP280();

  // Initialize radio
  this->telemetry_radio = new RH_RF22(10, 3);

  // Create states
  this->states[0] = new StageGroundIdle();
  this->states[1] = new StagePoweredFlight();
  this->states[2] = new StateUnpoweredFlight();
  this->states[3] = new StateBallisticDescent();
  this->states[4] = new StateChuteDescent();
  this->states[5] = new StateLanded();

  // Create state machine
  this->stateMachine = StateMachine(this->states, 6);

  this->last_micro = micros();
}

void Rocket::boot() {
  Serial.begin(9600);

  if (!this->imu.begin()) {
    Serial.println("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    exit(1);
  }

  delay(1000);

  this->imu.setExtCrystalUse(true);

  if (!this->bmp.begin()) {
    Serial.println("Ooops, no BMP280 detected ... Check your wiring or I2C ADDR!");
    exit(1);
  }

  delay(1000);

  calibrate_altitude();
}

bool Rocket::tick() {
  this->update_time();
  this->poll_sensors();

  if (t_check(&this->telemetry_interval)) {
    t_reset(&this->telemetry_interval);
    this->send_telemetry();
  }

  bool stateDone = this->stateMachine.currentState()->shouldAdvance(&this->sensor_data, this->dt);
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
    imu::Vector<3> accel = this->imu.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
    imu::Quaternion quat = this->imu.getQuat();
    this->sensor_data.acceleration.x = accel.x();
    this->sensor_data.acceleration.y = accel.y();
    this->sensor_data.acceleration.z = accel.z();

    this->sensor_data.orientation.x = quat.x();
    this->sensor_data.orientation.y = quat.y();
    this->sensor_data.orientation.z = quat.z();
    this->sensor_data.orientation.w = quat.w();
  }

  if (t_check(&this->barometer_interval)) {
    t_reset(&this->barometer_interval);
    this->sensor_data.temperature = this->bmp.readTemperature();
    this->sensor_data.altitude = this->bmp.readAltitude();
    this->sensor_data.pressure = this->bmp.readPressure();
  }
}

void Rocket::send_telemetry() {
  // Format data
  format_sensor_data_to_csv(&this->sensor_data, &this->telemetry_message);

  // Log data local
  Serial.println(this->telemetry_message);

  // Send data remote
  this->telemetry_radio->send(reinterpret_cast<const uint8_t*>(this->telemetry_message.c_str()),
                              this->telemetry_message.length());
}

void Rocket::calibrate_altitude() {
  Serial.println("Calibrating altitude");

  // Measure average altitude on launchpad
  uint8_t sample_count = 50;
  float samples[sample_count];
  uint8_t i = 0;
  float total_altitude = 0;

  // TODO Use Chauvenet's criterion to detect outliers in data

  while (i < sample_count) {
    float alt = this->bmp.readAltitude();
    samples[i] = alt;
    total_altitude += alt;
    i++;
    delay(100);
  }

  this->ground_altitude = total_altitude / sample_count;

  Serial.print("Calibration done. Ground altitude: ");
  Serial.println(this->ground_altitude);
}
