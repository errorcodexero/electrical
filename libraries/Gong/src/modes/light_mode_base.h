#ifndef LIGHT_MODE_BASE_H
#define LIGHT_MODE_BASE_H

#include "FastLED.h"

#include "../util/robot_info.h"
#include "../control/light_strip_constants.h"
#include "../control/lights.h"

struct Light_mode_base{	
	virtual void set_leds(CRGB*,const unsigned,const Robot_info&) = 0;
	
	void clear(CRGB*,const unsigned);
	
	virtual void print()const = 0;
	virtual void println()const = 0;
	virtual ~Light_mode_base(){}
};

#endif
