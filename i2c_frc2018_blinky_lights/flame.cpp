#include "flame.h"

void Flame::print()const{
	Serial.print("Flame");
}
void Flame::println()const{
	Serial.println("Flame");
}

void Flame::set_leds(const Robot_info& ROBOT_INFO, CRGB leds[]){
	/*
	for(unsigned i = NUMBER_OF_LEDS - 1; i -2 > 0; i--){
		heat[i] = min(255, max(0, (heat[i - 1] + heat[i - 2] + heat[i - 2] ) / 3.0));
		heat[i] = min(255, max(0, heat[i] - random(255.0 / NUMBER_OF_LEDS, 2.0 * 255.0 / NUMBER_OF_LEDS)));
	}
	for(unsigned i = 0; i < min(3, NUMBER_OF_LEDS); i++){
		if(random(0,9) > 0){
			heat[i] = random(180, 255);
		}
	}
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		CRGB color;
		if(heat[i] > 240){
			color = CRGB(heat[i], heat[i],heat[i] - 100);
		} else if(heat[i] > 200){
			color = CRGB(heat[i], heat[i] - 15, heat[i] - 150);
		} else if(heat[i] > 150){
			color = CRGB(heat[i], heat[i] - 70,0);
		} else if(heat[i] > 100){
			color = CRGB(heat[i], heat[i] - 80,0);
			color.fadeToBlackBy(70);
		} else if(heat[i] > 50){
			color = CRGB(heat[i], 0,0);
			color.fadeToBlackBy(120);
		} else {
			color = CRGB(0,0,0);
		}
		leds[i] = color;
		Serial.println(heat[i]);
	}
	
	*/
	
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(100);
	CRGB last_leds[Light_constants::NUMBER_OF_LEDS];
	for(unsigned i = 0; i < Light_constants::NUMBER_OF_LEDS; i++){
		last_leds[i] = leds[i];
	}
	for(unsigned i = 0; i < Light_constants::NUMBER_OF_LEDS; i++){
		unsigned red = random(10, 255);
		unsigned green = random(0, red / 2);
		CRGB new_led = (random(0,3) != 0) ? CRGB(red,green,0) : leds[i];
		leds[i] = ((int)i - 1 >= 0) ? last_leds[i - 1] : new_led;
		leds[i].fadeToBlackBy(Light_constants::MAX_BRIGHTNESS / Light_constants::NUMBER_OF_LEDS);
	}
	
	/*
	double green_segment_size = random(3, 5);
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		unsigned red = (255 / NUMBER_OF_LEDS) * (NUMBER_OF_LEDS - i);
		if(random(0,20) == 0){
			red *= 0.5;
		}
		unsigned green = [&]{
			if(i < NUMBER_OF_LEDS * (1.0 / green_segment_size)){
				return random(0, red / 7);
			}
			if(i < NUMBER_OF_LEDS * (2.0 / green_segment_size)){
				return random(0, red / 4);
			}
			return random(0, red / 2);
		}();
		leds[i] = CRGB(red, green, 0);
	}
	*/
	
	FastLED.show();
}
