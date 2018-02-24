#ifndef CLIMBING_H
#define CLIMBING_H

#include "light_mode_base.h"

struct Climbing: public Light_mode_base{
	private:
	unsigned hue;
	
	public:
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Climbing(unsigned*);
};

#endif
