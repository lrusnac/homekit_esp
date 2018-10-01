#include "DHTesp.h"

#include <ESP8266WiFi.h>

#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#define DHTPIN 4
DHTesp dht;
ESP8266WebServer server(80);

void handleHumidity();
void handleTemperature();

void setup() {
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  server.on("/api/getHumidity", handleHumidity);
  server.on("/api/getTemperature", handleTemperature);

  server.begin();
  Serial.println("HTTP server started");

  dht.setup(DHTPIN, DHTesp::DHT22);
}

void loop() {
    server.handleClient();
}

void handleHumidity() {
  float h = dht.getHumidity();
  server.send(200, "text/plain", String(h));
}

void handleTemperature() {
  float t = dht.getTemperature();
  server.send(200, "text/plain", String(t));
}
