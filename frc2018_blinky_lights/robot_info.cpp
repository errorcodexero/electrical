#include "robot_info.h"
#include <assert.h>

#ifndef ROBOT_INFO_TEST
#include "Arduino.h"
#else
#include <iostream>
#endif

using namespace std;

Robot_info::Robot_info(unsigned h,bool c,bool m,Alliance a):lifter_height(h),climbing(c),autonomous(m),alliance(a){}
Robot_info::Robot_info():Robot_info(0,false,false,INVALID){}

void Robot_info::update(double duty_cylce){
	const double PWM_RANGE = 2.0;
	const double INCREMENT = PWM_RANGE / (double)Robot_info::INFO_STATES;
	const double STARTING_VALUE = -1.0;
	
	int value = ((duty_cylce - STARTING_VALUE) / INCREMENT);
	
	switch(value){
		case 0:
			climbing = false;
			break;
		case 1:
			climbing = true;
			break;
		case 2:
			autonomous = false;
			break;
		case 3:
			autonomous = true;
			break;
		case 4: 
			alliance = RED;
			break;
		case 5:
			alliance = BLUE;
			break;
		case 6:
			alliance = INVALID;
			break;
		default:
			lifter_height = (value - 7) * 3;
	}
}

void Robot_info::print()const{
	#ifndef ROBOT_INFO_TEST
	
	Serial.print("(lifter_height:");
	Serial.print(lifter_height);
	Serial.print(" climbing:");
	Serial.print(climbing);
	Serial.print(" autonomous:");
	Serial.print(autonomous);
	Serial.print("alliance:");
	switch(alliance){
		case INVALID:
			Serial.println("INVALID");
			break;
		case BLUE:
			Serial.println("BLUE");
			break;
		case RED:
			Serial.println("RED");
			break;
		default:
			assert(0);
	}
	Serial.print(")");
	
	#else
		
	string s = [&]{
		switch(alliance){
			case INVALID:
				return "INVALID";
			case BLUE:
				return "BLUE";
			case RED:
				return "RED";
			default:
				assert(0);
		}
	}();
	cout<<"lifter_height:"<<lifter_height<<" climbing:"<<climbing<<" autonomous:"<<autonomous<<" alliance:"<<s<<"\n";
	
	#endif
}

#ifdef ROBOT_INFO_TEST

#include <iostream> 
#include <vector>

int main(){
	Robot_info robot_info;
	vector<double> pwm_values = {-1,-1,-1,-0.943925,-0.943925,-0.943925,-0.88785,-0.88785,-0.719626,-0.719626,-0.719626};
	for(double a: pwm_values){
		robot_info.update(a);
	}
	robot_info.print();
}

#endif
