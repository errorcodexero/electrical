#include "util.h"

#include "assert.h"

void shift_leds(const CRGB NEW_LED,CRGB leds[], const unsigned NUMBER_OF_LEDS){
	for(int i = NUMBER_OF_LEDS - 1; i > 0; i--){
    	leds[i] = leds[i - 1];
	}
	leds[0] = NEW_LED;
}

CRGB alliance_to_color(const Robot_info::Alliance ALLIANCE){
	switch(ALLIANCE){
		case Robot_info::Alliance::RED:
			return CRGB::Red;
		case Robot_info::Alliance::BLUE:
			return CRGB::Blue;
		case Robot_info::Alliance::INVALID:
			return CRGB::Purple;
		default:
			assert(0);
	}
}

