#ifndef FLAME_H
#define FLAME_H

#include "light_mode_base.h"
#include "../util/countdown_timer.h"

struct Flame: public Light_mode_base{
	private:
	Countdown_timer wait_timer;
	int *heat;
	
	public:
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Flame(unsigned*);
};

#endif
