#include "lifter_height.h"

void Lifter_height::print()const{
	Serial.print("Lifter_height");
}
void Lifter_height::println()const{
	Serial.println("Lifter_height");
}

void Lifter_height::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	int led_height = ROBOT_INFO.lifter_height * Light_constants::LEDS_PER_INCH;//number of leds to light up
	const CRGB COLOR = CRGB::Blue;
	clear(leds);
	
	//fill_solid(leds, min(led_height, NUMBER_OF_LEDS), COLOR);
	leds[min(led_height, Light_constants::NUMBER_OF_LEDS - 1)] = COLOR;
	
	FastLED.show();
}
