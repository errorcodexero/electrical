#ifndef CLIMBING_H
#define CLIMBING_H

#include "light_mode_base.h"

struct Climbing: public Light_mode_base{
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;
};

#endif
