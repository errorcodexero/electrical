#include "light_mode_base.h"
#include "assert.h"

void Light_mode_base::clear(CRGB leds[], const unsigned LEN){
	fill_solid(leds,LEN,CRGB::Black);
	FastLED.show();
}

void Light_mode_base::clear(Lights& lights){
	for(unsigned i = 0; i < Lights::Led_index::LEDS_; i++){
		clear(lights.get(i), Lights::LED_LENGTHS[i]);
	}
}

