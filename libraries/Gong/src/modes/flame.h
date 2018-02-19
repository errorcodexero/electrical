#ifndef FLAME_H
#define FLAME_H

#include "light_mode_base.h"
#include "../util/countdown_timer.h"

struct Flame: public Light_mode_base{
	private:
	Countdown_timer wait_timer;
	int heat[Lights::Led_index::LEFT_STRIP];
	
	public:
	void set_leds(const Robot_info&, Lights&);
	
	void print()const;
	void println()const;
};

#endif
