#ifndef ROBOT_LIGHTS_H
#define ROBOT_LIGHTS_H

#include <Gong.h>

struct Robot_lights: public Lights{
	enum Led_index{
		LEFT_STRIP = 0,
		RIGHT_STRIP = 1, 
		LEDS_ = 2
	};
	
	private:
	static const unsigned MAX_BRIGHTNESS = 190;// 75%
	static constexpr double LEDS_PER_INCH = 0.812799561;
	
	static const unsigned LEFT_STRIP_LENGTH = 24;
	static const unsigned RIGHT_STRIP_LENGTH = 24;
	
	static const unsigned LEFT_STRIP_DATA_PIN = 7;
	static const unsigned LEFT_STRIP_DATA_PIN = 8;
	
	CRGB left_strip[LEFT_STRIP_LENGTH];
	CRGB right_strip[RIGHT];
	
	public:

	double leds_per_inch()const ;
	unsigned max_brightness()const;
	
	CRGB* get(const unsigned);
	unsigned data_pin(const unsigned);
	unsigned length(const unsigned);
	
	Robot_lights();
};

#endif
