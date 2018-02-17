#ifndef ALLIANCE_FADE_H
#define ALLIANCE_FADE_H

#include "light_mode_base.h"

struct Alliance_fade: public Light_mode_base{
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;
};

#endif
