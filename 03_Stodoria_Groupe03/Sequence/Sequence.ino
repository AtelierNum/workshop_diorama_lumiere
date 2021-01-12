#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);// premier chiffre : nombre de led - deuxieme chiffre numero de broche sur la carte

void setup() { // put your setup code here, to run once:

  pixels.begin();
  pixels1.begin();
  Serial.begin(9600); //potence
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(0);
  Serial.println(potValue);

  if (potValue < 400) {

    float lum = 1. - map(potValue , 0, 400, 0, 100) / 100.;

    for (int i = 0; i < 16; i++) {
      pixels1.setPixelColor(i, pixels1.Color(255 * lum , 180 * lum * lum, 0));
      pixels.setPixelColor(i, pixels1.Color(0 , 0, 0));
    }

    pixels1.show();
    pixels.show();


  }
  else if (potValue > 400 && potValue < 500) {
    for (int i = 0; i < 16; i++) {
      pixels1.setPixelColor(i, pixels1.Color(0 , 0, 0));
      pixels.setPixelColor(i, pixels1.Color(0 , 0, 0));
    }

    pixels1.show();
    pixels.show();



  }
  else if (potValue > 500 & potValue < 750) {

    float lum = map(potValue , 500, 750, 0, 100) / 100.;

    for (int i = 0; i < 16; i++) {
      pixels1.setPixelColor(i, pixels1.Color(0 , 0, 0));
      pixels.setPixelColor(i, pixels1.Color(255 * lum , 25 * lum, 75 * lum));
    }

    pixels1.show();
    pixels.show();



  }
  else if (potValue > 750) {
    float lum = map(potValue , 750, 1023, 0, 100) / 100.;

    for (int i = 0; i < 16; i++) {
      pixels1.setPixelColor(i, pixels1.Color(100 * lum , 100 * lum, 255 * lum));
      pixels.setPixelColor(i, pixels1.Color(255  , 25 , 75 ));
    }

    pixels1.show();
    pixels.show();

  }

}

  /*
    float lum = potValue / 1023.; //potence, valeur entre 0 et 1023
    for (int i = 0; i < 16; i++) {

    //float g = map(i, 0, 15, 0, 255); //pour le dégradé
    pixels.setPixelColor(i, pixels.Color(255 * lum, 10 * lum, 255 * lum));
    //pixels.setPixelColor(i, pixels.Color(255, 255, 255));

    pixels.show();
    }


    for (int i = 0; i < 16; i++) {

    if (potValue < potValue/2 ) {
      pixels1.setPixelColor(i, pixels1.Color(0 * (1 - lum), 0 * (1 - lum), 255 * (1 - lum)));
    }
    else
    {
      pixels1.setPixelColor(i, pixels1.Color(100 * (1 - lum), 100 * (1 - lum), 220 * (1 - lum)));
    }

    //float s = map(i, 0, 15, 0, 255); //pour le dégradé
    //pixels1.setPixelColor(i, pixels1.Color(100 * (1 - lum), 100 * (1 - lum), 255 * (1 - lum))); //le 1-lum pour inverser
    //pixels1.setPixelColor(i, pixels1.Color(255, 255, 255));

    pixels1.show();
    }

pixels.setPixelColor(i, pixels.Color(255, 255, 255));*/
