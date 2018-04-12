#include <FastLED.h>
#include "countdown_timer.h"

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

static const unsigned DEBOUNCE_DURATION = 500;

struct Elevated_indicator {
	static const unsigned LED_COUNT = 12;
	static const uint8_t  BRIGHTNESS = 255 * .1;
	static const unsigned PIN_OUT = 13;
};

Countdown_timer has_cube_debounce_timer;
static const unsigned HAS_CUBE_BLINK_PAUSE = 50;
static const unsigned HAS_CUBE_BLINK_DURATION = 1000;
Countdown_timer indicate_has_cube_blink_timer;
Countdown_timer indicate_has_cube_timer;
bool indicate_has_cube_state = true;
CRGB has_cube_color = CRGB(0, 255, 0);
bool has_cube_last = false;

CRGB collecting_color = CRGB(255, 153, 0);

CRGB elevated_indicator_leds[Elevated_indicator::LED_COUNT];

class Input {
	protected:
	int _pin;
	
	public:
	virtual void init();
	virtual bool read();
	
	Input(int pin) {
		_pin = pin;
	}
};
	
class DigitalInput : public Input {
	public:
	void init() {
		pinMode(_pin, INPUT);
	}
	
	bool read() {
		return digitalRead(_pin) == HIGH;
	}
	
	DigitalInput(int pin):Input(pin) {}
};

class AnalogInput : public Input {
	public:
	void init() {}
	
	bool read() {
		return analogRead(_pin) > 511;
	}
	
	AnalogInput(int pin):Input(pin) {}
};

class Output {
	int _pin;
	bool _state;
	
	public:
	void init() {
		pinMode(_pin, OUTPUT);
		_state = false;
	}
	
	void set(bool state) {
		_state = state;
	}
	
	bool get() {
		return _state;
	}
	
	void write() {
		digitalWrite(_pin, _state ? HIGH : LOW);
	}
	
	void write(bool state) {
		digitalWrite(_pin, state ? HIGH : LOW);
	}
	
	Output(int pin) {
		_pin = pin;
	}
};

#define INPUTS 2
Input* in_has_cube =          new DigitalInput(12);
Input* in_collecting =        new AnalogInput(0);

#define OUTPUTS 10
Output* out_floor =           new Output(2);
Output* out_exchange =        new Output(3);
Output* out_switch =          new Output(4);
Output* out_scale =           new Output(5);
Output* out_climb =           new Output(6);
Output* out_collect_closed =  new Output(7);
Output* out_collect_open =    new Output(8);
Output* out_eject =           new Output(9);
Output* out_drop =            new Output(10);
Output* out_wing_release =    new Output(11);

Input* inputs[INPUTS] = {in_has_cube, in_collecting};
Output* outputs[OUTPUTS] = {out_floor, out_exchange, out_switch, out_scale, out_climb, out_wing_release, out_drop, out_eject, out_collect_open, out_collect_closed};

void setup() {
	FastLED.addLeds<LED_TYPE, Elevated_indicator::PIN_OUT, COLOR_ORDER>(elevated_indicator_leds, Elevated_indicator::LED_COUNT);
	FastLED.setBrightness(Elevated_indicator::BRIGHTNESS);

	Serial.begin(9600);

	for(int i = 0; i < INPUTS; i++) {
		inputs[i]->init();
	}

	for(int i = 0; i < OUTPUTS; i++) {
		outputs[i]->init();
		outputs[i]->set(false);
	}
	outputs[0]->set(true);
}

void writeall(bool val) {
	for(int i = 0; i < OUTPUTS; i++) {
		outputs[i]->write(val);
	}
}

void loop() {
	bool has_cube = in_has_cube->read();
	if(has_cube != has_cube_last) {
		if(!has_cube) {
			has_cube_debounce_timer.set(DEBOUNCE_DURATION);
		}
		if(has_cube && has_cube_debounce_timer.done()) {
			indicate_has_cube_timer.set(HAS_CUBE_BLINK_DURATION);
		}
	}
	has_cube_last = has_cube;

	if(!indicate_has_cube_timer.done()){
		if(indicate_has_cube_blink_timer.done()){
			fill_solid(elevated_indicator_leds, Elevated_indicator::LED_COUNT, indicate_has_cube_state ? has_cube_color : CRGB(0, 0, 0));
			FastLED.show();
			writeall(indicate_has_cube_state);
			indicate_has_cube_blink_timer.set(HAS_CUBE_BLINK_PAUSE);
			indicate_has_cube_state = !indicate_has_cube_state;
		}
	} else if(in_collecting->read()) {
		fill_solid(elevated_indicator_leds, Elevated_indicator::LED_COUNT, collecting_color);
		FastLED.show();
		writeall(false);
	} else {
		fill_solid(elevated_indicator_leds, Elevated_indicator::LED_COUNT, CRGB(0,0,0));
		FastLED.show();
		writeall(false);
		indicate_has_cube_state = true;
	}

	/*
	{
		bool overflowed = outputs[OUTPUTS - 1]->get();
		for(int i = OUTPUTS - 2; i >= 0; i--) {
			Serial.println(i);
			if(outputs[i]->get()) {
				outputs[i]->set(false);
				outputs[i + 1]->set(true);
			}
		}
		if(overflowed){
			outputs[0]->set(true);
			outputs[OUTPUTS - 1]->set(false);
		}
		
		for(int i = 0; i < OUTPUTS; i++) {
			outputs[i]->write();
		}
		
		delay(110);
	}
	*/
}
