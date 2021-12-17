//
// Created by Brandon Richards on 12/6/21.
//

#include "rocket.h"

rocket::rocket() {
	// Initialize imu
	this->imu = Adafruit_BNO055(55);

	// Initialize barometer
	this->barometer = Adafruit_BMP280();

	// Create states
	this->states = new State* [6] {
		new StageGroundIdle("Ground Idle"),
				new StagePoweredFlight("Powered Flight"),
				new StateUnpoweredFlight("Unpowered Flight"),
				new StateBallisticDescent("Ballistic Descent"),
				new StateChuteDescent("Chute Descent"),
				new StateLanded("Landed")
	};

	// Create state machine
	this->stateMachine = StateMachine(this->states, 6);

	this->last_micro = micros();
}

bool rocket::tick() {
	this->update_time();
	this->poll_sensors();

	if (t_check(&this->telemetry_interval)) {
		this->send_telemetry();
		t_reset(&this->telemetry_interval);
	}

	bool stateDone = this->stateMachine.currentState()->shouldAdvance(this->sensor_data, this->dt);
	if (!stateDone) return false;

	if (this->stateMachine.hasNextState()) {
		this->stateMachine.advance();
	} else {
		return true;
	}
}

void rocket::update_time() {
	unsigned long now = micros();
	this->dt = now - this->last_micro;
	this->last_micro = now;
}

void rocket::poll_sensors() {
	if (t_check(&this->imu_interval)) {
		t_reset(&this->imu_interval);
		this->sensor_data.acceleration = this->imu.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
	}

	if (t_check(&this->barometer_interval)) {
		t_reset(&this->barometer_interval);
		this->sensor_data.temperature = this->barometer.readTemperature();
		this->sensor_data.altitude = this->barometer.readAltitude();
		this->sensor_data.pressure = this->barometer.readPressure();
	}
}

void rocket::send_telemetry() {
	// Format data
	memset(this->telemetry_message, 0, sizeof(this->telemetry_message));
	sprintf(this->telemetry_message, "%lu", this->last_micro);

	// Log data local
	Serial.println(this->telemetry_message);

	// TODO Send data remote
}
