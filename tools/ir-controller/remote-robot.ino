#include <IRremote.h>

const int RECV_PIN = 12; // Pin connected to the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  irrecv.enableIR(); // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX);

    // Define specific actions for different IR codes
    switch (results.value) {
      case 0x00000000: // Forward
        // Control robot motors for forward movement
        break;
      case 0x00000001: // Backward
        // Control robot motors for backward movement
        break;
      case 0x00000002: // Left
        // Control robot motors for left turn
        break;
      case 0x00000003: // Right
        // Control robot motors for right turn
        break;
      // Add more cases for other desired IR codes and actions
    }

    irrecv.resume(); // Prepare for the next IR code
  }
}
