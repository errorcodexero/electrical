#include "autonomous.h"

void Autonomous::print()const{
	Serial.print("Autonomous");
}
void Autonomous::println()const{
	Serial.println("Autonomous");
}

void Autonomous::set_leds(const Robot_info& ROBOT_INFO){
	int left_led_height = NUMBER_OF_LEDS *0.5 + (NUMBER_OF_LEDS * 0.5) * ROBOT_INFO.drive_left;//number of leds to light up
	int right_led_height = NUMBER_OF_LEDS *0.5 + (NUMBER_OF_LEDS * 0.5) * ROBOT_INFO.drive_right;
	const CRGB COLOR = CRGB::Blue;
	clear();
	
	fill_solid(leds, left_led_height, CRGB::Red);
	
	FastLED.show();
}
