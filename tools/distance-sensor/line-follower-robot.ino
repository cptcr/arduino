#define leftSensorPin A0
#define rightSensorPin A1
#define motor1A 2
#define motor1B 3
#define motor2A 4
#define motor2B 5

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  int leftValue = analogRead(leftSensorPin);
  int rightValue = analogRead(rightSensorPin);

  if (leftValue > rightValue) {
    // Line on the left, turn right
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
  } else if (leftValue < rightValue) {
    // Line on the right, turn left
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  } else {
    // Line in the center, move forward
    moveForward();
  }
}

void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}
