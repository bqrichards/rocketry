//
// Created by Brandon Richards on 12/24/21.
//

#include "test_state.h"

void test_get_number() {
  State state(12);

  TEST_ASSERT_EQUAL(12, state.getNumber());
}
