#include <LiquidCrystal.h>

const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;
const int sensorPin = A0;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Light Level:");
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int lightPercentage = map(sensorValue, 0, 1023, 0, 100);

  lcd.setCursor(0, 1);
  lcd.print(lightPercentage);
  lcd.print("%");

  delay(500);
}
