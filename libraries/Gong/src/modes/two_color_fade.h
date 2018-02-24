#ifndef TWO_COLOR_FADE_H
#define TWO_COLOR_FADE_H

#include "light_mode_base.h"
#include "../util/countdown_timer.h"

struct Two_color_fade: public Light_mode_base{
	private:
	Countdown_timer blue_timer;
	Countdown_timer red_timer;
	int blue;
	bool rise;

	public:
	void set_leds(CRGB*,const unsigned,const Robot_info&);
	
	void print()const;
	void println()const;

	Two_color_fade();
};

#endif
