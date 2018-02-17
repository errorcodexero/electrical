#include <Wire.h>
#include "lights.h"
#include "countdown_timer.h"

/*
 * Arduino I2C pins
 * 
 * A4 - SDA (Black)
 * A5 - SCL (Brown)
 */

Robot_info robot_info;
Lights lights;
const byte ROBORIO_ID = 8;

Countdown_timer lifter_timer = {500};//to test

unsigned h = 0;//to test

void setup(){
	randomSeed(millis());
	lights.setup();
	Wire.begin(ROBORIO_ID);
	Wire.onReceive(receive_event);
	Serial.begin(9600);
	Serial.println("Set up complete.");
}

void loop() {
	robot_info.alliance = Robot_info::Alliance::RED;
	{//to test
		robot_info.lifter_height = h;
		if(lifter_timer.done()){
			robot_info.enabled = true; 
			lifter_timer.set(500);
			 h++;
		}
		if(h > 30){
			h = 0;	
		}
	}
	robot_info.println();
	lights.set_leds(robot_info);
	delay(0);//TODO
}

void receive_event(int number_received){
	int received[number_received];
	int i = 0;
	while (0 < Wire.available()){ // loop through all 
		int x	= Wire.read();
		received[i] = x;
		i++;
	}
	robot_info.update(
		received[0],
		received[1],
		received[2],
		received[3],
		received[4],
		received[5],
		received[6],
		received[7]
	);
}
