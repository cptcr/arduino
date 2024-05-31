const byte ROWS = 4; // Number of rows in the keypad
const byte COLS = 4; // Number of columns in the keypad
char keys[ROWS][COLS] = {
  {'a', 'b', 'c', 'd'},
  {'e', 'f', 'g', 'h'},
  {'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; // Pins connected to keypad rows
byte colPins[COLS] = {6, 7, 8, 9}; // Pins connected to keypad columns

String text = "";

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  for (int i = 0; i < COLS; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

void loop() {
  char input = readKeypad();
  if (input != '\0') {
    Serial.print(input);
    // Add the pressed key to the text string
    text += input;
  }
  // Add functionality for backspace, enter, and other editing options
}

char readKeypad() {
  for (int i = 0; i < ROWS; i++) {
    digitalWrite(rowPins[i], LOW);
    for (int j = 0; j < COLS; j++) {
      if (digitalRead(colPins[j]) == LOW) {
        delay(10);
        if (digitalRead(colPins[j]) == LOW) {
          digitalWrite(rowPins[i], HIGH);
          return keys[i][j];
        }
      }
    }
    digitalWrite(rowPins[i], HIGH);
  }
  return '\0';
}
