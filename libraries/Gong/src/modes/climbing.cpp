#include "climbing.h"

#include "../util/util.h"
#include "assert.h"

Climbing::Climbing(unsigned s[]):strips(s){}

void Climbing::print()const{
	Serial.print("Climbing");
}
void Climbing::println()const{
	Serial.println("Climbing");
}

void Climbing::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const unsigned LENGTH = 3;
	const unsigned GAP = 5;
	const unsigned HUE_DELTA = 30;
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		//fill_solid(&leds[led_index],Lights::LED_LENGTHS[led_index],CRGB(red,0,blue));
		
		CRGB new_led = [&]{
			unsigned gap = 0;
			unsigned colored = 0;
			for(unsigned i = 0; i < Lights::LED_LENGTHS[led_index]; i++){
				if(lights.get(led_index)[i] != CRGB(0,0,0)){
					for(unsigned k = i; k < Lights::LED_LENGTHS[led_index]; k++){
						if(lights.get(led_index)[k] == CRGB(0,0,0)){
							break;
						}
						colored++;
					}
					break;
				}
				gap++;
			}
			if(gap >= GAP || colored < LENGTH){
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
		
		shift_leds(new_led, lights.get(led_index), Lights::LED_LENGTHS[led_index]);
	}
	FastLED.show();
}
