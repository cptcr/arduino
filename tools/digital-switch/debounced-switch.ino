const int SWITCH_PIN = 2; // Pin connected to the switch
const int LED_PIN = 13; // Pin connected to the LED

long lastDebounceTime = 0; // Variable to store the last debounce time
int switchState = HIGH; // Variable to store the current switch state

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Set the switch pin as input with pullup resistor
}

void loop() {
  int currentSwitchState = digitalRead(SWITCH_PIN);
  if (currentSwitchState != switchState && millis() - lastDebounceTime > 50) { // Check for state change and debounce delay
    lastDebounceTime = millis(); // Update debounce time
    switchState = currentSwitchState; // Update switch state
    if (switchState == LOW) {
      digitalWrite(LED_PIN, HIGH); // Turn the LED on
    } else {
      digitalWrite(LED_PIN, LOW); // Turn the LED off
    }
  }
}
