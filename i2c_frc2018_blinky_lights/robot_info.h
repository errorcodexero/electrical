#ifndef ROBOT_INFO_H
#define ROBOT_INFO_H

enum Alliance{RED,BLUE,INVALID};

struct Robot_info{
	static const unsigned INFO_STATES = 41;//keep this updated with the lights.cpp 
	unsigned lifter_height;
	bool climbing;
	bool autonomous;
	Alliance alliance;

	void update(double);//takes a pwm value and updates robot info
	
	void print()const;
	
	Robot_info();
	Robot_info(unsigned,bool,bool,Alliance);
};

#endif
