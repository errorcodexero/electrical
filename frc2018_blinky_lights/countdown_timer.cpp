#include "countdown_timer.h"

#include "Arduino.h"

Countdown_timer::Countdown_timer(const unsigned long END_TIME):finish_time(END_TIME){}
Countdown_timer::Countdown_timer():Countdown_timer(0){}

void Countdown_timer::set(const unsigned long length){
	finish_time = millis() + length;
}

bool Countdown_timer::done()const{
	return millis() >= finish_time;
}
