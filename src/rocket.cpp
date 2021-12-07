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
    this->states = new State*[6]{
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

	// TODO - don't call as often
	this->poll_sensors();

    bool stateDone = this->stateMachine.currentState()->shouldAdvance(this->sensor_data, this->dt);
    if (stateDone) {
        if (this->stateMachine.hasNextState()) {
            this->stateMachine.advance();
        } else {
            return true;
        }
    }

    return false;
}

void rocket::update_time() {
	unsigned long now = micros();
	this->dt = now - this->last_micro;
	this->last_micro = now;
}

void rocket::poll_sensors() {
	this->imu.getEvent(&this->sensor_data.imu);
	this->barometer.getTemperatureSensor()->getEvent(&this->sensor_data.temperature);
	this->barometer.getPressureSensor()->getEvent(&this->sensor_data.altitude);
}
