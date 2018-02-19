#ifndef RANDOM_STREAM_H
#define RANDOM_STREAM_H

#include "light_mode_base.h"

struct Random_stream: public Light_mode_base{
	void set_leds(const Robot_info&, Lights&);
	
	void print()const;
	void println()const;
};

#endif
