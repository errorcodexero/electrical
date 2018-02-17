#include "has_cube.h"

void Has_cube::print()const{
	Serial.print("Has_cube");
}
void Has_cube::println()const{
	Serial.println("Has_cube");
}

void Has_cube::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	fill_solid(leds, Light_constants::NUMBER_OF_LEDS, CRGB::Green);
	
	FastLED.show();
}