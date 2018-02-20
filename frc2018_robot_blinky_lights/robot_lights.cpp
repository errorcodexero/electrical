#include "robot_lights.h"

Robot_lights::Robot_lights(){
	for(unsigned i = 0; i < Robot_lights::Led_index::LEDS_; i++){
		if(){
			Serial.println("Error: LED array length is of size zero or less");
			assert(0);
		}
	}
	
	FastLED.addLeds<
		LED_CONTROLLER,
		Lights::LED_DATA_PINS[Lights::Led_index::LEFT_STRIP],
		COLOR_ORDER
	>(left_strip, Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP]);

	FastLED.addLeds<
		LED_CONTROLLER,
		Lights::LED_DATA_PINS[Lights::Led_index::RIGHT_STRIP],
		COLOR_ORDER
	>(right_strip, Lights::LED_LENGTHS[Lights::Led_index::RIGHT_STRIP]);
	
	FastLED.setBrightness(Lights::MAX_BRIGHTNESS);
}

double Robot_lights::leds_per_inch()const{
	return LEDS_PER_INCH;
}

unsigned Robot_lights::max_brightness()const{
	return MAX_BRIGHTNESS;
}
	
CRGB* Robot_lights::get(const unsigned STRIP){
	switch(STRIP){
		case Led_index::LEFT_STRIP:
			return left_strip;
		case Led_index::RIGHT_STRIP:
			return right_strip;
		default:
			assert(0);
	}
}

unsigned Robot_lights::data_pin(const unsigned STRIP){
	switch(STRIP){
		case Led_index::LEFT_STRIP:
			return LEFT_STRIP_DATA_PIN;
		case Led_index::RIGHT_STRIP:
			return RIGHT_STRIP_DATA_PIN:
		default:
			assert(0);
	}
}

unsigned Robot_lights::length(const unsigned){
	switch(STRIP){
		case Led_index::LEFT_STRIP:
			return LEFT_STRIP_LENGTH
		case Led_index::RIGHT_STRIP:
			return RIGHT_STRIP_LENGTH
	}
}
