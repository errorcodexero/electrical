/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int runpin = 4;  // digital pin used to read the run switch
int shootpin = 5;  //digital pin used to read the shoot switch
int run = 0;    // variable to read the value from the run switch
int shoot = 0; // variable to read the value from the shoot switch

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
}

void loop() {
  run = digitalRead(runpin);            // reads the value of the potentiometer (value between 0 and 1023)
  if (run == 1) {
    myservo.write(166);
  } else {
   myservo.write(90);
  } if (shoot == 1 && run == 1) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(2,LOW);
    digitalWrite(3, LOW);
  }

                 // sets the servo position according to the scaled value
  delay(20);                           // waits for the servo to get there
}

