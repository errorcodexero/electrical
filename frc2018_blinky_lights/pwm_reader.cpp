#include "pwm_reader.h"
#include "Arduino.h"

double calculate_duty_cycle(unsigned input_pin){//reads the pwm value of an input
	unsigned long high_time = pulseIn(input_pin, HIGH);
	unsigned long low_time = pulseIn(input_pin, LOW);
	unsigned long cycle_time = high_time  + low_time;
	double duty_cycle = (double)high_time / (double)cycle_time;
	return duty_cycle;
}
