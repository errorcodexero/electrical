#include "robot_lights.h"

#include "assert.h"

Robot_lights::Robot_lights():left_lifter_strip(Light_strip(24,7)),right_lifter_strip(Light_strip(24,8)),last_robot_info(),mode_index(random(LIFTER_HEIGHT, OFF)),mode(OFF){}

void Robot_lights::println_mode()const{
	left_lifter_strip.println();
	//right_lifter_strip.println();
}

void Robot_lights::print_mode()const{
	left_lifter_strip.print();
	//right_lifter_strip.print();
}

void Robot_lights::set_leds(const Robot_info& ROBOT_INFO){
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
			return (Robot_lights::Mode)mode_index;
		}
		return last_mode;
	}();

	println_mode();

	if(last_mode != mode){
		{//clear the leds
			left_lifter_strip.set_mode(new Off());
			left_lifter_strip.set_leds(ROBOT_INFO);
		}
		cycle_timer.set(CYCLE_TIME);
		
		switch(mode){
			case RECENTLY_ENABLED:
				if(last_mode != RECENTLY_ENABLED){
					cycle_timer.set(2000);
				}
				left_lifter_strip.set_mode(new Recently_enabled());
				break;
			case AUTONOMOUS:
				left_lifter_strip.set_mode(new Autonomous());
				break;
			case HAS_CUBE:
				left_lifter_strip.set_mode(new Has_cube());
				break;
			case LIFTER_HEIGHT:
				left_lifter_strip.set_mode(new Lifter_height());
				break;
			case CLIMBING:
				left_lifter_strip.set_mode(new Climbing());
				break;
			case FLAME:
				left_lifter_strip.set_mode(new Flame());
				break;
			case RANDOMIZED:
				left_lifter_strip.set_mode(new Randomized());
				break;
			case ALLIANCE_FADE:
				left_lifter_strip.set_mode(new Alliance_fade());
				break;
			case RAINBOW_CHASE:
				left_lifter_strip.set_mode(new Rainbow_chase());
				break;
			case RAINBOW_STRIPES:
				left_lifter_strip.set_mode(new Rainbow_stripes());
				break;
			case RANDOM_STREAM:
				left_lifter_strip.set_mode(new Random_stream());
				break;
			case TWO_COLOR_FADE:
				left_lifter_strip.set_mode(new Two_color_fade());
				break;
			case FADE:
				left_lifter_strip.set_mode(new Fade());
				break;
			case FLAME_STRIPES:
				left_lifter_strip.set_mode(new Flame_stripes());
				break;
			case OFF:
				left_lifter_strip.set_mode(new Off());
				break;
			default:
				assert(0);
		}
	}

	left_lifter_strip.set_leds(ROBOT_INFO);
	
	last_robot_info = ROBOT_INFO;	
}

