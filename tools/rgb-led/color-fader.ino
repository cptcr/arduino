const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Increase color values
  redValue++;
  greenValue++;
  blueValue++;

  // Check for overflow and reset to 0
  if (redValue > 255) {
    redValue = 0;
  }
  if (greenValue > 255) {
    greenValue = 0;
  }
  if (blueValue > 255) {
    blueValue = 0;
  }

  // Set PWM values for each color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  delay(10); // Adjust delay for desired fade speed
}
