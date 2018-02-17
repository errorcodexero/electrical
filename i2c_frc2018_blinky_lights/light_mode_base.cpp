#include "light_mode_base.h"
#include "assert.h"

void Light_mode_base::clear(CRGB leds[]){
	fill_solid(leds, Light_constants::NUMBER_OF_LEDS, CRGB::Black);
	FastLED.show();
}

