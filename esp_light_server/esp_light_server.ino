#include <ESP8266WiFi.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

ESP8266WebServer server(80);

#define LIGHT 4

void handleOn();
void handleOff();
void handleStatus();

void setup() {
  pinMode(LIGHT, OUTPUT);
  digitalWrite(LIGHT, LOW);
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  server.on("/api/on", handleOn);
  server.on("/api/off", handleOff);
  server.on("/api/status", handleStatus);

  server.begin();
  Serial.println("HTTP server started");

  digitalWrite(LIGHT, LOW);
}

void loop() {
  server.handleClient();
}

void handleOn() {
  digitalWrite(LIGHT, HIGH);  
  server.send(200, "text/plain", "ok");
}
void handleOff() {
  digitalWrite(LIGHT, LOW);  
  server.send(200, "text/plain", "ok");
}
void handleStatus() {
  server.send(200, "text/plain", digitalRead(LIGHT) ? "1": "0");
}
