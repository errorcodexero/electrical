#include "fade.h"

void Fade::print()const{
	Serial.print("FADE");
}
void Fade::println()const{
	Serial.println("FADE");
}

void Fade::set_leds(const Robot_info& ROBOT_INFO){
	const double UPDATE_DELAY = .05;//slows the color changing by this percent
	CRGB color;
	color.setHue((int)(millis() * UPDATE_DELAY) % 255);
	fill_solid(leds,NUMBER_OF_LEDS,color);
	
	FastLED.show();
}
