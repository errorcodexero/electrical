#include "fade.h"

Fade::Fade(unsigned s[]):strips(s){}

void Fade::print()const{
	Serial.print("FADE");
}
void Fade::println()const{
	Serial.println("FADE");
}

void Fade::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){
	const double UPDATE_DELAY = .05;//slows the color changing by this percent
	CRGB color;
	color.setHue((int)(millis() * UPDATE_DELAY) % 255);
	for(unsigned led_index = 0; led_index < Lights::Led_index::LEDS_; led_index++){
		fill_solid(lights.get(led_index),Lights::LED_LENGTHS[led_index],color);
	}
	
	FastLED.show();
}
