//
// Created by Brandon Richards on 12/7/21.
//

#ifndef ROCKETRY_T_INTERVAL_H
#define ROCKETRY_T_INTERVAL_H

#include <Arduino.h>

/**
 * An interval.
 * @link
 * http://hwhacks.com/2016/05/08/scheduling-arduino-code-run-every-x-seconds/
 * @see t_check
 * @see t_reset
 */
typedef struct t_interval {
  unsigned long t_start;

  /**
   * The interval in milliseconds
   */
  unsigned long t_timeout;
} t_interval;

bool t_check(t_interval *interval);

void t_reset(t_interval *interval);

#endif  // ROCKETRY_T_INTERVAL_H
