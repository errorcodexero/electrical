#ifndef FLAME_STRIPES_H
#define FLAME_STRIPES_H

#include "light_mode_base.h"
#include "../util/countdown_timer.h"

struct Flame_stripes: public Light_mode_base{
	private:
	unsigned hue;
	Countdown_timer wait_timer;
	
	public:
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Flame_stripes(unsigned*);
};

#endif
