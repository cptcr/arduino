#include <IRremote.h>

const int RECV_PIN = 12; // Pin connected to the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

// Define pins or components for the security system (e.g., siren, alarm notification)
const int SIREN_PIN = 10;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  irrecv.enableIR(); // Start the IR receiver

  pinMode(SIREN_PIN, OUTPUT); // Set siren pin as output
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX);

    // Define the trigger code for activating the alarm
    const int ALARM_TRIGGER_CODE = 0x00000000;

    if (results.value == ALARM_TRIGGER_CODE) {
      // Activate the security system alarm
      digitalWrite(SIREN_PIN, HIGH); // Turn on the siren
      // Send notifications or alerts (e.g., using serial communication or other methods)
    }

    irrecv.resume(); // Prepare for the next IR code
  }
}
