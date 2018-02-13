#ifndef ROBOT_INFO_H
#define ROBOT_INFO_H

struct Robot_info{
	enum Alliance{RED,BLUE,INVALID};

	unsigned lifter_height;
	bool climbing;
	bool autonomous;
	bool enabled;
	Alliance alliance;
  double drive_left;
  double drive_right;
  bool has_cube;

	void update(int,int,int,int,int,int,int,int);
	
	void print()const;
	void println()const;
	
	Robot_info();
	Robot_info(unsigned,bool,bool,bool,Alliance,double,double,bool);
};

#endif
