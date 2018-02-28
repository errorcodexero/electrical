#ifndef HAS_CUBE_H
#define HAS_CUBE_H

#include "light_mode_base.h"

struct Has_cube: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
