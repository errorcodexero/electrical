#include <FastLED.h>
#include <Blinky.h>

Blinky<2> myLEDs(4);
ColorWheel myColorWheel(12);

void setup() {
}

void loop() {
  int pot = analogRead(0);
  int speed = (pot - 512);
  
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
