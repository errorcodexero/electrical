#include "off.h"

void Off::print()const{
	Serial.print("Off");
}
void Off::println()const{
	Serial.println("Off");
}

void Off::set_leds(const Robot_info& ROBOT_INFO, Lights& lights){
	clear(lights);
	
	FastLED.show();
}
