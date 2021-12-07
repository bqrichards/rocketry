#include <Arduino.h>
#include "src/rocket.h"

rocket r;

void setup() {
    r = rocket();
}

void loop() {
    if (r.tick()) {
        exit(0);
    }
}
