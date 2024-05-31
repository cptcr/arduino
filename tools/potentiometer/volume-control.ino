const int POTENTIOMETER_PIN = A0; // Pin connected to the potentiometer
const int LED_PIN = 13; // Pin connected to the LED

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN); // Read potentiometer value
  int brightness = map(potentiometerValue, 0, 1023, 0, 255); // Map the value to brightness
  analogWrite(LED_PIN, brightness); // Set the LED brightness
}
