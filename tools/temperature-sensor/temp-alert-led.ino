#include <DHT.h>

#define DHTPIN 2     // Pin where the sensor is connected
#define DHTTYPE DHT11   // DHT 11
#define LED_PIN 13    // Pin where the LED is connected

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  delay(2000); // Wait a few seconds between measurements
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (t > 30) {
    digitalWrite(LED_PIN, HIGH); // Turn the LED on
  } else {
    digitalWrite(LED_PIN, LOW); // Turn the LED off
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
}
