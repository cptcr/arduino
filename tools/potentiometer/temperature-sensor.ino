const int POTENTIOMETER_PIN = A0; // Pin connected to the potentiometer (acting as a voltage divider with a thermistor)
const int TEMPERATURE_REFERENCE = 25; // Reference temperature in degrees Celsius

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN); // Read potentiometer value
  float voltage = potentiometerValue * 5.0 / 1023.0; // Convert to voltage
  float resistance = 10000.0 / voltage - 10000.0; // Calculate thermistor resistance
  float temperature = TEMPERATURE_REFERENCE / log(resistance / 10000.0) + 273.15; // Convert to temperature in Kelvin
  temperature = temperature - 273.15; // Convert to Celsius
  Serial.print("Temperature: ");
  Serial.println(temperature, 1); // Print temperature with one decimal place
  delay(1000); // Delay for 1 second
}
