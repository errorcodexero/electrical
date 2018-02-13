#include "countdown_timer.h"

#include "Arduino.h"

Countdown_timer::Countdown_timer():left(0),last_time(0){}

void Countdown_timer::set(const unsigned long length){
	left = length;
	last_time = millis();
}

void Countdown_timer::update(){
	long now = millis();
	if(left > 0){
		left -= (now - last_time);
	}
	last_time = now;
}

bool Countdown_timer::done()const{
	return left <= 0;
}
