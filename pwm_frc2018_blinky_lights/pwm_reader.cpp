#include "pwm_reader.h"
#include "Arduino.h"

double calculate_duty_cycle(const unsigned INPUT_PIN){//reads the pwm value of an input
	unsigned long high_time = pulseIn(INPUT_PIN, HIGH);
	unsigned long low_time = pulseIn(INPUT_PIN, LOW);
	unsigned long cycle_time = high_time  + low_time;
	double duty_cycle = (double)high_time / (double)cycle_time;
	return duty_cycle;
}

double mapf(double x, double in_min, double in_max, double out_min, double out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double convert_duty_cycle(const double DUTY_CYCLE){//DUTY_CYCLE in microseconds
  //Serial.println(DUTY_CYCLE);
  
  if(DUTY_CYCLE > (double)PWM_constants::DEADBAND_RANGE_LOW_END && DUTY_CYCLE < (double)PWM_constants::DEADBAND_RANGE_HIGH_END){
     return 0.0;  
  }

  if(DUTY_CYCLE < (double)PWM_constants::DEADBAND_RANGE_LOW_END){
    return mapf(DUTY_CYCLE, (double)PWM_constants::FULL_REVERSE, (double)PWM_constants::DEADBAND_RANGE_LOW_END, -1.0, 0.0);
  }

  if(DUTY_CYCLE > (double)PWM_constants::DEADBAND_RANGE_HIGH_END){
    return mapf(DUTY_CYCLE, (double)PWM_constants::DEADBAND_RANGE_HIGH_END, (double)PWM_constants::FULL_FORWARD, 0.0, 1.0);
  }
    
  return 0;//error
}

