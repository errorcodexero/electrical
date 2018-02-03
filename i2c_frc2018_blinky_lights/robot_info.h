#ifndef ROBOT_INFO_H
#define ROBOT_INFO_H

enum Alliance{RED,BLUE,INVALID};

struct Robot_info{
	static const unsigned INFO_STATES = 41;//keep this updated with the lights.cpp 
	unsigned lifter_height;
	bool climbing;
	bool autonomous;
  bool enabled;
	Alliance alliance;

	void update(int,int,int,int,int);
	
	void print()const;
	
	Robot_info();
	Robot_info(unsigned,bool,bool,bool,Alliance);
};

#endif