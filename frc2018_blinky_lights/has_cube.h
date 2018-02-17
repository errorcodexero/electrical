#ifndef HAS_CUBE_H
#define HAS_CUBE_H

#include "light_mode_base.h"

struct Has_cube: public Light_mode_base{
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;
};

#endif
