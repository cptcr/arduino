#include <IRremote.h>

const int RECV_PIN = 12; // Pin connected to the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

// Define pins for controlling appliances (e.g., relays, IR modules)
const int LIGHT_PIN = 2;
const int FAN_PIN = 3;
const int TV_PIN = 4;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  irrecv.enableIR(); // Start the IR receiver

  // Set pin modes for controlling appliances
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(TV_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX);

    // Define specific actions for different IR codes
    switch (results.value) {
      case 0x00000000: // Light on
        digitalWrite(LIGHT_PIN, HIGH);
        break;
      case 0x00000001: // Light off
        digitalWrite(LIGHT_PIN, LOW);
        break;
      case 0x00000002: // Fan on
        digitalWrite(FAN_PIN, HIGH);
        break;
      case 0x00000003: // Fan off
        digitalWrite(FAN_PIN, LOW);
        break;
      case 0x00000004: // TV power
        // Control TV power using IR module connected to TV_PIN
        break;
      // Add more cases for other desired IR codes and appliance controls
    }

    irrecv.resume(); // Prepare for the next IR code
  }
}
