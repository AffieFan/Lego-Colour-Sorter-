#include <Servo.h>
#include <Stepper.h>

// Servo setup
Servo servo1;
Servo servo2;

const int buttonPin = 7;
int buttonState = HIGH;
int lastButtonState = HIGH;
bool isMoving = true;

unsigned long lastServoMoveTime = 0;
unsigned long servoGoInterval = 500;   // Time to hold at 1552
unsigned long servoStopInterval = 1000; // Time to hold at 1500
bool servoToggle = false;

// Stepper setup
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  servo2.attach(2);
  servo1.attach(3);

  pinMode(buttonPin, INPUT_PULLUP);
  myStepper.setSpeed(5);  // RPM

  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  // Read button input
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastButtonState = reading;
    if (reading == LOW) {
      isMoving = !isMoving;
      Serial.println(isMoving ? "Movement Mode: Type 1 (Moving)" : "Movement Mode: Type 2 (Stopped)");
    }
  }

  if (isMoving) {
    // Stepper motor runs while active
    myStepper.step(5);  // Adjust step count as needed

    // Servo motion using millis
    unsigned long currentTime = millis();
    unsigned long currentInterval = servoToggle ? servoGoInterval : servoStopInterval;

    if (currentTime - lastServoMoveTime >= currentInterval) {
      lastServoMoveTime = currentTime;

      if (servoToggle) {
        Serial.println("Moving servos to 1552");
        servo1.writeMicroseconds(1552);
        servo2.writeMicroseconds(1552);
      } else {
        Serial.println("Moving servos to 1500");
        servo1.writeMicroseconds(1500);
        servo2.writeMicroseconds(1500);
      }

      servoToggle = !servoToggle;
    }
  } else {
    // Stop servos and stepper
    servo1.writeMicroseconds(1500);
    servo2.writeMicroseconds(1500);
  }

  // Debug
  Serial.print("Button State: ");
  Serial.println(reading);
}
