#include <IRremote.h>

const int RECV_PIN = 12; // Pin connected to the IR receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

// Define IR codes for different media device functions
const int VOL_UP_CODE = 0x00000000;
const int VOL_DOWN_CODE = 0x00000001;
const int PLAY_PAUSE_CODE = 0x00000002;
const int CHANNEL_UP_CODE = 0x00000003;
const int CHANNEL_DOWN_CODE = 0x00000004;
// Add more codes for other desired functions

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
      case VOL_UP_CODE:
        // Send volume up command to the media device
        break;
      case VOL_DOWN_CODE:
        // Send volume down command to the media device
        break;
      case PLAY_PAUSE_CODE:
        // Send play/pause command to the media device
        break;
      case CHANNEL_UP_CODE:
        // Send channel up command to the media device
        break;
      case CHANNEL_DOWN_CODE:
        // Send channel down command to the media device
        break;
      // Add more cases for other IR codes and media device controls
    }

    irrecv.resume(); // Prepare for the next IR code
  }
}
