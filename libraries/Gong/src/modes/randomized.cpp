#include "randomized.h"

void Randomized::print()const{
	Serial.print("Randomized");
}
void Randomized::println()const{
	Serial.println("Randomized");
}

void Randomized::set_leds(CRGB* leds,const unsigned LENGTH,const Robot_info& ROBOT_INFO){//TODO
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(100);
	for(unsigned i = 0; i < LENGTH; i++){
		CRGB& led = leds[i];
		int r = random(0,255);
		int g = random(0,255);
		int b = random(0,255);
		led = CRGB(r, g, b);
	}
	
	FastLED.show();
}
