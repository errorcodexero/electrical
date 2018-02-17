#include "lights.h"
#include <assert.h>

#include "alliance_fade.h"
#include "autonomous.h"
#include "climbing.h"
#include "fade.h"
#include "flame.h"
#include "flame_stripes.h"
#include "has_cube.h"
#include "lifter_height.h"
#include "off.h"
#include "rainbow_chase.h"
#include "rainbow_stripes.h"
#include "randomized.h"
#include "random_stream.h"
#include "recently_enabled.h"
#include "two_color_fade.h"

Lights::Lights():mode_index(random(LIFTER_HEIGHT, OFF)),mode(OFF),light_mode(new Off()){}

void Lights::setup(){
	assert(Light_constants::NUMBER_OF_LEDS > 0);
	FastLED.addLeds<LED_CONTROLLER,Light_constants::LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, Light_constants::NUMBER_OF_LEDS);
	FastLED.setBrightness(Light_constants::MAX_BRIGHTNESS);
}

void Lights::println_mode()const{
	light_mode -> println();
}

void Lights::print_mode()const{
	light_mode -> print();
}

void Lights::set_leds(const Robot_info& ROBOT_INFO){
	const long CYCLE_TIME = 10000;

	Mode last_mode = mode;
	mode = [&]{//pick mode to display
		if((last_mode == RECENTLY_ENABLED && !cycle_timer.done()) ||
		   (ROBOT_INFO.enabled && !last_robot_info.enabled)){
			return RECENTLY_ENABLED;
		}
		if(ROBOT_INFO.has_cube){
			return HAS_CUBE;
		}
		if(ROBOT_INFO.climbing){
			return CLIMBING;
		}
		if(ROBOT_INFO.autonomous){
			return AUTONOMOUS;
		}
		if(cycle_timer.done()){
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
		cycle_timer.set(CYCLE_TIME);
		
		switch(mode){
			case RECENTLY_ENABLED:
				if(last_mode != RECENTLY_ENABLED){
					cycle_timer.set(2000);
				}
				light_mode = new Recently_enabled();
				break;
			case AUTONOMOUS:
				light_mode = new Autonomous();
				break;
			case HAS_CUBE:
				light_mode = new Has_cube();
				break;
			case LIFTER_HEIGHT:
				light_mode = new Lifter_height();
				break;
			case CLIMBING:
				light_mode = new Climbing();
				break;
			case FLAME:
				light_mode = new Flame();
				break;
			case RANDOMIZED:
				light_mode = new Randomized();
				break;
			case ALLIANCE_FADE:
				light_mode = new Alliance_fade();
				break;
			case RAINBOW_CHASE:
				light_mode = new Rainbow_chase();
				break;
			case RAINBOW_STRIPES:
				light_mode = new Rainbow_stripes();
				break;
			case RANDOM_STREAM:
				light_mode = new Random_stream();
				break;
			case TWO_COLOR_FADE:
				light_mode = new Two_color_fade();
				break;
			case FADE:
				light_mode = new Fade();
				break;
			case FLAME_STRIPES:
				light_mode = new Flame_stripes();
				break;
			case OFF:
				light_mode = new Off();
				break;
			default:
				assert(0);
		}
	}

	light_mode -> set_leds(ROBOT_INFO, leds);
	
	last_robot_info = ROBOT_INFO;
}

