#include <Arduino.h>
#include <Server.h>
#include "BRUSHLESS_MOTOR.h"

BrushlessMotor motor(2);

void setup() {
  // put your setup code here, to run once:
  motor.begin();
}

void loop() {
  motor.run();
  // put your main code here, to run repeatedly:
}
