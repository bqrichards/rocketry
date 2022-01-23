#include <Arduino.h>
#include <Rocket.h>

Rocket r;

void setup() {
  Serial.begin(9600);
  r.boot();
}

void loop() {
  if (r.tick()) {
    exit(0);
  }
}
