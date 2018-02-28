#ifndef RAINBOW_CHASE_H
#define RAINBOW_CHASE_H

#include "light_mode_base.h"

struct Rainbow_chase: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
