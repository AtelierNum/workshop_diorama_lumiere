#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(16, 9, NEO_GRB + NEO_KHZ800);//16 leds branchés sur 9
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(16, 10, NEO_GRB + NEO_KHZ800);//16 leds branchés sur 10

long currentTime;

int startIndex = 0;

int previousTime = 0;
int interval = 50;
int incr = 0;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pixels1.begin();
  pixels2.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  // incr ++;
  currentTime = millis() % 32000;

  if (currentTime < 8000) {


    double lum = map(currentTime, 0, 8000, 0, 10000) / 10000.;
    lum = lum * lum;
    for (int i = 0; i < 16 ; i++) {
      pixels1.setPixelColor (i, pixels1.Color(255 * lum, 255 * lum, 255 * lum));
      pixels2.setPixelColor (i, pixels1.Color(0, 0, 0));
    }

    pixels1.show();
    pixels1.setBrightness(100);
    startIndex = 0;
    previousTime = 0;

  }

  else if (currentTime > 8000 && currentTime < 16000) {
    float currentTime2 = constrain(currentTime, 8000, 13000);
    float lum = 1 - map(currentTime2, 8000, 13000, 0, 1000) / 1000.;
    lum = (lum) * lum * lum * lum;
    float lum2 = map(currentTime, 8000, 16000, 0, 1000) / 1000.;
    lum2 = lum2;
    for (int i = 0; i < 16 ; i++) {
      pixels1.setPixelColor (i, pixels1.Color(255 * lum, 255 * lum, 255 * lum));
      //pixels2.setPixelColor (i, pixels1.Color(0, 0, 255 * lum2));
    }

    float lum3 =  map(currentTime, 8000, 16000, 0, 1000) / 1000.;

    for (int i = 0; i <   16 ; i++) {
      if (i % 2 == 0) {
        float lum4 = (sin(millis() / 500. + i * .25) + 1) / 2.;
        pixels2.setPixelColor (i, pixels1.Color(0, 0, 255 * lum4 * lum3));
      }
      else {
        pixels2.setPixelColor (i, pixels1.Color(0, 0, 0  * lum3));
      }
    }


    pixels2.show();

    pixels1.show();
    pixels2.show();




  }

  else if (currentTime > 16000 && currentTime < 24000) {
    float lum = 1. - map(currentTime, 16000, 24000, 0, 1000) / 1000.;

    for (int i = 0; i <   16 ; i++) {
      if (i % 2 == 0) {
        float lum2 = (sin(millis() / 500. + i * .25) + 1) / 2.;
        pixels2.setPixelColor (i, pixels1.Color(0, 0, 255 * lum2 ));
      }
      else {
        pixels2.setPixelColor (i, pixels1.Color(0, 0, 0  * lum));
      }
    }


    pixels2.show();

    if (currentTime - previousTime > interval) {
      startIndex ++;
      previousTime = currentTime;
    }
    for (int j = 0; j < 16 ; j++) {
      //float lum2 = (sin(millis() / 500. + i) + 1) / 2.;
      int teinte = map(((startIndex + j) % 16), 0, 15, 0 , 65536);
      pixels1.setPixelColor (j % 16 , pixels1.ColorHSV(teinte));


    }
    double lum2 = map(currentTime, 16000, 24000, 0, 10000) / 10000.;
    pixels1.setBrightness (20*lum2);
    pixels1.show();




  }

  else if (currentTime > 24000 && currentTime < 32000) {
    float lum = 1. - map(currentTime, 24000, 32000, 0, 1000) / 1000.;

    for (int i = 0; i <   16 ; i++) {
      if (i % 2 == 0) {
        float lum2 = (sin(millis() / 500. + i * .25) + 1) / 2.;
        pixels2.setPixelColor (i, pixels1.Color(0, 0, 255 * lum2 * lum));
      }
      else {
        pixels2.setPixelColor (i, pixels1.Color(0, 0, 0  * lum));
      }
    }


    pixels2.show();

    if (currentTime - previousTime > interval) {
      startIndex ++;
      previousTime = currentTime;
    }
    for (int j = 0; j < 16 ; j++) {
      //float lum2 = (sin(millis() / 500. + i) + 1) / 2.;
      int teinte = map(((startIndex + j) % 16), 0, 15, 0 , 65536);
      pixels1.setPixelColor (j % 16 , pixels1.ColorHSV(teinte));
      pixels1.setBrightness (lum * 10);


    }
    pixels1.show();



  }





}
