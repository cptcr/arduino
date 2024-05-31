const int speakerPin = 8;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  tone(speakerPin, 1000); // Play a 1kHz tone
  delay(1000);
  noTone(speakerPin); // Stop the tone
  delay(1000);
}
