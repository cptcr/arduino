#define leftTrigPin 8
#define leftEchoPin 9
#define rightTrigPin 7
#define rightEchoPin 6
#define motor1A 2
#define motor1B 3
#define motor2A 4
#define motor2B 5

void setup() {
  pinMode(leftTrigPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  long leftDuration = pulseIn(leftEchoPin, HIGH);
  float leftDistance = leftDuration * 0.034 / 2;
  long rightDuration = pulseIn(rightEchoPin, HIGH);
  float rightDistance = rightDuration * 0.034 / 2;

  if (leftDistance < 10 && rightDistance < 10) { // Obstacle detected
    stopMotors();
    delay(1000);
    // Implement obstacle avoidance logic (e.g., turn left or right)
  } else {
    moveForward();
  }
}

void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
