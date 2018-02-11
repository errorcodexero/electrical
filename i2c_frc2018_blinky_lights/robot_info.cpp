#include "robot_info.h"
#include <assert.h>

#ifndef ROBOT_INFO_TEST
#include "Arduino.h"
#else
#include <iostream>
#endif

using namespace std;

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

void Robot_info::print()const{
	#ifndef ROBOT_INFO_TEST
	
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
	cout<<"lifter_height:"<<lifter_height<<" climbing:"<<climbing<<" autonomous:"<<autonomous<<" enabled:"<<enabled<<" alliance:"<<s<<"\n";
	
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
