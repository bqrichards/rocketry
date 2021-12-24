//
// Created by Brandon Richards on 12/24/21.
//

#ifndef RFCS_TEST_STATEMACHINE_H
#define RFCS_TEST_STATEMACHINE_H

#include <Arduino.h>
#include <statemachine.h>
#include <states/state.h>
#include <unity.h>

void test_current_state();
void test_advance();
void test_has_next_state();

#endif  // RFCS_TEST_STATEMACHINE_H
