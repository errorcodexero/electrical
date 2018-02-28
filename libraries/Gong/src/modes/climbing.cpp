#include "climbing.h"

#include "../util/util.h"
#include "assert.h"

void Climbing::print()const{
	Serial.print("Climbing");
}
void Climbing::println()const{
	Serial.println("Climbing");
}

void Climbing::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const unsigned STRIPE_LENGTH = 3;
	const unsigned GAP = 5;
	const unsigned HUE_DELTA = 30;
	//fill_solid(leds,LENGTH,CRGB(red,0,blue));
		
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
			if(gap >= GAP){
				hue += HUE_DELTA;
				if(hue > 255){
					hue = 0;
				}
			}
			CRGB color;
			color.setHue(hue);
			return color;
		} 
		return CRGB(0,0,0);
	}();
	
	shift_leds(new_led, leds, LENGTH);
	FastLED.show();
}
