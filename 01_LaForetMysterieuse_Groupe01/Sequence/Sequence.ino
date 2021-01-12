#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(16, 9, NEO_GRB + NEO_KHZ800); //16 leds branchées sur 9
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(16, 11, NEO_GRB + NEO_KHZ800); //16 leds branchées sur 11



long currentTime = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pixels1.begin();
  pixels2.begin();

  for (int i = 0 ; i < 16 ; i++) {
    //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0)); //vert vers bleu
    pixels1.setPixelColor(i, pixels2.Color(0, 0, 0));

  }
  pixels2.show();
  pixels1.show();
  delay(500);
}

void loop() {


  currentTime = (millis())  % 60000;


  // ETAPE 1
  if (currentTime < 5000) {
    for (int i = 0 ; i < 16 ; i++) {
      //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
      pixels2.setPixelColor(i, pixels2.Color(0, 0, 0)); //vert vers bleu
      pixels1.setPixelColor(i, pixels2.Color(0, 0, 0));

    }

    pixels1.setBrightness( 100);
    pixels1.show();

    pixels2.setBrightness(100);
    pixels2.show();
    

  }

  // ETAPE 2
  else if (currentTime > 5000 && currentTime < 20000) {

    int currentTime2 = constrain(currentTime , 5000, 13000);
    float lum1 = map(currentTime2 , 5000, 13000, 0 , 1000) / 1000.;

    int currentTime3 = constrain(currentTime , 11000, 18000);
    float lum2 = map(currentTime3 , 11000, 18000, 0 , 1000) / 1000.;
    lum2 = lum2 * lum2;


    for (int i = 0 ; i < 16 ; i++) {
      //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
      pixels1.setPixelColor(i, pixels2.Color(255 * lum1, 255 * lum1, 255 * lum1)); //vert vers bleu
      pixels2.setPixelColor(i, pixels2.Color(255 * lum2, 255 * lum2, 255 * lum2));

    }
    pixels2.show();
    pixels1.show();



  }

  // ETAPE 3
  else if (currentTime > 20000 && currentTime < 30000) {


    float lum2 = 1. - map(currentTime , 20000, 30000, 0 , 1000) / 1000.;
    lum2 = lum2 * lum2;

    float lum1 = map(currentTime , 20000, 30000, 0 , 1000) / 1000.;



    for (int i = 0 ; i < 16 ; i++) {

      if (i % 2 == 0) {
        //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
        pixels1.setPixelColor(i, pixels2.Color(255 , 255 - 255 * lum1, 255 - 155 * lum1)); //vert vers bleu
      }
      else {
        pixels1.setPixelColor(i, pixels2.Color(255 - 30 * lum1 , 255  - 175 * lum1 , 255 )); //vert vers bleu
      }
      pixels2.setPixelColor(i, pixels2.Color(255 * lum2, 255 * lum2, 255 * lum2));

    }
    pixels2.show();
    pixels1.show();




  }

  // ETAPE 4
  else if (currentTime > 30000 && currentTime < 40000) {

    float currentTime2 = constrain(currentTime, 35000, 40000);

    float lum1 = 1. - map(currentTime , 30000, 40000, 0, 1000) / 1000.;
    lum1 = lum1 * lum1;

    float lum2 =  map(currentTime2 , 35000, 40000, 0, 1000) / 1000.;
    lum2 = lum2 * lum2;
    //Serial.println(currentTime2);
    //Serial.println(lum2);



    for (int i = 0 ; i < 16 ; i++) {

      if (i % 2 == 0) {
        //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
        pixels1.setPixelColor(i, pixels2.Color(255 , 255 - 255 * 1, 255 - 155 * 1)); //vert vers bleu
      }
      else {
        pixels1.setPixelColor(i, pixels2.Color(255 - 30 * 1 , 255  - 175 * 1 , 255 )); //vert vers bleu
      }

    }

    pixels1.setBrightness( lum1 * 100);
    pixels1.show();

    for (int i = 0 ; i < 16 ; i++) {
      pixels2.setPixelColor(i, pixels2.Color(50  , 50 , 255 )); //vert vers bleu

    }
    pixels2.setBrightness(80 * lum2);
    pixels2.show();




  }
  else if (currentTime > 40000 && currentTime < 50000) {



    for (int i = 0 ; i < 16 ; i++) {

      if (i % 2 == 0) {
        //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
        pixels1.setPixelColor(i, pixels2.Color(255 , 255 - 255 * 1, 255 - 155 * 1)); //vert vers bleu
      }
      else {
        pixels1.setPixelColor(i, pixels2.Color(255 - 30 * 1 , 255  - 175 * 1 , 255 )); //vert vers bleu
      }

    }



    for (int i = 0 ; i < 16 ; i++) {
      pixels2.setPixelColor(i, pixels2.Color(50 * 1 , 50 * 1, 255 * 1)); //vert vers bleu

    }

    float pulse1 = ((sin(currentTime * .00167) + 1) / 2.) * 80.;
    float pulse2 = ((cos(currentTime * 0.00258) + 1) / 2.) * 80;


    pixels1.setBrightness( pulse1);
    pixels1.show();

    pixels2.setBrightness(pulse2);
    pixels2.show();





  }
  else if (currentTime > 50000 && currentTime < 60000) {

    float lum = map(currentTime , 50000, 60000, 1000, 0) / 1000.0;

    for (int i = 0 ; i < 16 ; i++) {

      if (i % 2 == 0) {
        //float g = map(i, 0, 15, 0, 255); //dégradé de 2 couleurs
        pixels1.setPixelColor(i, pixels2.Color(255 , 255 - 255 * 1, 255 - 155 * 1)); //vert vers bleu
      }
      else {
        pixels1.setPixelColor(i, pixels2.Color(255 - 30 * 1 , 255  - 175 * 1 , 255 )); //vert vers bleu
      }

    }



    for (int i = 0 ; i < 16 ; i++) {
      pixels2.setPixelColor(i, pixels2.Color(50 * 1 , 50 * 1, 255 * 1)); //vert vers bleu

    }

    float pulse1 = ((sin(currentTime * .00167) + 1) / 2.) * 80.;
    float pulse2 = ((cos(currentTime * 0.00258) + 1) / 2.) * 80;


    pixels1.setBrightness( pulse1*lum);
    pixels1.show();

    pixels2.setBrightness(pulse2*lum);
    pixels2.show();



  }



}
