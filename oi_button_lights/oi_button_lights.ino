#include <FastLED.h>
#include "countdown_timer.h"

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

struct Cube_collected_signal{
	static const unsigned LED_COUNT = 12;
	static const uint8_t  BRIGHTNESS = 255 * .1;
	static const unsigned PIN_OUT = 13;
	static const unsigned BLINK_PAUSE = 50;
	static const unsigned BLINK_DURATION = 1000;
};

Countdown_timer cube_collected_signal_blink_timer;
Countdown_timer cube_collected_signal_timer;
CRGB cube_collected_signal_blink_color = CRGB(0,255,0);
bool has_cube_last = false;

CRGB cube_collected_signal_leds[Cube_collected_signal::LED_COUNT];

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

#define INPUTS 1
Input* in_has_cube =          new DigitalInput(12);

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

Input* inputs[INPUTS] = {in_has_cube};
Output* outputs[OUTPUTS] = {out_floor, out_exchange, out_switch, out_scale, out_climb, out_wing_release, out_drop, out_eject, out_collect_open, out_collect_closed};

void setup() {
	FastLED.addLeds<LED_TYPE,Cube_collected_signal::PIN_OUT,COLOR_ORDER>(cube_collected_signal_leds, Cube_collected_signal::LED_COUNT);
	FastLED.setBrightness(Cube_collected_signal::BRIGHTNESS);
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
	//until msp430 sends proper signals, turn all lights on all the time
	/*for(int i = 0; i < OUTPUTS; i++) {
		outputs[i]->write(true);
	}*/

	bool hc = in_has_cube->read();
	Serial.println(hc);
	if(hc && hc != has_cube_last){
		cube_collected_signal_timer.set(Cube_collected_signal::BLINK_DURATION);
		has_cube_last = hc;
	}
	if(!cube_collected_signal_timer.done()){
		if(cube_collected_signal_blink_timer.done()){
			fill_solid(cube_collected_signal_leds, Cube_collected_signal::LED_COUNT, cube_collected_signal_blink_color);
			if(cube_collected_signal_blink_color == CRGB(0,255,0)){
				cube_collected_signal_blink_color = CRGB(0,0,0);
				writeall(true);
			} else {
				cube_collected_signal_blink_color = CRGB(0,255,0);
				writeall(false);
			}
			FastLED.show();
			cube_collected_signal_blink_timer.set(Cube_collected_signal::BLINK_PAUSE);
		}
	} else {
		fill_solid(cube_collected_signal_leds, Cube_collected_signal::LED_COUNT, CRGB(0,0,0));
		FastLED.show();
		writeall(false);
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
