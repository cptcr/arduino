const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int speakerPin = 8;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    tone(speakerPin, 500); // Play a low-frequency sound
    delay(250);
    noTone(speakerPin);
  } else if (digitalRead(button2) == LOW) {
    tone(speakerPin, 1000); // Play a mid-frequency sound
    delay(250);
    noTone(speakerPin);
  } else if (digitalRead(button3) == LOW) {
    tone(speakerPin, 2000); // Play a high-frequency sound
    delay(250);
    noTone(speakerPin);
  }
}
