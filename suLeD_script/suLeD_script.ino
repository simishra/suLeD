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


void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
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
  server.begin();
}
void setupClient(){
  WiFiClient client = server.available();

  if (client){
    String req = client.readStringUntil('\r');
    client.flush();
    if(req.indexOf("/led/on") != -1)
    digitalWrite(ledPin, HIGH);
    if(req.indexOf("/led/off") != -1)
    digitalWrite(ledPin, LOW);
    
  }
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
 
