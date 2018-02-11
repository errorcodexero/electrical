#include <Wire.h>
#include "lights.h"

/*
 * Arduino I2C pins
 * 
 * A4 - SDA (Black)
 * A5 - SCL (Brown)
 */

Robot_info robot_info;
Lights lights;
const byte ROBORIO_ID = 8;

Countdown_timer disabled_timer;//to test enabled

unsigned h = 0;

void setup(){
  lights.setup();
  Wire.begin(8);
  Wire.onReceive(receive_event);
  Serial.begin(9600);
  Serial.println("hello world");
  
  disabled_timer.set(500);//to test
}

void loop() {
  {//to test
    robot_info.lifter_height = h;
    disabled_timer.update(millis());
    if(disabled_timer.done()){
       disabled_timer.set(500);//to test
       h++;
    }
  }
  robot_info.print();
  lights.set_leds(robot_info,millis());
  delay(5);
}

void receive_event(int number_received){
  int received[number_received];
  int i = 0;
  while (0 < Wire.available()){ // loop through all 
    int x  = Wire.read();
    received[i] = x;
    //Serial.println(received[i]);
    i++;
  }
  robot_info.update(
    received[0],
    received[1],
    received[2],
    received[3],
    received[4]
  );
}
