#ifndef LIGHTS_H
#define LIGHTS_H

#include "robot_info.h"
#include "countdown_timer.h"
#include "FastLED.h" // http://fastled.io/docs/3.1/group___colorutils.html

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

class Lights{
	public:
	enum Mode{
		RECENTLY_ENABLED = 0, //flashes alliance color at beginning of match
		AUTONOMOUS = 1, //TODO
		CLIMBING = 2, //TODO
		LIFTER_HEIGHT = 3, //lights up to the height of the lifter
		FLAME = 4, //colors a flame slowing from the base
		RANDOMIZED = 5, //sets rgb values randomly 
		FADE = 6, //fades in and out of red and blue
		RAINBOW_CHASE = 7 //colors lights in rainbow and shifts through colors throughout
	};
	
	static const unsigned NUMBER_OF_LEDS = 24;
	static const unsigned LED_STRIP_DATA_PIN = 7;
	static const byte MAX_BRIGHTNESS = 255;
	static constexpr double LEDS_PER_INCH = 0.812799561;

	private:
	CRGB leds[NUMBER_OF_LEDS];
	
	Robot_info last_robot_info;//information about the robot used to inform the lights
	Mode mode;//the display mode
	
	Countdown_timer wait_timer;//used in timing for various modes
	Countdown_timer cycle_timer;//used to swtich between modes at random when the robot isn't doing anything interesting
	
	void color_recently_enabled(const Robot_info::Alliance);
	void color_autonomous();
	void color_lifter_height(const unsigned);
	void color_climbing();
	void color_flame();
	void color_randomized();
	void color_fade();
	void color_rainbow_chase();
	void clear();

	public:
	void print_mode()const;
	void println_mode()const;

	void set_leds(Robot_info const&);
	void setup();

	Lights();
};

#endif
