#include "statemachine.h"

StateMachine::StateMachine() {
	this->states = new State*[0];
	this->state_count = 0;
}

StateMachine::StateMachine(State** states, uint8_t state_count) {
	this->states = states;
	this->state_count = state_count;
}

State* StateMachine::currentState() {
	return this->states[this->current_state];
}

void StateMachine::advance() {
	this->current_state++;
	this->states[this->current_state]->begin();
}

bool StateMachine::hasNextState() const {
	return this->current_state < (this->state_count - 1);
}
