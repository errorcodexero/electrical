#include "recently_enabled.h"

#include "assert.h"
#include "../util/util.h"

void Recently_enabled::print()const{
	Serial.print("Recently_enabled");
}
void Recently_enabled::println()const{
	Serial.println("Recently_enabled");
}

void Recently_enabled::set_leds(const Robot_info& ROBOT_INFO, Lights& lights){
	if(millis() % 50 > 25){//set color to black temporarily to flash color
		clear(lights);
		Serial.println("clear");
		return;
	}
	CRGB COLOR = alliance_to_color(ROBOT_INFO.alliance);
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		fill_solid(lights.get(led_index), Lights::LED_LENGTHS[led_index], COLOR);
	}
	FastLED.show();
}
