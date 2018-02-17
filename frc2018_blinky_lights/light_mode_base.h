#ifndef LIGHT_MODE_BASE_H
#define LIGHT_MODE_BASE_H

#include "FastLED.h"
#include "robot_info.h"
#include "light_constants.h"

struct Light_mode_base{	
	virtual void set_leds(const Robot_info&,CRGB*) = 0;
	
	void clear(CRGB*);
	
	virtual void print()const = 0;
	virtual void println()const = 0;
	virtual ~Light_mode_base(){}
};

#endif
