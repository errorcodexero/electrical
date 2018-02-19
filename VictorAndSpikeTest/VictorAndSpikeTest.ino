/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo



void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  

  if (!digitalRead(4)) {
    if (!digitalRead(0)) {
      digitalWrite(3, HIGH); 
    } else {
      digitalWrite(3, LOW);
    }
    digitalWrite(2, HIGH);
    myservo.write(0);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    myservo.write(90);
  }
  
  delay(20);                           // waits for the servo to get there
  Serial.write(!digitalRead(13));
}


