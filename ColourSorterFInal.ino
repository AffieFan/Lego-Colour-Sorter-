#include <Servo.h>

// Defining color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Defining Servo
Servo myServo;
Servo secondServo;  // Second servo for rotating back and forth
#define SERVO_PIN 9   // Servo for color sorting
#define SECOND_SERVO_PIN 10  // Second servo for rotation

// Defining Pulse Width Variables
int RPW = 0;
int GPW = 0;
int BPW = 0;

// Calibration Values
int redMin = 20, redMax = 236;
int greenMin = 20, greenMax = 300;
int blueMin = 20, blueMax = 222;

// Variables for final color values
int redValue, greenValue, blueValue;

void setup() {
  // Setting up color sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Attach servos
  myServo.attach(SERVO_PIN);
  secondServo.attach(SECOND_SERVO_PIN);

  // Set initial positions for both servos
  myServo.write(90);  // Default neutral position for sorting servo
  secondServo.write(0);  // Start position for the second servo

  Serial.begin(9600);
}

void loop() {
  // Read color values
  RPW = readRed();
  GPW = readGreen();
  BPW = readBlue();
  delay(200);

  Serial.print("Red = "); Serial.println(RPW);
  Serial.print("Green = "); Serial.println(GPW);
  Serial.print("Blue = "); Serial.println(BPW);

  // Determine color and move servo
  moveServoBasedOnColor(RPW, GPW, BPW);

  // Rotate second servo 180° and back every 10 seconds
  moveSecondServo();
}

void moveServoBasedOnColor(int r, int g, int b) {
  if (r > g && r > b) {
    Serial.println("Detected: Red");
    myServo.write(20);  // Move to red compartment
  } 
  else if (g > r && g > b) {
    Serial.println("Detected: Green");
    myServo.write(60);  // Move to green compartment
  } 
  else if (b > r && b > g) {
    Serial.println("Detected: Blue");
    myServo.write(100); // Move to blue compartment
  } 
  else if (r > 100 && g > 100 && b < 80) {  // Yellow detection
    Serial.println("Detected: Yellow");
    myServo.write(140); // Move to yellow compartment
  } 
  else {
    Serial.println("Detected: Miscellaneous");
    myServo.write(180); // Move to miscellaneous compartment
  }
}

void moveSecondServo() {
  secondServo.write(180);  // Rotate 180° clockwise
  delay(4000);  // Wait for 1 second at 180°
  secondServo.write(0);  // Rotate back to 0°
  delay(4000);  // Wait for 1 second at 0°
}

int readRed() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  return pulseIn(sensorOut, LOW);
}

int readGreen() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}

int readBlue() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  return pulseIn(sensorOut, LOW);
}
