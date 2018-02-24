#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "light_mode_base.h"
#include "../util/countdown_timer.h"

struct Autonomous: public Light_mode_base{
	private:
	unsigned hue;

	public:
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Autonomous(unsigned*);
};

#endif
