const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Generate random values for each color
  int redValue = random(0, 256);
  int greenValue = random(0, 256);
  int blueValue = random(0, 256);

  // Set PWM values for each color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  delay(500); // Adjust delay for desired color change frequency
}
