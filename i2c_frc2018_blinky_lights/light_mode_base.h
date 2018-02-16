#ifndef LIGHT_MODE_BASE_H
#define LIGHT_MODE_BASE_H

#include "FastLED.h"
#include "robot_info.h"

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

class Light_mode_base{
	public:
	static const unsigned NUMBER_OF_LEDS = 24;
	static const unsigned LED_STRIP_DATA_PIN = 7;
	static const byte MAX_BRIGHTNESS = 190;//75%
	static constexpr double LEDS_PER_INCH = 0.812799561;

	protected:
	Robot_info last_robot_info;
	CRGB leds[NUMBER_OF_LEDS];
	
	public:
	virtual void set_leds(const Robot_info&) = 0;
	
	void clear();
	void setup();
	
	virtual void print()const = 0;
	virtual void println()const = 0;
	virtual ~Light_mode_base(){}
};

#endif
