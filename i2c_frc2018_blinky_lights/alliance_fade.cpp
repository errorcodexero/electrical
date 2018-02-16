#include "alliance_fade.h"

void Alliance_fade::print()const{
	Serial.print("Alliance_fade");
}
void Alliance_fade::println()const{
	Serial.println("Alliance_fade");
}

void Alliance_fade::set_leds(const Robot_info& ROBOT_INFO){
	const double UPDATE_DELAY = .1;//slows the color changing by this percent

	const unsigned COLORS = 2;
	const unsigned COLOR_RANGE = 255 * 2;//255 per color, times two to fade in and out

	unsigned blue = [&]{
		unsigned color_picker = (int)(millis() * UPDATE_DELAY) % (COLOR_RANGE * COLORS);
		if(color_picker > 0 * COLOR_RANGE && color_picker < 1 * COLOR_RANGE){
			unsigned remainder = color_picker % COLOR_RANGE;
			if(remainder < 256){
			 return remainder % 256;
			}
			return (COLOR_RANGE - remainder) % 256;
		}
		return (unsigned)0;
	}();
	unsigned red = [&]{
		unsigned color_picker = (int)(millis() * UPDATE_DELAY) % (COLOR_RANGE * COLORS);
		if(color_picker > 1 * COLOR_RANGE && color_picker < 2 * COLOR_RANGE){
			unsigned remainder = color_picker % COLOR_RANGE;
			if(remainder < 256){
			 return remainder % 256;
			}
			return (COLOR_RANGE - remainder) % 256;
		}
		return (unsigned)0;
	}();
	fill_solid(leds,NUMBER_OF_LEDS,CRGB(red,0,blue));
	
	FastLED.show();
}
