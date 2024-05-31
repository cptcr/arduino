const int LED_PIN = 13; // Pin connected to the LED
const int BLINK_INTERVAL = 1000; // Time between blinks in milliseconds

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn the LED on
  delay(BLINK_INTERVAL); // Wait for the blink interval
  digitalWrite(LED_PIN, LOW); // Turn the LED off
  delay(BLINK_INTERVAL); // Wait for the blink interval
}
