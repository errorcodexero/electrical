#include "flame_stripes.h"

#include "../util/util.h"

Flame_stripes::Flame_stripes(unsigned s[]):strips(s){}

void Flame_stripes::print()const{
	Serial.print("Flame_stripes");
}
void Flame_stripes::println()const{
	Serial.println("Flame_stripes");
}

void Flame_stripes::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);

	const unsigned LENGTH = 5;
	const unsigned STRIPES = 3;
	const unsigned HUES[STRIPES] = {45, 26, 0};//colors in reverse order - red orange yellow
	
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		CRGB new_led = [&]{
			CRGB color;
			color.setHue(HUES[hue]);
	
			CRGB last = lights.get(led_index)[1];
			if(last == CRGB(0, 0, 0)){
				return color;
			}
			
			unsigned colored = 0;
			for(unsigned i = 0; i < Lights::LED_LENGTHS[led_index]; i++){
				if(lights.get(led_index)[i] == last){
					colored++;
				} else {
					return color;
				}
				if(colored >= LENGTH){
					hue += 1;
					if(hue > STRIPES - 1){// -1 because the math uses stripes as 0-indexed
						hue = 0;
					}
					color.setHue(HUES[hue]);
					return color;
				}
			}
			//something went wrong
			return CRGB(0,0,0);
		}();
		shift_leds(new_led, lights.get(led_index), Lights::LED_LENGTHS[led_index]);
	}

	FastLED.show();
}
