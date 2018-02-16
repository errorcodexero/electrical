#include "util.h"

void shift_leds(const CRGB NEW_LED,CRGB leds[], const unsigned NUMBER_OF_LEDS){
	CRGB last_leds[NUMBER_OF_LEDS];
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		last_leds[i] = leds[i];
	}
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		leds[i] = ((int)i - 1 >= 0) ? last_leds[i - 1] : NEW_LED;
	}
}
