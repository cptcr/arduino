#include <Servo.h>

Servo myServo;

#define SERVO_PIN 9 // Pin where the servo motor is connected

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  myServo.write(90); // Move the servo to 90 degrees
  delay(1000); // Wait for a second
  myServo.write(0); // Move the servo to 0 degrees
  delay(1000); // Wait for a second
  myServo.write(180); // Move the servo to 180 degrees
  delay(1000); // Wait for a second
}
