#ifndef LIGHT_MODE_BASE_H
#define LIGHT_MODE_BASE_H

#include "../../FastLED/FastLED.h"
#include "../util/robot_info.h"
#include "../control/lights.h"

struct Light_mode_base{	
	virtual void set_leds(const Robot_info&,Lights&) = 0;
	
	void clear(Lights&);
	void clear(CRGB*,const unsigned);
	
	virtual void print()const = 0;
	virtual void println()const = 0;
	virtual ~Light_mode_base(){}
};

#endif
