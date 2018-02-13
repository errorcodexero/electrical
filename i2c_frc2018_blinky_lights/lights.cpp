#include "lights.h"
#include <assert.h>

Lights::Lights():mode_index(LIFTER_HEIGHT),mode(RECENTLY_ENABLED),wait_timer(),cycle_timer(){
	assert(NUMBER_OF_LEDS > 0);
	for(int& h: heat){
		h = 0;
	}
}

void Lights::setup(){
	FastLED.addLeds<LED_CONTROLLER,LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
	FastLED.setBrightness(MAX_BRIGHTNESS);
	clear();
	randomSeed(millis());
}

void Lights::clear(){
	FastLED.clear();
}

void Lights::println_mode()const{
	print_mode();
	Serial.print("\n");
}

void Lights::print_mode()const{
	switch(mode){
		case RECENTLY_ENABLED:
			Serial.print("RECENTLY_ENABLED");
			break;
		case AUTONOMOUS:
			Serial.print("AUTONOMOUS");
			break;
		case CLIMBING:
			Serial.print("CLIMBING");
			break;
		case LIFTER_HEIGHT:
			Serial.print("LIFTER_HEIGHT");
			break;
		case FLAME:
			Serial.print("FLAME");
			break;
		case RANDOMIZED:
			Serial.print("RANDOMIZED");
			break;
		case ALLIANCE_FADE:
			Serial.print("ALLIANCE_FADE");
			break;
		case RAINBOW_CHASE:
			Serial.print("RAINBOW_CHASE");
			break;
		case RAINBOW_STRIPES:
			Serial.print("RAINBOW_STRIPES");
			break;
		case FADE:
			Serial.print("FADE");
			break;
		case FLAME_STRIPES:
			Serial.print("FLAME_STRIPES");
			break;
		case OFF:
			Serial.print("OFF");
			break;
		default:
			Serial.print("ERROR:LIGHTS MODE DOES NOT EXIST");
	}
}

void Lights::shift_leds(const CRGB NEW_LED){
	CRGB last_leds[NUMBER_OF_LEDS];
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		last_leds[i] = leds[i];
	}
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		leds[i] = ((int)i - 1 >= 0) ? last_leds[i - 1] : NEW_LED;
	}
}

void Lights::color_recently_enabled(const Robot_info::Alliance ALLIANCE){
	if(millis() % 2 == 0){//set color to black temporarily to flash color
		clear();
		return;
	}
	CRGB COLOR = [&]{
		switch(ALLIANCE){
			case Robot_info::Alliance::RED:
				return CRGB::Red;
			case Robot_info::Alliance::BLUE:
				return CRGB::Blue;
			case Robot_info::Alliance::INVALID:
				return CRGB::Green;
			default:
				assert(0);
		}
	}();
	fill_solid(leds, NUMBER_OF_LEDS, COLOR);
}

void Lights::color_autonomous(){
	
}

void Lights::color_lifter_height(const unsigned LIFTER_HEIGHT){
	int led_height = LIFTER_HEIGHT * LEDS_PER_INCH;//number of leds to light up
	const CRGB COLOR = CRGB::Blue;
	clear();
	
	//fill_solid(leds, min(led_height, NUMBER_OF_LEDS), COLOR);
	leds[min(led_height, NUMBER_OF_LEDS - 1)] = COLOR;
}

void Lights::color_climbing(){
	
}

void Lights::color_flame(){//TODO
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
	CRGB last_leds[NUMBER_OF_LEDS];
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		last_leds[i] = leds[i];
	}
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		unsigned red = random(10, 255);
		unsigned green = random(0, red / 2);
		CRGB new_led = (random(0,3) != 0) ? CRGB(red,green,0) : leds[i];
		leds[i] = ((int)i - 1 >= 0) ? last_leds[i - 1] : new_led;
		leds[i].fadeToBlackBy(MAX_BRIGHTNESS / NUMBER_OF_LEDS);
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
}

void Lights::color_randomized(){
	if(wait_timer.done()){
		for(CRGB& led: leds){
			int r = random(0,255);
			int g = random(0,255);
			int b = random(0,255);
			led = CRGB(r, g, b);
		}
		wait_timer.set(100);
	}
}

void Lights::color_alliance_fade(){
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
}

void Lights::color_rainbow_chase(){
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
}

void Lights::color_rainbow_stripes(){
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);
	
	const unsigned LENGTH = 7;
	const unsigned NUMBER_OF_STRIPES = 2;
	const unsigned HUE_DELTA = 255.0 / LENGTH;
	
	CRGB new_led = [&]{
		const unsigned GAP = ((double)NUMBER_OF_LEDS / NUMBER_OF_STRIPES) - LENGTH;
	
		unsigned gap = 0;
		unsigned colored = 0;
		for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
			if(leds[i] != CRGB(0,0,0)){
				for(unsigned k = i; k < NUMBER_OF_LEDS; k++){
					if(leds[k] == CRGB(0,0,0)){
						break;
					}
					colored++;
				}
				break;
			}
			gap++;
		}
		if(gap >= GAP || colored < LENGTH){
			CRGB color;
			color.setHue(colored * HUE_DELTA);
			return color;
		} 
		return CRGB(0,0,0);
	}();
	
	shift_leds(new_led);
}

void Lights::color_random_stream(){
	const unsigned GAP = 5;	

	CRGB new_led = [&]{
		unsigned gap = 0;
		for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
			if(leds[i] != CRGB(0,0,0)){
				break;
			}
			gap++;
			if(gap >= GAP){
				CRGB color; 
				color.setHue(random(1,255));
				return color;
			} 
		}
		return CRGB(0,0,0);
	}();
	shift_leds(new_led);
}

void Lights::color_fade(){
	const double UPDATE_DELAY = .05;//slows the color chaning by this percent
	CRGB color;
	color.setHue((int)(millis() * UPDATE_DELAY) % 255);
	fill_solid(leds,NUMBER_OF_LEDS,color);
}

void Lights::color_flame_stripes(){//TODO
	if(!wait_timer.done()){
		return;
	}
	wait_timer.set(50);

	const unsigned LENGTH = 5;
	const unsigned STRIPES = 3;
	const unsigned HUES[STRIPES] = {0, 30, 60};
	
	static unsigned hue = 0;
	CRGB new_led = [&]{//Hue (red orange yellow) 0 30 60
		CRGB color;
		color.setHue(HUES[hue]);

		CRGB last = leds[1];
		if(last == CRGB(0, 0, 0)){
			return color;
		}
		
		unsigned colored = 0;
		for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
			if(leds[i] == last){
				colored++;
			} else {
				return color;
			}
			if(colored >= LENGTH){
				hue += 1;
				if(hue >= STRIPES){// -1 because the math uses stripes as 0-indexed
					hue = 0;
				}
				color.setHue(HUES[hue]);
				return color;
			}
		}
		//something went wrong
		return CRGB(0,0,0);
	}();
	shift_leds(new_led);
}

void Lights::set_leds(const Robot_info& ROBOT_INFO){
	const long CYCLE_TIME = 10000;
	wait_timer.update();
	cycle_timer.update();

	Mode last_mode = mode;
	mode = [&]{//pick mode to display
		if((last_mode == RECENTLY_ENABLED && !wait_timer.done()) || (ROBOT_INFO.enabled && !last_robot_info.enabled)){
			return RECENTLY_ENABLED;
		}
		if(ROBOT_INFO.climbing){
			//TODO
		}
		if(ROBOT_INFO.autonomous){
			//TODO
		}
		if(cycle_timer.done() ||
			(last_mode == RECENTLY_ENABLED && wait_timer.done())
		){
			mode_index++;
			if(mode_index >= OFF){
				mode_index = LIFTER_HEIGHT;
			}
			return (Lights::Mode)mode_index;
		}
		return last_mode;
	}();

	println_mode();

	if(last_mode != mode){
		clear();
		wait_timer.set(0);
		cycle_timer.set(CYCLE_TIME);
	}

	switch(mode){
		case RECENTLY_ENABLED: 
			if(last_mode != RECENTLY_ENABLED){
				wait_timer.set(1000);
			}
			color_recently_enabled(ROBOT_INFO.alliance);
			break;
		case AUTONOMOUS:
			color_autonomous();
			break;
		case LIFTER_HEIGHT:
			color_lifter_height(ROBOT_INFO.lifter_height);
			break;
		case CLIMBING:
			color_climbing();
			break;
		case FLAME:
			color_flame();
			break;
		case RANDOMIZED:
			color_randomized();
			break;
		case ALLIANCE_FADE:
			color_alliance_fade();
			break;
		case RAINBOW_CHASE:
			color_rainbow_chase();
			break;
		case RAINBOW_STRIPES:
			color_rainbow_stripes();
			break;
		case RANDOM_STREAM:
			color_random_stream();
			break;
		case FADE:
			color_fade();
			break;
		case FLAME_STRIPES:
			color_flame_stripes();
			break;
		case OFF:
			clear();
			break;
		default:
			assert(0);
	}

	FastLED.show();
	
	last_robot_info = ROBOT_INFO;
}

