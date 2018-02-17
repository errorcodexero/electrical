#ifndef LIGHT_CONSTANTS_H
#define LIGHT_CONSTANTS_H

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Light_constants{
	static const unsigned NUMBER_OF_LEDS = 24;
	static const unsigned LED_STRIP_DATA_PIN = 7;
	static const byte MAX_BRIGHTNESS = 190;//75%
	static constexpr double LEDS_PER_INCH = 0.812799561;
};

#endif