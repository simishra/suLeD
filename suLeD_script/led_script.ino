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

void kurz(){
  setAll(128, 140, 7);
  morse_pause();
}

void lang(){
  setAll(128, 140, 7);
  delay(1000);
  morse_pause();
}

void morse_pause(){
  delay(500);
  setAll(0, 0, 0);
  delay(500);
}

void morse(){
  char str[] = "SOS";
  char alpha[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
  char alphal[] ="abcdefghijklmnopqrstuvwxyz";
  for(int i=0; i<3; i++){
   
    if(str[i] == alpha[0]|| alphal[0]){
        kurz();
        lang();
    }
    if(str[i] == alpha[1]|| alphal[1]){
        lang();
        kurz();
        kurz();
        kurz();
    }
    if(str[i] == alpha[2]|| alphal[2]){
        lang();
        kurz();
        lang();
        kurz();
    }
    if(str[i] == alpha[3]|| alphal[3]){
        lang();
        kurz();
        kurz();
    }
    if(str[i] == alpha[4]|| alphal[4]){
        kurz();
    }
    if(str[i] == alpha[5]|| alphal[5]){
        kurz();
        kurz();
        lang();
        kurz();
    }
    if(str[i] == alpha[6]|| alphal[6]){
        lang();
        lang();
        kurz();
    }
    if(str[i] == alpha[7]|| alphal[7]){
        kurz();
        kurz();
        kurz();
        kurz();
    }
    if(str[i] == alpha[8]|| alphal[8]){
        kurz();
        kurz();
    }
    if(str[i] == alpha[9]|| alphal[9]){
        kurz();
        lang();
        lang();
        lang();
    }
    if(str[i] == alpha[10]|| alphal[10]){
        lang();
        kurz();
        lang();
    }
    if(str[i] == alpha[11]|| alphal[11]){
        kurz();
        lang();
        kurz();
        kurz();
    }
    if(str[i] == alpha[12]|| alphal[12]){
        lang();
        lang();
    }
    if(str[i] == alpha[13]|| alphal[13]){
        lang();
        kurz();
    }
    if(str[i] == alpha[14]|| alphal[14]){
        lang();
        lang();
        lang();
    }
    if(str[i] == alpha[15]|| alphal[15]){
        kurz();
        lang();
        lang();
        kurz();
    }
    if(str[i] == alpha[16]|| alphal[16]){
        lang();
        lang();
        kurz();
        lang();
    }
    if(str[i] == alpha[17]|| alphal[17]){
        kurz();
        lang();
        kurz();
    }
    if(str[i] == alpha[18]|| alphal[18]){
        kurz();
        kurz();
        kurz();
    }
    if(str[i] == alpha[19]|| alphal[19]){
        lang();
    }
    if(str[i] == alpha[20]|| alphal[20]){
        kurz();
        kurz();
        lang();
    }
    if(str[i] == alpha[21]|| alphal[21]){
        kurz();
        kurz();
        kurz();
        lang();
    }
    if(str[i] == alpha[22]|| alphal[22]){
        kurz();
        lang();
        lang();
    }
    if(str[i] == alpha[23]|| alphal[23]){
        lang();
        kurz();
        kurz();
        lang();
    }
    if(str[i] == alpha[24]|| alphal[24]){
        lang();
        kurz();
        lang();
        lang();
    }
    if(str[i] == alpha[25]|| alphal[25]){
        lang();
        lang();
        kurz();
        kurz();
    }
    
    
  }
}



 
 
