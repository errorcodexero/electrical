#include "recently_enabled.h"

#include "assert.h"

void Recently_enabled::print()const{
	Serial.print("Recently_enabled");
}
void Recently_enabled::println()const{
	Serial.println("Recently_enabled");
}

void Recently_enabled::set_leds(const Robot_info& ROBOT_INFO){
	if(millis() % 2 == 0){//set color to black temporarily to flash color
		clear();
		return;
	}
	CRGB COLOR = [&]{
		switch(ROBOT_INFO.alliance){
			case Robot_info::Alliance::RED:
				return CRGB::Red;
			case Robot_info::Alliance::BLUE:
				return CRGB::Blue;
			case Robot_info::Alliance::INVALID:
				return CRGB::Green;
			default:
				assert(0);
		}
	}();
	fill_solid(leds, NUMBER_OF_LEDS, COLOR);
	
	FastLED.show();
}
