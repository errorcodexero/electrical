#include <Wire.h>
#include "robot_info.h"

/*
 * Arduino I2C pins
 * 
 * A4 - SDA
 * A5 - SCL
 */

Robot_info robot_info;

void setup() {
	Serial.begin(9600);
	Wire.begin();
}

void loop() {
  const unsigned ROBORIO_ID = 8;
  const byte BYTES_TO_RECIEVE = 6;
  Wire.requestFrom(ROBORIO_ID, BYTES_TO_RECIEVE);
  while(Wire.available()){
    int i = Wire.read();
    Serial.print(i);
  }
  //robot_info.update(0);
 // robot_info.print();
}
