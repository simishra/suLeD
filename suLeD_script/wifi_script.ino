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
