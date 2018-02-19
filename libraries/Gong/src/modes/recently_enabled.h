#ifndef RECENTLY_ENABLED_H
#define RECENTLY_ENABLED_H

#include "light_mode_base.h"

struct Recently_enabled: public Light_mode_base{
	void set_leds(const Robot_info&, Lights&);
	
	void print()const;
	void println()const;
};

#endif
