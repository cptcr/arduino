#include <SPI.h>
#include <SD.h>

const int speakerPin = 8;
const int chipSelect = 4;

File myFile;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(chipSelect, OUTPUT);
  Serial.begin(9600);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  myFile = SD.open("melody.wav");
  if (!myFile) {
    Serial.println("Error opening melody file!");
    return;
  }
}

void loop() {
  while (myFile.available()) {
    byte data = myFile.read();
    tone(speakerPin, data);
    delay(2); // Adjust delay based on audio file
  }
  
  myFile.close();
  delay(1000);
  myFile = SD.open("melody.wav");
}
