#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "lights.h"
#include "../modes/light_mode_base.h"
#include "../util/robot_info.h"
#include "../util/countdown_timer.h"
/*
class Controller{
	public:
	enum Mode{
		RECENTLY_ENABLED = 0, //flashes alliance color at beginning of match
		AUTONOMOUS = 1, //colors out from the center in changing colors to the percent of the power of each drive side
		CLIMBING = 2, //sends up colored stripes
		HAS_CUBE = 3, //lights up green when we have a cube
		LIFTER_HEIGHT = 4, //lights up to the height of the lifter
		FLAME = 5, //colors a flame slowing from the base
		RANDOMIZED = 6, //sets rgb values randomly 
		ALLIANCE_FADE = 7, //fades in and out of red and blue
		RAINBOW_CHASE = 8, //colors lights in rainbow and shifts through colors throughout
		RAINBOW_STRIPES = 9, //send rainbows out with gabs in between
		RANDOM_STREAM = 10, //sends a single random color out at a time
		TWO_COLOR_FADE = 11, //fades in between red and blue
		FADE = 12, //cycles through the rainbow
		FLAME_STRIPES = 13, //sends out stripes of red, orange, then yellow 
		OFF = 14 //turn all lights off (note, this must always be the last mode in the list / the mode set to the highest incremental value)
	};

	private:
	Robot_info last_robot_info;
	Lights* lights;

	unsigned mode_index;
	Mode mode;
	Light_mode_base* light_mode;

	Countdown_timer cycle_timer;

	public:
	void print_mode()const;
	void println_mode()const;

	void set_leds(const Robot_info&);

	Controller(Lights*);
};
*/
#endif
