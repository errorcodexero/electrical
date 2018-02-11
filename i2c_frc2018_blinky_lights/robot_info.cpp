#include "robot_info.h"
#include <assert.h>
#include "Arduino.h"

Robot_info::Robot_info(unsigned h,bool c,bool m,bool e,Alliance a):lifter_height(h),climbing(c),autonomous(m),enabled(e),alliance(a){}
Robot_info::Robot_info():Robot_info(0,false,false,false,INVALID){}

void Robot_info::update(int c,int a, int e,int al, int h){
	climbing = (bool)c;
	autonomous = (bool)a;
	enabled = (bool)e;
 	lifter_height = h;
	 
 	switch(al){
		case 0: 
			alliance = RED;
			break;
		case 1:
			alliance = BLUE;
			break;
		case 2:
			alliance = INVALID;
			break;
		default:
			;//null
	}
}

void Robot_info::println()const{
	print();
	Serial.print("\n");
}

void Robot_info::print()const{
	Serial.print("(lifter_height:");
	Serial.print(lifter_height);
	Serial.print(" climbing:");
	Serial.print(climbing);
	Serial.print(" autonomous:");
	Serial.print(autonomous);
	Serial.print(" enabled:");
	Serial.print(enabled);
	Serial.print(" alliance:");
	switch(alliance){
		case INVALID:
			Serial.print("INVALID");
			break;
		case BLUE:
			Serial.print("BLUE");
			break;
		case RED:
			Serial.print("RED");
			break;
		default:
			assert(0);
	}
	Serial.print(")");
}
