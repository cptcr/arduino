#include <Servo.h>

Servo myServo;

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 11

void setup() {
  myServo.attach(SERVO_PIN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  int angle = map(distance, 0, 100, 0, 180); // Map the distance to an angle between 0 and 180
  myServo.write(angle); // Set the servo position according to the mapped value

  delay(1000); // Wait for a second before the next reading
}
