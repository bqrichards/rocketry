//
// Created by Brandon Richards on 12/24/21.
//
#include "test_t_interval.h"

void test_interval() {
  t_interval interval = {0, 100};

  delay(25);

  TEST_ASSERT_FALSE(t_check(&interval));

  delay(25);

  TEST_ASSERT_FALSE(t_check(&interval));

  delay(100);

  TEST_ASSERT_TRUE(t_check(&interval));
}
