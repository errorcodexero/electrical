#ifndef LIFTER_HEIGHT_H
#define LIFTER_HEIGHT_H

#include "light_mode_base.h"

struct Lifter_height: public Light_mode_base{
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;
};

#endif
