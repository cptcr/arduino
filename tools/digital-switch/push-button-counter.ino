const int SWITCH_PIN = 2; // Pin connected to the switch
int buttonPressCount = 0; // Variable to store the button press count

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Set the switch pin as input with pullup resistor
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN);
  if (switchState == LOW) { // Button is pressed
    buttonPressCount++; // Increment the counter
    Serial.print("Button pressed: ");
    Serial.println(buttonPressCount); // Print the count
  }
}
