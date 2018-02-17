#include "autonomous.h"

Autonomous::Autonomous():dot(HALF){}

void Autonomous::print()const{
	Serial.print("Autonomous");
}
void Autonomous::println()const{
	Serial.println("Autonomous");
}

void Autonomous::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	int left_led_height = Light_constants::NUMBER_OF_LEDS * 0.5 + (Light_constants::NUMBER_OF_LEDS * 0.5) * ROBOT_INFO.drive_left;//number of leds to light up
	int right_led_height = Light_constants::NUMBER_OF_LEDS * 0.5 + (Light_constants::NUMBER_OF_LEDS * 0.5) * ROBOT_INFO.drive_right;

	if(color_timer.done()){
		color.setHue(random(0, 255));
		color_timer.set(1000);
	}
	clear(leds);

	for(unsigned i = HALF + min(0, HALF * ROBOT_INFO.drive_left); i < HALF + max(0, HALF * ROBOT_INFO.drive_left); i++){
		leds[i] = color;
	}

	leds[dot] = CRGB::White;
	
	if(ROBOT_INFO.drive_left <= 0){
		dot--;
	} else {
		dot++;
	}
	if((ROBOT_INFO.drive_left <= 0 && dot <= left_led_height) ||
	    (ROBOT_INFO.drive_left > 0 && dot >= left_led_height)
	){
		dot = HALF;
	}

	FastLED.show();
}
