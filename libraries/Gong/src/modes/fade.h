#ifndef FADE_H
#define FADE_H

#include "light_mode_base.h"

struct Fade: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
