#include "FastLED.h"
#define DATA_PIN1    2
#define DATA_PIN2    3
#define DATA_PIN3    4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    13
CRGB leds[3][NUM_LEDS];

void setup() { 
  FastLED.addLeds<LED_TYPE,DATA_PIN1,COLOR_ORDER>(leds[0], NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN2,COLOR_ORDER>(leds[1], NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN3,COLOR_ORDER>(leds[2], NUM_LEDS);
}


void loop() {
  int i;
   
  for(i = 0; i < NUM_LEDS; i++) {
    leds[0][i] = CRGB::Blue; 
    FastLED.show(); 
    //delay(100); 
    leds[1][i] = CRGB::Blue; 
    FastLED.show(); 
   //delay(100);
    leds[2][i] = CRGB::Blue;
    FastLED.show();
    delay(100);
  }
  for(i = 0; i < NUM_LEDS; i++) {
    leds[0][i] = CRGB::White; 
    FastLED.show(); 
    //delay(100); 
    leds[1][i] = CRGB::White; 
    FastLED.show(); 
   //delay(100);
    leds[2][i] = CRGB::White;
    FastLED.show();
    delay(100);
  }
  for(i = 0; i < NUM_LEDS; i++) {
    leds[0][i] = CRGB::Red; 
    FastLED.show(); 
    //delay(100); 
    leds[1][i] = CRGB::Red; 
    FastLED.show(); 
   //delay(100);
    leds[2][i] = CRGB::Red;
    FastLED.show();
    delay(100);
  }
  for(i = 0; i < NUM_LEDS; i++) {
    leds[0][i] = CRGB::Black; 
    FastLED.show(); 
    //delay(100); 
    leds[1][i] = CRGB::Black; 
    FastLED.show(); 
   //delay(100);
    leds[2][i] = CRGB::Black;
    FastLED.show();
    delay(100);
  }
}
