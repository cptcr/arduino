#include <SPI.h>
#include <SD.h>
#include <DHT.h>

#define DHTPIN 2     // Pin where the sensor is connected
#define DHTTYPE DHT11   // DHT 11
#define CHIP_SELECT 10 // Pin where the SD card module is connected

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  if (!SD.begin(CHIP_SELECT)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card is ready to use.");
}

void loop() {
  delay(2000); // Wait a few seconds between measurements
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.print("Humidity: ");
    dataFile.print(h);
    dataFile.print(" %, ");
    dataFile.print("Temperature: ");
    dataFile.print(t);
    dataFile.println(" *C");
    dataFile.close();
    Serial.println("Data logged.");
  } else {
    Serial.println("Error opening datalog.txt");
  }
}
