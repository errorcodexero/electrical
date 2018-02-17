#include "randomized.h"

void Randomized::print()const{
	Serial.print("Randomized");
}
void Randomized::println()const{
	Serial.println("Randomized");
}

void Randomized::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){//TODO
	if(wait_timer.done()){
		for(unsigned i = 0; i < Light_constants::NUMBER_OF_LEDS; i++){
			CRGB& led = leds[i];
			int r = random(0,255);
			int g = random(0,255);
			int b = random(0,255);
			led = CRGB(r, g, b);
		}
		wait_timer.set(100);
	}
	
	FastLED.show();
}
