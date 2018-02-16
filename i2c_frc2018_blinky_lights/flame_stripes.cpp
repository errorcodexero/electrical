#include "flame_stripes.h"

#include "util.h"

void Flame_stripes::print()const{
	Serial.print("Flame_stripes");
}
void Flame_stripes::println()const{
	Serial.println("Flame_stripes");
}

void Flame_stripes::set_leds(const Robot_info& ROBOT_INFO){
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);

	const unsigned LENGTH = 5;
	const unsigned STRIPES = 3;
	const unsigned HUES[STRIPES] = {45, 26, 0};//colors in reverse order - red orange yellow
	
	static unsigned hue = 0;
	CRGB new_led = [&]{
		CRGB color;
		color.setHue(HUES[hue]);

		CRGB last = leds[1];
		if(last == CRGB(0, 0, 0)){
			return color;
		}
		
		unsigned colored = 0;
		for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
			if(leds[i] == last){
				colored++;
			} else {
				return color;
			}
			if(colored >= LENGTH){
				hue += 1;
				if(hue >= STRIPES){// -1 because the math uses stripes as 0-indexed
					hue = 0;
				}
				color.setHue(HUES[hue]);
				return color;
			}
		}
		//something went wrong
		return CRGB(0,0,0);
	}();
	shift_leds(new_led, leds, Light_mode_base::NUMBER_OF_LEDS);
	
	FastLED.show();
}
