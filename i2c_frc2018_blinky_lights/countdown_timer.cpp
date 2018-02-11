#include "countdown_timer.h"

Countdown_timer::Countdown_timer():left(0),last_time(0){}

void Countdown_timer::set(long length){
	left=length;
	last_time=0;
}

long Countdown_timer::get_now()const{
  return last_time;
}

void Countdown_timer::update(long now){
	if(left>0){
		left-=(now-last_time);
	}
	last_time=now;
}

bool Countdown_timer::done()const{
	return left<=0;
}
