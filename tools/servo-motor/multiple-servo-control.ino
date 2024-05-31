#include <Servo.h>

Servo servo1;
Servo servo2;

#define SERVO1_PIN 9 // Pin where the first servo motor is connected
#define SERVO2_PIN 10 // Pin where the second servo motor is connected

void setup() {
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
}

void loop() {
  servo1.write(90); // Move the first servo to 90 degrees
  servo2.write(90); // Move the second servo to 90 degrees
  delay(1000); // Wait for a second
  servo1.write(0); // Move the first servo to 0 degrees
  servo2.write(180); // Move the second servo to 180 degrees
  delay(1000); // Wait for a second
}
