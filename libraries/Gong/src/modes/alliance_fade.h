#ifndef ALLIANCE_FADE_H
#define ALLIANCE_FADE_H

#include "light_mode_base.h"

struct Alliance_fade: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Alliance_fade(unsigned*);
};

#endif
