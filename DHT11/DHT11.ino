#include "DHT.h"

#define DHTPIN 5     // D1;Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
float h;
float t;

void setup() {
  //Begin serial communicaton
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));

  //begin dht communication
  dht.begin();
}

void loop() {
  // get the humidity and temperature values
  h = dht.readHumidity();
  t = dht.readTemperature();

  // check if dht giving values or not, if not print error message on screen
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  //print the values on screen
Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));

  Serial.println("");
  delay(1000);
}