#include <FastLED.h>
#include <WiFi.h>
#define NUM_LEDS 60
#define DATA_PIN 2

CRGB leds[NUM_LEDS];
int ledPin = 2;
const char* ssid = "Hier";
const char* pw =  "36649208171032143028";
const int ESPPort = 80; //Telnet
WiFiServer server(80);



void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  initWiFi();
  setupServer();
}

void loop() {
  // put your main code here, to run repeatedly:
  setupClient();
}
