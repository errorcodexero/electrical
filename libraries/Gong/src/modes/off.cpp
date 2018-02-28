#include "off.h"

void Off::print()const{
	Serial.print("Off");
}
void Off::println()const{
	Serial.println("Off");
}

void Off::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	clear(leds,LENGTH);
	
	FastLED.show();
}
