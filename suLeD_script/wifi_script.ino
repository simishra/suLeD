#include <FastLED.h>
#include <WiFi.h>

#define NUM_LEDS 60
#define DATA_PIN 2


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
