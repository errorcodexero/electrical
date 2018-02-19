#include <FastLED.h>
#include <Blinky.h>

Blinky<2> myLEDs(4);
ColorWheel myColorWheel(12);

void setup() {
  pinMode(A0, INPUT);
}

void loop() {
  int pwm = pulseIn(A1, HIGH, 100000);
  int speed = (pwm == 0) ? 0 : (pwm - 1500);
  
  if (speed > 20) {
    myLEDs.shiftRight( myColorWheel.next() );
  } else if (speed < -20) {
    myLEDs.shiftLeft( myColorWheel.next() );   
  } else {
    myLEDs.fill( myColorWheel.next() );
  }
  FastLED.show();

  int dly = 100 + (512 - abs(speed)) * 2;
    delay(dly);
}
