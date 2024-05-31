#include <IRremote.h>

const int RECV_PIN = 12; // Pin connected to the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

// Define LEDs or other components for the interactive toy
const int LED1_PIN = 13;
const int LED2_PIN = 8;
const int BUZZER_PIN = 9;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  irrecv.enableIR(); // Start the IR receiver

  // Set pin modes for LEDs or other components
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX);

    // Define specific actions for different IR codes
    switch (results.value) {
      case 0x00000000: // LED1 on
        digitalWrite(LED1_PIN, HIGH);
        break;
      case 0x00000001: // LED1 off
        digitalWrite(LED1_PIN, LOW);
        break;
      case 0x00000002: // LED2 on
        digitalWrite(LED2_PIN, HIGH);
        break;
      case 0x00000003: // LED2 off
        digitalWrite(LED2_PIN, LOW);
        break;
      case 0x00000004: // Play sound
        tone(BUZZER_PIN, 1000); // Play a tone
        delay(500); // Play for 500 milliseconds
        noTone(BUZZER_PIN); // Stop the tone
        break;
      // Add more cases for other IR codes and toy actions
    }

    irrecv.resume(); // Prepare for the next IR code
  }
}
