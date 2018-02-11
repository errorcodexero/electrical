#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

//time in milliseconds

class Countdown_timer{
	private:
	long left;
	unsigned long last_time;
	
	public:
	Countdown_timer();
	void set(const unsigned long);
	void update();
	bool done()const;
	long get_now()const;
};

#endif
