#include "recently_enabled.h"

#include "assert.h"
#include "../util/util.h"

void Recently_enabled::print()const{
	Serial.print("Recently_enabled");
}
void Recently_enabled::println()const{
	Serial.println("Recently_enabled");
}

void Recently_enabled::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	if(millis() % 50 > 25){//set color to black temporarily to flash color
		clear(leds,LENGTH);
		Serial.println("clear");
		return;
	}
	CRGB COLOR = alliance_to_color(ROBOT_INFO.alliance);

	fill_solid(leds, LENGTH, COLOR);

	FastLED.show();
}
