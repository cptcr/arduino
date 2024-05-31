const int LED_PIN = 13; // Pin connected to the LED
const int DOT_LENGTH = 250; // Duration of a dot in milliseconds
const int DASH_LENGTH = 3 * DOT_LENGTH; // Duration of a dash in milliseconds
const int LETTER_SPACE = 3 * DOT_LENGTH; // Space between letters
const int WORD_SPACE = 7 * DOT_LENGTH; // Space between words

char morseCode[][6] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  String message = "HELLO WORLD"; // Replace with your desired message

  for (int i = 0; i < message.length(); i++) {
    char letter = message.charAt(i);
    if (letter == ' ') {
      delay(WORD_SPACE); // Space between words
    } else {
      int letterIndex = letter - 'A';
      for (int j = 0; j < strlen(morseCode[letterIndex]); j++) {
        if (morseCode[letterIndex][j] == '.') {
          digitalWrite(LED_PIN, HIGH);
          delay(DOT_LENGTH);
          digitalWrite(LED_PIN, LOW);
          delay(DOT_LENGTH);
        } else if (morseCode[letterIndex][j] == '-') {
          digitalWrite(LED_PIN, HIGH);
          delay(DASH_LENGTH);
          digitalWrite(LED_PIN, LOW);
          delay(DOT_LENGTH);
        }
      }
      delay(LETTER_SPACE); // Space between letters
    }
  }
}
