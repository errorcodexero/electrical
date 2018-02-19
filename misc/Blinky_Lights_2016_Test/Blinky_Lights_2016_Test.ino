#include "FastLED.h"

#define DATA_PIN1    4
#define DATA_PIN2    5
#define USER_LED     13
#define BRIGHTNESS   100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    4

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN1,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN2,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(USER_LED, OUTPUT);
}

void loop() {
  static bool heartbeat = false;
  int i; 
  for (i = 0; i < NUM_LEDS; i++) {
    leds[i] = 0xff6600;
    FastLED.show(); 
    delay(100);
  }
  for (i = 0; i < NUM_LEDS; i++) {
    leds[i] = 0x000000;
    FastLED.show();
    delay(100);
  }
  heartbeat = !heartbeat;
  digitalWrite(USER_LED, heartbeat);
}

