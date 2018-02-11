#include "lights.h"
#include <assert.h>

Lights::Lights():mode(RECENTLY_ENABLED),wait_timer(),cycle_timer(){
	assert(NUMBER_OF_LEDS > 0);
}

void Lights::setup(){
	FastLED.addLeds<LED_CONTROLLER,LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
	FastLED.setBrightness(MAX_BRIGHTNESS);
	clear();
	randomSeed(millis());
}

void Lights::clear(){
	fill_solid(leds, NUMBER_OF_LEDS, CRGB::Black);
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
		case FADE:
			Serial.print("FADE");
			break;
		case RAINBOW_CHASE:
			Serial.print("RAINBOW_CHASE");
			break;
		default:
			Serial.print("ERROR:LIGHTS MODE DOES NOT EXIST");
	}
}

void Lights::color_recently_enabled(const Robot_info::Alliance ALLIANCE){
	if(wait_timer.get_now() % 2 == 0){//set color to black temporarily to flash color
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

void Lights::color_flame(){
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

void Lights::color_fade(){
	const double UPDATE_DELAY = .1;//slows the color changing by this percent

	const unsigned COLORS = 2;
	const unsigned COLOR_RANGE = 255 * 2;//255 per color, times two to fade in and out

	unsigned blue = [&]{
		unsigned color_picker = (int)(wait_timer.get_now() * UPDATE_DELAY) % (COLOR_RANGE * COLORS);
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
		unsigned color_picker = (int)(wait_timer.get_now() * UPDATE_DELAY) % (COLOR_RANGE * COLORS);
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
		int remainder = (int)(wait_timer.get_now() * UPDATE_DELAY) % 512;
		if(remainder < 256){
			return remainder ;
		} 
		return 512 - remainder ;
	}();
	const unsigned HUE_DELTA = 5;
	fill_rainbow(leds,NUMBER_OF_LEDS,hue,HUE_DELTA);
}

void Lights::set_leds(Robot_info const& ROBOT_INFO){
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
			const Lights::Mode FILLER_MODES[5] = {Lights::Mode::LIFTER_HEIGHT, Lights::Mode::FLAME, Lights::Mode::RANDOMIZED, Lights::Mode::FADE, Lights::Mode::RAINBOW_CHASE};
			Mode next_mode = FILLER_MODES[random(0, 5)];
			while(next_mode == last_mode){
				next_mode = FILLER_MODES[random(0, 5)];
			}
			return next_mode;
		}
		return last_mode;
	}();

	println_mode();

	if(last_mode != mode){
		clear();
		wait_timer.set(0);
		cycle_timer.set(10000);
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
		case FADE:
			color_fade();
			break;
		case RAINBOW_CHASE:
			color_rainbow_chase();
			break;
		default:
			assert(0);
	}

	FastLED.show();
	
	last_robot_info = ROBOT_INFO;
}

