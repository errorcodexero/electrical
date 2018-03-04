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

#define INPUTS 8
Input* in_collect_open =		 new DigitalInput(12);
Input* in_collect_closed =		 new DigitalInput(13);
Input* in_has_cube =			 new AnalogInput(0);
Input* in_wing_ready =           new AnalogInput(1);
Input* in_enabled =				 new AnalogInput(2);
Input* in_lifter_a =			 new AnalogInput(3);
Input* in_lifter_b =			 new AnalogInput(4);
Input* in_lifter_c =			 new AnalogInput(5);

#define OUTPUTS 10
Output* out_floor =				 new Output(2);
Output* out_exchange =			 new Output(3);
Output* out_switch =			 new Output(4);
Output* out_scale =				 new Output(5);
Output* out_climb =				 new Output(6);
Output* out_collect_closed =	 new Output(7);
Output* out_collect_open =		 new Output(8);
Output* out_eject =				 new Output(9);
Output* out_drop =				 new Output(10);
Output* out_wing_release =		 new Output(11);

Input* inputs[INPUTS] = {in_collect_open, in_collect_closed, in_has_cube, in_wing_ready, in_enabled, in_lifter_a, in_lifter_b, in_lifter_c};
Output* outputs[OUTPUTS] = {out_floor, out_exchange, out_switch, out_scale, out_climb, out_wing_release, out_drop, out_eject, out_collect_open, out_collect_closed};

void setup() {
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

void loop() {
	if(in_enabled->read()) {
		int lifter_pos = 0;
		if(in_lifter_a->read()) lifter_pos += 4;
		if(in_lifter_b->read()) lifter_pos += 2;
		if(in_lifter_c->read()) lifter_pos += 1;
		out_floor->write(lifter_pos == 1);
		out_exchange->write(lifter_pos == 2);
		out_switch->write(lifter_pos == 3);
		out_scale->write(lifter_pos == 4);
		out_climb->write(lifter_pos == 5);
		
		out_collect_closed->write(in_collect_closed->read());
		out_collect_open->write(in_collect_open->read());
		
		bool has_cube = in_has_cube->read();
		out_eject->write(has_cube);
		out_drop->write(has_cube);
		
		out_wing_release->write(in_wing_ready->read());
		
		delay(50);
	} else {
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
}
