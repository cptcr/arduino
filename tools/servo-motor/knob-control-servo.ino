#include <Servo.h>

Servo myServo;

#define SERVO_PIN 9
#define POT_PIN A0 // Pin where the potentiometer is connected

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  int potValue = analogRead(POT_PIN); // Read the potentiometer value
  int angle = map(potValue, 0, 1023, 0, 180); // Map the value to an angle between 0 and 180
  myServo.write(angle); // Set the servo position according to the mapped value
  delay(15); // Wait for the servo to reach the position
}
