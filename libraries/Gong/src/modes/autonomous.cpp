#include "autonomous.h"

void Autonomous::print()const{
	Serial.print("Autonomous");
}
void Autonomous::println()const{
	Serial.println("Autonomous");
}

void Autonomous::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const int HALFWAY = LENGTH * 0.5;

	int led_height = HALFWAY + HALFWAY * ROBOT_INFO.drive_left;//number of leds to light up

	CRGB color;

	color.setHue(hue);
	hue += 5;
	if(hue > 255){
		hue = 0;
	}
	
	clear(leds,LENGTH);

	for(unsigned i = HALFWAY + min(0, HALFWAY * ROBOT_INFO.drive_left); i < HALFWAY + max(0, HALFWAY * ROBOT_INFO.drive_left); i++){
		leds[i] = color;
	}

	FastLED.show();
}
