#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

//time in milliseconds

class Countdown_timer{
  public:
	long left,last_time;
	
	public:
	Countdown_timer();
	void set(long length);
	void update(long now);
	bool done()const;
  long get_now()const;
};

#endif
