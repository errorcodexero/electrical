#include <Wire.h>
#include "robot_info.h"

/*
 * Arduino I2C pins
 * 
 * A4 - SDA (Black)
 * A5 - SCL (Brown)
 */

Robot_info robot_info;
const byte ROBORIO_ID = 8;

void setup() {
  Wire.begin(8);
  Wire.onReceive(receive_event);
  Serial.begin(9600);
  Serial.println("hello world");
}

void loop() {
  delay(100);
  robot_info.print();
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
