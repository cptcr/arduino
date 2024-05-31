#include <Wire.h>
#include <Adafruit_PN532.h>

#define SDA_PIN 4
#define SCL_PIN 5
#define LED_PIN 6

Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

uint8_t authorizedUID[] = { 0x12, 0x34, 0x56, 0x78 };

void setup(void) {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  nfc.SAMConfig();
  Serial.println("Waiting for an NFC card ...");
}

void loop(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; 
  uint8_t uidLength;

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    Serial.println("Found an NFC card!");
    bool authorized = true;
    for (uint8_t i = 0; i < uidLength; i++) {
      if (uid[i] != authorizedUID[i]) {
        authorized = false;
        break;
      }
    }

    if (authorized) {
      Serial.println("LED ON");
      digitalWrite(LED_PIN, HIGH);
      delay(1000);
      digitalWrite(LED_PIN, LOW);
    } else {
      Serial.println("Unauthorized NFC tag");
    }
    delay(1000);
  }
}
