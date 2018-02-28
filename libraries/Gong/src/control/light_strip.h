#ifndef LIGHT_STRIP_H
#define LIGHT_STRIP_H

#include "FastLED.h"

#include "light_strip_constants.h"
#include "../util/robot_info.h"
#include "../modes/light_mode_base.h"

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Light_strip{
	private:
	CRGB* leds;
	
	unsigned length_;
	uint8_t data_pin_;
	
	Light_mode_base* light_mode;
	
	public:	
	unsigned length()const;
	uint8_t data_pin()const;
	
	void print()const;
	void println()const;
	
	void set_mode(Light_mode_base*);
	void set_leds(const Robot_info&);
	
	Light_strip(const unsigned, const uint8_t);
};

#endif