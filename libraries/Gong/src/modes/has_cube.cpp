#include "has_cube.h"

void Has_cube::print()const{
	Serial.print("Has_cube");
}
void Has_cube::println()const{
	Serial.println("Has_cube");
}

void Has_cube::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	fill_solid(leds,LENGTH,CRGB::Green);
	
	FastLED.show();
}
