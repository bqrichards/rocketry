//
// Created by Brandon Richards on 12/24/21.
//

#include "test_state.h"

void test_get_name() {
  State state("State 1");

  TEST_ASSERT_EQUAL_STRING("State 1", state.getName().c_str());
}
