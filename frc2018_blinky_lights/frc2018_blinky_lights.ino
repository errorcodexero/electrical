#include "pwm_reader.h"
#include "robot_info.h"

Robot_info robot_info;
unsigned input_pin = 9;

void setup() {
	Serial.begin(9600);
	pinMode(input_pin, INPUT);
}

void loop() {
	double duty_cycle = calculate_duty_cycle(input_pin);
	Serial.println(duty_cycle);
	robot_info.update(duty_cycle);
}
