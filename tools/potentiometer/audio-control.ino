const int POTENTIOMETER_PIN = A0; // Pin connected to the potentiometer
const int AUDIO_PIN = 9; // Pin connected to the audio output (e.g., speaker)

void setup() {
  pinMode(AUDIO_PIN, OUTPUT);
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN); // Read potentiometer value
  int frequency = map(potentiometerValue, 0, 1023, 200, 2000); // Map the value to frequency
  tone(AUDIO_PIN, frequency); // Generate the tone
}
