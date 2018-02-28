#ifndef RAINBOW_STRIPES_H
#define RAINBOW_STRIPES_H

#include "light_mode_base.h"
#include "../util/countdown_timer.h"

struct Rainbow_stripes: public Light_mode_base{
	private:
	Countdown_timer wait_timer;
	
	public:
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
