#include "has_cube.h"

Has_cube::Has_cube(unsigned s[]):strips(s){}

void Has_cube::print()const{
	Serial.print("Has_cube");
}
void Has_cube::println()const{
	Serial.println("Has_cube");
}

void Has_cube::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		fill_solid(lights.get(led_index),Lights::LED_LENGTHS[led_index],CRGB::Green);
	}
	
	FastLED.show();
}
