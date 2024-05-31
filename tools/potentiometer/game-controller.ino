const int POTENTIOMETER_PIN_X = A0; // Pin connected to the X-axis potentiometer
const int POTENTIOMETER_PIN_Y = A1; // Pin connected to the Y-axis potentiometer

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int xValue = analogRead(POTENTIOMETER_PIN_X); // Read X-axis potentiometer value
  int yValue = analogRead(POTENTIOMETER_PIN_Y); // Read Y-axis potentiometer value
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(", Y: ");
  Serial.println(yValue); // Print both values
  delay(100); // Delay for 100 milliseconds
}
