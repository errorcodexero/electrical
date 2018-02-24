#include "autonomous.h"

Autonomous::Autonomous(unsigned s[]):strips(s){}

void Autonomous::print()const{
	Serial.print("Autonomous");
}
void Autonomous::println()const{
	Serial.println("Autonomous");
}

void Autonomous::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const int HALFWAY_UP_LEFT = Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP] * 0.5;
	const int HALFWAY_UP_RIGHT = Lights::LED_LENGTHS[Lights::Led_index::RIGHT_STRIP] * 0.5;

	int left_led_height = Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP]  * 0.5 + (Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP] * 0.5) * ROBOT_INFO.drive_left;//number of leds to light up
	int right_led_height = Lights::LED_LENGTHS[Lights::Led_index::RIGHT_STRIP] * 0.5 + (Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP] * 0.5) * ROBOT_INFO.drive_right;

	CRGB color;

	color.setHue(hue);
	hue += 5;
	if(hue > 255){
		hue = 0;
	}
	
	clear(lights);

	for(unsigned i = HALFWAY_UP_LEFT + min(0, HALFWAY_UP_LEFT * ROBOT_INFO.drive_left); i < HALFWAY_UP_LEFT + max(0, HALFWAY_UP_LEFT * ROBOT_INFO.drive_left); i++){
		lights.get(Lights::Led_index::LEFT_STRIP)[i] = color;
	}

	for(unsigned i = HALFWAY_UP_RIGHT + min(0, HALFWAY_UP_RIGHT * ROBOT_INFO.drive_left); i < HALFWAY_UP_RIGHT + max(0, HALFWAY_UP_RIGHT * ROBOT_INFO.drive_left); i++){
		lights.get(Lights::Led_index::RIGHT_STRIP)[i] = color;
	}

	FastLED.show();
}
