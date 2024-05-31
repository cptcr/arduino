const int LED_PIN = 13; // Pin connected to the LED
const int SWITCH_PIN = 2; // Pin connected to the switch

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN);
  if (switchState == LOW) { // Switch is pressed
    digitalWrite(LED_PIN, HIGH); // Turn the LED on
  } else {
    digitalWrite(LED_PIN, LOW); // Turn the LED off
  }
}
