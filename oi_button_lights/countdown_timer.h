#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

//time in milliseconds

class Countdown_timer{
	private:
	unsigned long finish_time;
	
	public:
	Countdown_timer();
	Countdown_timer(const unsigned long);
	void set(const unsigned long);
	bool done()const;
};

#endif
