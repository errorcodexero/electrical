#include "rainbow_stripes.h"

#include "util.h"
#include "assert.h"

void Rainbow_stripes::print()const{
	Serial.print("Rainbow_stripes");
}
void Rainbow_stripes::println()const{
	Serial.println("Rainbow_stripes");
}

void Rainbow_stripes::set_leds(const Robot_info& ROBOT_INFO, Lights& lights){
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);
	
	const unsigned LENGTH = 7;
	const unsigned GAP = 5;
	const unsigned HUE_DELTA = 30;
	
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
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
				CRGB color;
				color.setHue(colored * HUE_DELTA);
				return color;
			} 
			return CRGB(0,0,0);
		}();
		
		shift_leds(new_led, lights.get(led_index), Lights::LED_LENGTHS[led_index]);
	}
	FastLED.show();
}
