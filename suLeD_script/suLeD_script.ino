#include <FastLED.h>
#include <WiFi.h>
#define NUM_LEDS 60
#define DATA_PIN 2

CRGB leds[NUM_LEDS];
int ledPin = 2;
const char* ssid = "samplessid";
const char* pw =  "samplepw";
const int ESPPort = 23; //Telnet
WiFiServer Server(ESPPort);

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
}

void initWiFi(){
  WiFi.begin(ssid, pw);
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("not connected");
  }
  Serial.println("connected");
}

void setupServer(){
  Server.begin();
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position=0;
 
  for(int j=0; j<NUM_LEDS*2; j++)
  {
      Position++; 
      for(int i=0; i<NUM_LEDS; i++) {
        setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
      }
     
      showStrip();
      delay(WaveDelay);
  }
}

void 
