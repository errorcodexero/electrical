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
  //if(duty_cycle >= (double)PWM_constants::FULL_REVERSE && duty_cycle <= (double)PWM_constants::FULL_FORWARD){
    double pwm_signal = duty_cycle;//convert_duty_cycle(duty_cycle);
	  /*
	  Serial.print(duty_cycle,6);
	  Serial.print("     ");
	  Serial.print(pwm_signal,6);
    Serial.print("\n");
	  */
	  robot_info.update(pwm_signal);
	  robot_info.print();
  //
}
