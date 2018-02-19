#include "lifter_height.h"

#include "../util/util.h"

void Lifter_height::print()const{
	Serial.print("Lifter_height");
}
void Lifter_height::println()const{
	Serial.println("Lifter_height");
}

void Lifter_height::set_leds(const Robot_info& ROBOT_INFO, Lights& lights){
	int led_height = ROBOT_INFO.lifter_height * Lights::LEDS_PER_INCH;//number of leds to light up
	const CRGB COLOR = alliance_to_color(ROBOT_INFO.alliance);

	//fill_solid(leds, Lights::NUMBER_OF_LEDS, ABOVE_HEIGHT_COLOR);
	//fill_solid(leds, min(led_height, Lights::NUMBER_OF_LEDS), BELOW_HEIGHT_COLOR);
	const unsigned LENGTH = 5;

	clear(lights);

	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		
		unsigned start = min(led_height, Lights::LED_LENGTHS[led_index] - 1);

		for(unsigned i = start; i < min(start + LENGTH, Lights::LED_LENGTHS[led_index]); i++){
			lights.get(led_index)[i] = COLOR;
		}
	}
	
	FastLED.show();
}
