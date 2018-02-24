#include "random_stream.h"

#include "../util/util.h"

Random_stream::Random_stream(unsigned s[]):strips(s){}

void Random_stream::print()const{
	Serial.print("Random_stream");
}
void Random_stream::println()const{
	Serial.println("Random_stream");
}

void Random_stream::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const unsigned GAP = 5;	
	
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		CRGB new_led = [&]{
			unsigned gap = 0;
			for(unsigned i = 0; i < Lights::LED_LENGTHS[led_index]; i++){
				if(lights.get(led_index)[i] != CRGB(0,0,0)){
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
		shift_leds(new_led, lights.get(led_index), Lights::LED_LENGTHS[led_index]);
	}
	FastLED.show();
}
