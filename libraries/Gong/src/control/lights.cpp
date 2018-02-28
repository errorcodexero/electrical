#include "lights.h"

#include "assert.h"

/*
const unsigned Lights::Led_lengths::operator[](const Lights::Led_index LED_INDEX)const{
	switch(LED_INDEX){
		case Lights::Led_index::LEFT_STRIP:
			return LEFT_STRIP;
		case Lights::Led_index::RIGHT_STRIP:
			return RIGHT_STRIP;
		default:
			assert(0);
	}
}

const unsigned Lights::Led_lengths::operator[](const unsigned LED_INDEX)const{
	switch(LED_INDEX){
		case Lights::Led_index::LEFT_STRIP:
			return LEFT_STRIP;
		case Lights::Led_index::RIGHT_STRIP:
			return RIGHT_STRIP;
		default:
			assert(0);
	}
}
*/
/*
Lights::Lights(){
	for(unsigned i = 0; i < Lights::Led_index::LEDS_; i++){
		if(Lights::LED_LENGTHS[i] <= 0){
			Serial.println("Error: LED array length is of size zero or less");
			assert(0);
		}
	}
	
	left_strip = new CRGB[Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP]];
	FastLED.addLeds<
		LED_CONTROLLER,
		Lights::LED_DATA_PINS[Lights::Led_index::LEFT_STRIP],
		COLOR_ORDER
	>(left_strip, Lights::LED_LENGTHS[Lights::Led_index::LEFT_STRIP]);

	right_strip = new CRGB[Lights::LED_LENGTHS[Lights::Led_index::RIGHT_STRIP]];

	FastLED.addLeds<
		LED_CONTROLLER,
		Lights::LED_DATA_PINS[Lights::Led_index::RIGHT_STRIP],
		COLOR_ORDER
	>(right_strip, Lights::LED_LENGTHS[Lights::Led_index::RIGHT_STRIP]);
	
	FastLED.setBrightness(Lights::MAX_BRIGHTNESS);
}*/
/*
CRGB* Lights::get(const Lights::Led_index LED_INDEX){
	switch(LED_INDEX){
		case Lights::Led_index::LEFT_STRIP:
			return left_strip;
		case Lights::Led_index::RIGHT_STRIP:
			return right_strip;
		default:
			assert(0);
	}
}

CRGB* Lights::get(const unsigned LED_INDEX){
	assert(LED_INDEX < Lights::Led_index::LEDS_);
	return get((Lights::Led_index)LED_INDEX);
}
*/
