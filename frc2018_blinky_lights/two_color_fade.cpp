#include "two_color_fade.h"

Two_color_fade::Two_color_fade():blue(0),rise(true){}

void Two_color_fade::print()const{
	Serial.print("Two_color_fade");
}
void Two_color_fade::println()const{
	Serial.println("Two_color_fade");
}

void Two_color_fade::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){//TODO
	const int COLOR_MAX = 255;
	const int INCREMENT = 10;
	if(blue_timer.done()){
		blue_timer.set(0);
		if(rise){
			blue += INCREMENT;
		} else {
			blue -= INCREMENT;
		}
		if(blue < 0 || blue > COLOR_MAX){
			blue_timer.set(1000);
			if(blue > COLOR_MAX){
				rise = false;
				blue = COLOR_MAX;
			} else if(blue < 0){
				rise = true;
				blue = 0;
			}
		}
	}
	unsigned red = 255 - blue;

	fill_solid(leds,Light_constants::NUMBER_OF_LEDS,CRGB(red,0,blue));
	
	FastLED.show();
}
