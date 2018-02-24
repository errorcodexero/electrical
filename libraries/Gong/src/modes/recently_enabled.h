#ifndef RECENTLY_ENABLED_H
#define RECENTLY_ENABLED_H

#include "light_mode_base.h"

struct Recently_enabled: public Light_mode_base{
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;
	
	Recently_enabled(unsigned*);
};

#endif
