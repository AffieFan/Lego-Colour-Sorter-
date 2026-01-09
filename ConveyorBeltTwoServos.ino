#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
    servo1.attach(1); 
    servo2.attach(2);  

}

void loop() {

    servo2.writeMicroseconds(1552);
    servo1.writeMicroseconds(1552);
    delay(500);
    servo2.writeMicroseconds(1500);
    servo1.writeMicroseconds(1500);
    delay(500);



}