void notFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "404 Not found");
}

void setupServer(){
  server.onNotFound(notFound);
  server.begin();
  server.on("/RunngingLights/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "running lights");
    RunningLights( 124,  23,  45,  500);
  });
  server.on("/sos", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "sos");
    morse();
  });
}
