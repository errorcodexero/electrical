#include <FastLED.h>
#define DATA_PIN1    6
#define BRIGHTNESS   255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    24
CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN1, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS);


  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

}

void loop () {

  static uint8_t colorIndex;
  static int i = 0;

  leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
  colorIndex += 1;
  
  if (++i >= NUM_LEDS) {
    i = 0;
  }
  
  FastLED.show();
  delay (25);
 
}















