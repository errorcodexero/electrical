#include "off.h"

void Off::print()const{
	Serial.print("Off");
}
void Off::println()const{
	Serial.println("Off");
}

void Off::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	clear(leds);
	
	FastLED.show();
}
