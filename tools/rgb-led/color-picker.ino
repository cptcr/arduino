const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int redPotPin = A0;
const int greenPotPin = A1;
const int bluePotPin = A2;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read potentiometer values
  int redValue = analogRead(redPotPin) / 4; // Scale for 0-255 range
  int greenValue = analogRead(greenPotPin) / 4;
  int blueValue = analogRead(bluePotPin) / 4;

  // Set PWM values for each color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
