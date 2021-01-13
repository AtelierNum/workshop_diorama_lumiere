#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(16, 10, NEO_GRB + NEO_KHZ800);


double incr1 = 0 ;
double incr2 = 0 ;
double incr3 = 0 ;


int startIndex = 0 ;

long previousTime = 0 ;
long interval = 100;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pixels.begin();
  pixels2.begin();
}
void loop() {

  Serial.println(analogRead(0));

  int potValue = analogRead(0);

  if (potValue < 20) potValue = 0;
  float lum = potValue / 1023. ;
  lum = lum * lum ;


  int timeInterval =  map(potValue , 0 , 1023, 500, 10); // vitesse du vortex (500 lent - 10 rapide)

  // anneau du bas
  incr1 += 0.005; // vitesse pulsation
  incr2 += 0.009; // vitesse pulsation
  incr3 += 0.003; // vitesse pulsation
  double lum2a = (sin(incr1) + 1) * 0.5 ;
  double lum2b = (sin(incr2 ) + 1) * 0.5 ;
  double lum2c = (sin(incr3 ) + 1) * 0.5 ;
  //Serial.println(lum2a);
  // put your main code here, to run repeatedly:
  pixels2.setPixelColor(0, pixels2.Color(20 * lum2a * lum, 255 * lum2a * lum, 5 * lum2a * lum));
  pixels2.setPixelColor(1, pixels2.Color(20 * lum2a * lum, 255 * lum2a * lum, 5 * lum2a * lum));
  pixels2.setPixelColor(6, pixels2.Color(20 * lum2a * lum, 255 * lum2a * lum, 5 * lum2a * lum));
  pixels2.setPixelColor(12, pixels2.Color(20 * lum2a * lum, 255 * lum2a * lum, 5 * lum2a * lum));
  pixels2.setPixelColor(13, pixels2.Color(20 * lum2a * lum, 255 * lum2a * lum, 5 * lum2a * lum));

  pixels2.setPixelColor(2, pixels2.Color(255 * lum2b * lum, 0, 251 * lum2b * lum));
  pixels2.setPixelColor(3, pixels2.Color(255 * lum2b * lum, 0, 251 * lum2b * lum));
  pixels2.setPixelColor(4, pixels2.Color(255 * lum2b * lum, 0, 251 * lum2b * lum));
  pixels2.setPixelColor(7, pixels2.Color(255 * lum2b * lum, 0, 251 * lum2b * lum));
  pixels2.setPixelColor(8, pixels2.Color(255 * lum2b * lum, 0, 251 * lum2b * lum));
  pixels2.setPixelColor(14, pixels2.Color(255 * lum2b * lum, 0, 251 * lum2b * lum));

  pixels2.setPixelColor(5, pixels2.Color(106 * lum2c * lum, 255 * lum2c * lum, 110 * lum2c * lum));
  pixels2.setPixelColor(9, pixels2.Color(106 * lum2c * lum, 255 * lum2c * lum, 110 * lum2c * lum));
  pixels2.setPixelColor(10, pixels2.Color(106 * lum2c * lum, 255 * lum2c * lum, 110 * lum2c * lum));
  pixels2.setPixelColor(11, pixels2.Color(106 * lum2c * lum, 255 * lum2c * lum, 110 * lum2c * lum));
  pixels2.setPixelColor(15, pixels2.Color(106 * lum2c * lum, 255 * lum2c * lum, 110 * lum2c * lum));


  pixels2.show();

  //delay(100);

  //currentTime = millis();
  if (millis()  - previousTime > timeInterval) {
    startIndex  ++ ;
    startIndex = startIndex % 16;
    previousTime = millis();
  }

  for (int i = startIndex; i < startIndex + 6; i++) {
    pixels.setPixelColor(i % 16, pixels.Color(255 * lum, 0, 0));
  }
  for (int i = startIndex + 6; i < startIndex + 11; i++) {
    pixels.setPixelColor(i % 16, pixels.Color(150 * lum, 20 * lum, 0));
  }
  for (int i = startIndex + 11; i <  startIndex + 16; i++) {
    pixels.setPixelColor(i % 16, pixels.Color(25 * lum, 10 * lum, 0));
  }


  pixels.show();
}
