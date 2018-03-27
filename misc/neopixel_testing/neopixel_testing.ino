#include <FastLED.h>

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
const unsigned LED_COUNT =12;
const uint8_t BRIGHTNESS = 255 * 0.15;

const unsigned PIN_OUT = 7;

const unsigned BLINK_DELAY = 100;

CRGB leds[LED_COUNT];

void setup(){
	FastLED.addLeds<LED_TYPE,PIN_OUT,COLOR_ORDER>(leds, LED_COUNT);
	FastLED.setBrightness(BRIGHTNESS);
}

void loop(){
	fill_solid(leds, LED_COUNT, CRGB::Green);
	FastLED.show();
	delay(BLINK_DELAY);
	FastLED.clear();
	FastLED.show();
	delay(BLINK_DELAY);
}
