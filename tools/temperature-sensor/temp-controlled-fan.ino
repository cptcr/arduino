#include <DHT.h>

#define DHTPIN 2     // Pin where the sensor is connected
#define DHTTYPE DHT11   // DHT 11
#define FAN_PIN 3    // Pin where the fan is connected

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  delay(2000); // Wait a few seconds between measurements
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (t > 25) {
    digitalWrite(FAN_PIN, HIGH); // Turn the fan on
  } else {
    digitalWrite(FAN_PIN, LOW); // Turn the fan off
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
}
