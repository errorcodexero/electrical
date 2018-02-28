#include "light_strip.h"

#include "assert.h"

Light_strip::Light_strip(const unsigned LENGTH, const uint8_t DATA_PIN):length_(LENGTH),data_pin_(DATA_PIN){
	if(LENGTH <= 0){
		Serial.println("Error: LED array length is of size zero or less");
		assert(0);
	}
	
	leds = new CRGB[LENGTH];
	
	FastLED.addLeds<
		LED_CONTROLLER,
		DATA_PIN,
		COLOR_ORDER
	>(leds, LENGTH);
}

unsigned Light_strip::length()const{
	return length_;
}

uint8_t Light_strip::data_pin()const{
	return data_pin_;
}

void Light_strip::println()const{
	light_mode -> println();
}

void Light_strip::print()const{
	light_mode -> print();
}

void Light_strip::set_mode(Light_mode_base* new_mode){
	light_mode = new_mode;
}

void Light_strip::set_leds(const Robot_info& ROBOT_INFO){
	light_mode -> set_leds(leds, length(), ROBOT_INFO);
}