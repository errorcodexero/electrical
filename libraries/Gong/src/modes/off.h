#ifndef OFF_H
#define OFF_H

#include "light_mode_base.h"

struct Off: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
