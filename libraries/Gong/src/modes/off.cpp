#include "off.h"

Off::Off(unsigned s[]):strips(s){}

void Off::print()const{
	Serial.print("Off");
}
void Off::println()const{
	Serial.println("Off");
}

void Off::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	for(unsigned i = 0; i < sizeof(STRIPS) / sizeof(STRIPS[0]); i++){
		clear(lights);
	}
	
	FastLED.show();
}
