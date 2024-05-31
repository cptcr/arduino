#include <LiquidCrystal.h>

const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const char* message = "This is a scrolling message.";

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  for (int i = 0; i < strlen(message); i++) {
    lcd.scrollDisplayLeft();
    lcd.print(message[i]);
    delay(250);
  }
}
