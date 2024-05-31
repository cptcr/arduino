#define trigPin 8
#define echoPin 9

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; // Calculate distance in cm
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
}
