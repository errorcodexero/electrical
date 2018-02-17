#include "climbing.h"

void Climbing::print()const{
	Serial.print("Climbing");
}
void Climbing::println()const{
	Serial.println("Climbing");
}

void Climbing::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	//TODO
	
	FastLED.show();
}
