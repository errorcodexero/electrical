#include "light_mode_base.h"
#include "assert.h"

void Light_mode_base::clear(CRGB* leds, const unsigned LEN){
	fill_solid(leds, LEN, CRGB::Black);
	FastLED.show();
}