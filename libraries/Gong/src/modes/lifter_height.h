#ifndef LIFTER_HEIGHT_H
#define LIFTER_HEIGHT_H

#include "light_mode_base.h"

struct Lifter_height: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Lifter_height(unsigned*);
};

#endif
