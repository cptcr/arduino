#include <Servo.h>

Servo myServo;

#define SERVO_PIN 9 // Pin where the servo motor is connected

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(15); // Adjust speed as necessary
  }
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15); // Adjust speed as necessary
  }
}
