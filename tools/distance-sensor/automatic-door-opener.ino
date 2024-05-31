#define trigPin 8
#define echoPin 9
#define servoPin 10 // Servo motor connected to door
#define threshold 20 // Distance threshold in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoPin, OUTPUT);
  
  // Set servo to open position initially
  servo.attach(servoPin);
  servo.write(180);
}

void loop() {
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < threshold) {
    servo.write(0); // Open door
    delay(5000); // Keep door open for 5 seconds
    servo.write(180); // Close door
  }
}
