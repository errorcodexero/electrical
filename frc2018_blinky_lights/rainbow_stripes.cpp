#include "rainbow_stripes.h"

#include "util.h"
#include "assert.h"

void Rainbow_stripes::print()const{
	Serial.print("Rainbow_stripes");
}
void Rainbow_stripes::println()const{
	Serial.println("Rainbow_stripes");
}

void Rainbow_stripes::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);
	
	const unsigned LENGTH = 7;
	const unsigned NUMBER_OF_STRIPES = 2;
	const unsigned HUE_DELTA = 255.0 / LENGTH;
	
	CRGB new_led = [&]{
		const unsigned GAP = [&]{
				int a = ((double)Light_constants::NUMBER_OF_LEDS / NUMBER_OF_STRIPES) - LENGTH;
				assert(a >= 0);
				return a;
		}();
	
		unsigned gap = 0;
		unsigned colored = 0;
		for(unsigned i = 0; i < Light_constants::NUMBER_OF_LEDS; i++){
			if(leds[i] != CRGB(0,0,0)){
				for(unsigned k = i; k < Light_constants::NUMBER_OF_LEDS; k++){
					if(leds[k] == CRGB(0,0,0)){
						break;
					}
					colored++;
				}
				break;
			}
			gap++;
		}
		if(gap >= GAP || colored < LENGTH){
			CRGB color;
			color.setHue(colored * HUE_DELTA);
			return color;
		} 
		return CRGB(0,0,0);
	}();
	
	shift_leds(new_led, leds, Light_constants::NUMBER_OF_LEDS);
	
	FastLED.show();
}
