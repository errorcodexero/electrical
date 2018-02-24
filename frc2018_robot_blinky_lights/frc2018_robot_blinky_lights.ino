#include <Wire.h>
#include <Gong.h>

#include "robot_lights.h"
/*
 * Arduino I2C pins
 * 
 * A4 - SDA (Black)
 * A5 - SCL (Brown)
 */

Robot_info robot_info;
Controller controller = Controller(new Robot_lights());/*
	{
		new Recently_enabled({
				Robot_lights::Led_index::LEFT_STRIP,
				Robot_lights::Led_index::RIGHT_STRIP
			}),
						new Autonomous(),
		new Has_cube(),
		new Lifter_height(),
		new Climbing(),
		new Flame(),
		new Randomized(),
		new Alliance_fade(),
		new Rainbow_chase(),
		new Rainbow_stripes(),
		new Random_stream(),
		new Two_color_fade(),
		new Fade(),
		new Flame_stripes(),
		new Off()
	}
);
*/
const byte ROBORIO_ID = 8;

Countdown_timer lifter_timer = Countdown_timer(500);//to test

unsigned h = 0;//to test

void setup(){
	randomSeed(millis());
	Wire.begin(ROBORIO_ID);
	Wire.onReceive(receive_event);
	Serial.begin(9600);
	Serial.println("Set up complete.");
}

void loop() {
	//robot_info.climbing = true;
	robot_info.alliance = Robot_info::Alliance::RED;
	{//to test
		robot_info.lifter_height = h;
		if(lifter_timer.done()){
			robot_info.enabled = true; 
			//robot_info.autonomous = true;
			lifter_timer.set(500);
			h++;
		}
		if(h > 30){
			h = 0;	
		}
	}
	
	//robot_info.drive_left += 0.01;
	//if(robot_info.drive_left < -1 || robot_info.drive_left > 1){
	//	robot_info.drive_left = 0;
	//}
	
	robot_info.println();
	controller.set_leds(robot_info);
}

void receive_event(int number_received){
	int received[number_received];
	int i = 0;
	while (0 < Wire.available()){ // loop through all 
		int x = Wire.read();
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
