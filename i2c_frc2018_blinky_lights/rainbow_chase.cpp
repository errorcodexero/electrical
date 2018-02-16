#include "rainbow_chase.h"

void Rainbow_chase::print()const{
	Serial.print("Rainbow_chase");
}
void Rainbow_chase::println()const{
	Serial.println("Rainbow_chase");
}

void Rainbow_chase::set_leds(const Robot_info& ROBOT_INFO){
	const double UPDATE_DELAY = .1;//slows the color chaning by this percent

	unsigned hue = [&]{
		int remainder = (int)(millis() * UPDATE_DELAY) % 512;
		if(remainder < 256){
			return remainder ;
		} 
		return 512 - remainder ;
	}();
	const unsigned HUE_DELTA = 5;
	fill_rainbow(leds,NUMBER_OF_LEDS,hue,HUE_DELTA);
	
	FastLED.show();
}
