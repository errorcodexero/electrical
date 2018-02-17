#ifndef FLAME_STRIPES_H
#define FLAME_STRIPES_H

#include "light_mode_base.h"
#include "countdown_timer.h"

struct Flame_stripes: public Light_mode_base{
	private:
	Countdown_timer wait_timer;
	
	public:
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;
};

#endif