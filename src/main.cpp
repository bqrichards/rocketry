#include <Arduino.h>
#include <Rocket.h>

void setup() {
  Serial.begin(9600);
  Rocket r;
  r.boot();
}

void loop() {
  // if (r.tick()) {
  //   exit(0);
  // }
}
