#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Adjust for your motor

// Define stepper motor pins
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  

void setup() {
  myStepper.setSpeed(10);  // Speed in RPM
}

void loop() {
  myStepper.step(stepsPerRevolution);  // Move forward
}