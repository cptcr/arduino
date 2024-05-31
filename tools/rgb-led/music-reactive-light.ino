const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int micPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read microphone value
  int micValue = analogRead(micPin);

  // Map microphone value to color intensity
  int redValue = map(micValue, 0, 1023, 0, 255);
  int greenValue = map(micValue, 0, 1023, 0, 255);
  int blueValue = map(micValue, 0, 1023, 0, 255);

  // Set PWM values for each color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
