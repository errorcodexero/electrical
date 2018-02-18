#ifndef RANDOMIZED_H
#define RANDOMIZED_H

#include "light_mode_base.h"
#include "countdown_timer.h"

struct Randomized: public Light_mode_base{
	private:
	Countdown_timer wait_timer;

	public:
	void set_leds(const Robot_info&, Lights&);
	
	void print()const;
	void println()const;
};

#endif
