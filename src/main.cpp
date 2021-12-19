#include <Arduino.h>

#include "Rocket.h"

Rocket r;

void setup() { r = Rocket(); }

void loop() {
  if (r.tick()) {
    exit(0);
  }
}
