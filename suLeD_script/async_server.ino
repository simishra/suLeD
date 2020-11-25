int red = 123;
int green = 33;
int blue = 5;
int Wave_Delay = 500;
//index html to show overview of functions
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <title>UtzAtz Disco Disco</title>
  </head>
  <body>
    hallo<br>
    tschuess
  </body>
</html>)rawliteral";

void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "404 Not found");
}


void setupServer(){
  server.on("/RunngingLights", HTTP_GET, [](AsyncWebServerRequest *request){
    RunningLights(red, green, blue, Wave_Delay);
    request->send_P(200, "text/html", "running lights");
  });
  server.on("/sos", HTTP_GET, [](AsyncWebServerRequest *request){
    morse();
    request->send_P(200, "text/html", "sos");
  });
  
  server.onNotFound(notFound);
  server.begin();
}
