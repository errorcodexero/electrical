#ifndef OFF_H
#define OFF_H

#include "light_mode_base.h"

struct Off: public Light_mode_base{
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;
};

#endif
