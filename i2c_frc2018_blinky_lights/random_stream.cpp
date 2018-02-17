#include "random_stream.h"

#include "util.h"

void Random_stream::print()const{
	Serial.print("Random_stream");
}
void Random_stream::println()const{
	Serial.println("Random_stream");
}

void Random_stream::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	const unsigned GAP = 5;	

	CRGB new_led = [&]{
		unsigned gap = 0;
		for(unsigned i = 0; i < Light_constants::NUMBER_OF_LEDS; i++){
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
	shift_leds(new_led, leds, Light_constants::NUMBER_OF_LEDS);
	
	FastLED.show();
}
