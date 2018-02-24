#include "rainbow_chase.h"

Rainbow_chase::Rainbow_chase(unsigned s[]):strips(s){}

void Rainbow_chase::print()const{
	Serial.print("Rainbow_chase");
}
void Rainbow_chase::println()const{
	Serial.println("Rainbow_chase");
}

void Rainbow_chase::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const double UPDATE_DELAY = .1;//slows the color chaning by this percent

	unsigned hue = [&]{
		int remainder = (int)(millis() * UPDATE_DELAY) % 512;
		if(remainder < 256){
			return remainder ;
		} 
		return 512 - remainder ;
	}();
	const unsigned HUE_DELTA = 5;
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		fill_rainbow(lights.get(led_index),Lights::LED_LENGTHS[led_index],hue,HUE_DELTA);
	}
	
	FastLED.show();
}
