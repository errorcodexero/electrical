#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "light_mode_base.h"
#include "countdown_timer.h"

struct Autonomous: public Light_mode_base{
	private:
	static const int HALF = Light_constants::NUMBER_OF_LEDS * 0.5;
	Countdown_timer color_timer;
	CRGB color;
	int dot;

	public:
	void set_leds(const Robot_info&, CRGB*);
	
	void print()const;
	void println()const;

	Autonomous();
};

#endif
