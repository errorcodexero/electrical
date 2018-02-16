#ifndef LIGHTS_H
#define LIGHTS_H

#include "fade.h"
#include "countdown_timer.h"

class Lights{
	public:
	enum Mode{
		RECENTLY_ENABLED = 0, //flashes alliance color at beginning of match
		AUTONOMOUS = 1, //TODO
		CLIMBING = 2, //TODO
		HAS_CUBE = 3, //lights up green when we have a cube
		LIFTER_HEIGHT = 4, //lights up to the height of the lifter
		FLAME = 5, //colors a flame slowing from the base
		RANDOMIZED = 6, //sets rgb values randomly 
		ALLIANCE_FADE = 7, //fades in and out of red and blue
		RAINBOW_CHASE = 8, //colors lights in rainbow and shifts through colors throughout
		RAINBOW_STRIPES = 9, //send rainbows out with gabs in between
		RANDOM_STREAM = 10, //sends a single random color out
		TWO_COLOR_FADE = 11, //TODO
		FADE = 12, //cycles through the rainbow
		FLAME_STRIPES = 13, //sends out stripes of red, orange, then yellow 
		OFF = 14 //turn all lights off (note, this must always be the last mode in the list / the mode set to the highest incremental value)
	};
	private:
	unsigned mode_index;
	Mode mode;
	Countdown_timer cycle_timer;
	
	Light_mode_base* light_mode;

	public:
	void print_mode()const;
	void println_mode()const;

	void set_leds(const Robot_info&);
	void setup();

	Lights();
};

#endif
