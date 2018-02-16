#include "light_mode_base.h"
#include "assert.h"

void Light_mode_base::clear(){
	FastLED.clear();
}

void Light_mode_base::setup(){
	assert(NUMBER_OF_LEDS > 0);
	FastLED.addLeds<LED_CONTROLLER,LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
	FastLED.setBrightness(MAX_BRIGHTNESS);
	clear();
	randomSeed(millis());
}
