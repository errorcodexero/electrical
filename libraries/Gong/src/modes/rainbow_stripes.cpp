#include "rainbow_stripes.h"

#include "../util/util.h"
#include "assert.h"

void Rainbow_stripes::print()const{
	Serial.print("Rainbow_stripes");
}
void Rainbow_stripes::println()const{
	Serial.println("Rainbow_stripes");
}

void Rainbow_stripes::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);
	
	const unsigned STRIPE_LENGTH = 7;
	const unsigned GAP = 5;
	const unsigned HUE_DELTA = 30;
	
	CRGB new_led = [&]{
		unsigned gap = 0;
		unsigned colored = 0;
		for(unsigned i = 0; i < LENGTH; i++){
			if(leds[i] != CRGB(0,0,0)){
				for(unsigned k = i; k < LENGTH; k++){
					if(leds[k] == CRGB(0,0,0)){
						break;
					}
					colored++;
				}
				break;
			}
			gap++;
		}
		if(gap >= GAP || colored < STRIPE_LENGTH){
			CRGB color;
			color.setHue(colored * HUE_DELTA);
			return color;
		} 
		return CRGB(0,0,0);
	}();
	
	shift_leds(new_led, leds, LENGTH);
	FastLED.show();
}
