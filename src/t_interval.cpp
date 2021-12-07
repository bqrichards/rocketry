//
// Created by Brandon Richards on 12/7/21.
//

#include "t_interval.h"

bool t_check(t_interval* interval) {
	return millis() > (interval->t_start + interval->t_timeout);
}

void t_reset(t_interval* interval) {
	interval->t_start = millis();
}
