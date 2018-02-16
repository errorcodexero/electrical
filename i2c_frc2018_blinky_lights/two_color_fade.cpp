#include "two_color_fade.h"

void Two_color_fade::print()const{
	Serial.print("Two_color_fade");
}
void Two_color_fade::println()const{
	Serial.println("Two_color_fade");
}

void Two_color_fade::set_leds(const Robot_info& ROBOT_INFO){//TODO
	fill_solid(leds,NUMBER_OF_LEDS,CRGB(0,0,0));
	
	FastLED.show();
}
