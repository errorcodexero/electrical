#include "random_stream.h"

#include "../util/util.h"

void Random_stream::print()const{
	Serial.print("Random_stream");
}
void Random_stream::println()const{
	Serial.println("Random_stream");
}

void Random_stream::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const unsigned GAP = 5;	
	
	CRGB new_led = [&]{
		unsigned gap = 0;
		for(unsigned i = 0; i < LENGTH; i++){
			if(leds[i] != CRGB(0,0,0)){
				break;
			}
			gap++;
			if(gap >= GAP){
				CRGB color; 
				color.setHue(random(1,255));
				return color;
			} 
		}
		return CRGB(0,0,0);
	}();
	shift_leds(new_led, leds, LENGTH);
	FastLED.show();
}
