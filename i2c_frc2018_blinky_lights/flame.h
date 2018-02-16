#ifndef FLAME_H
#define FLAME_H

#include "light_mode_base.h"
#include "countdown_timer.h"

struct Flame: public Light_mode_base{
	private:
	Countdown_timer wait_timer;
	int heat[Light_mode_base::NUMBER_OF_LEDS];
	
	public:
	void set_leds(const Robot_info&);
	
	void print()const;
	void println()const;
};

#endif
