#include "state.h"

void State::begin() {
    // TODO - print
}

bool State::shouldAdvance(sensors_event_t orientation, sensors_event_t acceleration, double dt) {
    return true;
}

uint16_t State::imuSampleRate() {
    return 10;
}

