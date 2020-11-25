void initWiFi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pw);
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("not connected");
  }
  Serial.println("connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP()); 
}

//void setupClient(){
//  WiFiClient client = server.available();

//  if (client){
//    String req = client.readStringUntil('\r');
//    client.flush();
//    if(req.indexOf("/led/on") != -1)
//    digitalWrite(ledPin, HIGH);
//    if(req.indexOf("/led/off") != -1)
//    digitalWrite(ledPin, LOW);
//  }
//}
