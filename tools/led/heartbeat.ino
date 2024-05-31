const int LED_PIN = 13; // Pin connected to the LED
const int HEARTBEAT_RATE = 60; // Heartbeat rate in beats per minute
const int BEAT_DURATION = 60000 / HEARTBEAT_RATE; // Time between beats in milliseconds

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Simulate heartbeat peak
  delay(BEAT_DURATION / 2);
  digitalWrite(LED_PIN, LOW); // Simulate heartbeat rest
  delay(BEAT_DURATION / 2);
}
