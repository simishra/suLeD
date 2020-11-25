#include <FastLED.h>
#include <WiFi.h>
// Webserver
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// LEDS
#define NUM_LEDS 60
#define DATA_PIN 27

CRGB leds[NUM_LEDS];
const char* ssid = "secret";
const char* pw =  "secret";

AsyncWebServer server(80);

void setup() {
  Serial.begin(11520);
  initWiFi();
  setupServer();
}

void loop() {
}
