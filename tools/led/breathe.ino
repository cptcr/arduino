const int LED_PIN = 13; // Pin connected to the LED
const int FADE_DURATION = 1000; // Time for each fade cycle in milliseconds

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness < 255; brightness++) {
    analogWrite(LED_PIN, brightness); // Gradually increase brightness
    delay(FADE_DURATION / 255);
  }
  for (int brightness = 255; brightness > 0; brightness--) {
    analogWrite(LED_PIN, brightness); // Gradually decrease brightness
    delay(FADE_DURATION / 255);
  }
}
