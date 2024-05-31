#include <LiquidCrystal.h>

const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Current Time:");
}

void loop() {
  unsigned long currentMillis = millis();
  int seconds = currentMillis / 1000 % 60;
  int minutes = currentMillis / 60000 % 60;
  int hours = currentMillis / 3600000;

  lcd.setCursor(0, 1);
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds);

  delay(1000);
}
