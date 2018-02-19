#ifndef LIGHTS_H
#define LIGHTS_H

#include "../../FastLED/FastLED.h"

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Lights{
	static const byte MAX_BRIGHTNESS = 190;//75%
	static constexpr double LEDS_PER_INCH = 0.812799561;

	enum Led_index{
		LEFT_STRIP = 0,
		RIGHT_STRIP = 1, 
		LEDS_ = 2
	};

	private:
	struct Led_lengths{
		static const unsigned LEFT_STRIP = 24;
		static const unsigned RIGHT_STRIP = 24;//Note: if it's zero, errors happen. This is to prevent that for now.
		
		const unsigned operator[](const Led_index)const;
		const unsigned operator[](const unsigned)const;
	};

	public:
	static const Led_lengths LED_LENGTHS;

	static constexpr unsigned LED_DATA_PINS[Led_index::LEDS_] = {
		7,  //LEFT_STRIP
		8   //RIGHT_STRIP
	};

	private:
	CRGB *left_strip;
	CRGB *right_strip;
	
	public:
	CRGB* get(const Led_index);
	CRGB* get(const unsigned);
	
	Lights();
};

#endif
