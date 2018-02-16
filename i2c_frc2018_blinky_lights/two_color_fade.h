#ifndef TWO_COLOR_FADE_H
#define TWO_COLOR_FADE_H

#include "light_mode_base.h"

struct Two_color_fade: public Light_mode_base{
	void set_leds(const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
