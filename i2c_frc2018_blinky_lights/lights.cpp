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


Lights::Lights():mode_index(random(LIFTER_HEIGHT, OFF)),mode(RECENTLY_ENABLED),cycle_timer(){}

void Lights::setup(){
	light_mode -> setup();
}

void Lights::println_mode()const{
	light_mode -> println();
}

void Lights::print_mode()const{
	light_mode -> print();
}

void Lights::set_leds(const Robot_info& ROBOT_INFO){
	const long CYCLE_TIME = 10000;
	cycle_timer.update();

	Mode last_mode = mode;
	mode = [&]{//pick mode to display
		return FADE;
		/*
		if(
			(last_mode == RECENTLY_ENABLED && !wait_timer.done()) ||
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
	 */
	}();

	println_mode();

	if(last_mode != mode){
		cycle_timer.set(CYCLE_TIME);

		switch(mode){
			case RECENTLY_ENABLED:
				if(last_mode != RECENTLY_ENABLED){
					cycle_timer.set(1000);
				}
				break;
			case AUTONOMOUS:
				break;
			case HAS_CUBE:
				break;
			case LIFTER_HEIGHT:
				break;
			case CLIMBING:
				break;
			case FLAME:
				break;
			case RANDOMIZED:
				break;
			case ALLIANCE_FADE:
				break;
			case RAINBOW_CHASE:
				break;
			case RAINBOW_STRIPES:
				break;
			case RANDOM_STREAM:
				break;
			case TWO_COLOR_FADE:
				break;
			case FADE:
				light_mode = new Fade();
				break;
			case FLAME_STRIPES:
				break;
			case OFF:
				break;
			default:
				assert(0);
		}
	}
	
	light_mode -> set_leds(ROBOT_INFO);
}

