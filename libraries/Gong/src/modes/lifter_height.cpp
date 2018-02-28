#include "lifter_height.h"

#include "../util/util.h"

void Lifter_height::print()const{
	Serial.print("Lifter_height");
}
void Lifter_height::println()const{
	Serial.println("Lifter_height");
}

void Lifter_height::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	int led_height = ROBOT_INFO.lifter_height * Light_strip_constants::LEDS_PER_INCH;//number of leds to light up
	const CRGB COLOR = alliance_to_color(ROBOT_INFO.alliance);

	//fill_solid(leds, LENGTH, ABOVE_HEIGHT_COLOR);
	//fill_solid(leds, min(led_height, LENGTH), BELOW_HEIGHT_COLOR);
	const unsigned STRIPE_LENGTH = 5;

	clear(leds,LENGTH);

	unsigned start = min(led_height, LENGTH - 1);
	
	for(unsigned i = start; i < min(start + STRIPE_LENGTH, LENGTH); i++){
		leds[i] = COLOR;
	}

	
	FastLED.show();
}
