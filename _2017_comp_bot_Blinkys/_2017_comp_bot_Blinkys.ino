#include <FastLED.h>
#include <Blinky.h>
#include <math.h>

CRGB leds[12];
ColorWheel myColorWheel(240);              //set to a good number

void step_right()
{
  int i;
  for (i = 12; i > 0; i--)
  {

    leds[i] = leds[i - 1];

  }
}
void super(int percent, CRGB color)
{
  int i;
  for (i = 12; i > 0; i--)
  {

    leds[i] = leds[i - 1];

  }
  leds[0] = color;
  leds[0] %= percent;
}
void fill_color(CRGB color)
{
  int i;
  for (i = 0; i < 12; i++)
  {
    leds[i] = color;
  }
}


void setup() {
  FastLED.addLeds <WS2812, 13, GRB>(leds, 12);      // 13 pin originally
  FastLED.addLeds <WS2812, 12, GRB>(leds, 12);
  FastLED.addLeds <WS2812, 11, GRB>(leds, 12);
  pinMode(A0, INPUT);
  pinMode(A7, INPUT);
  pinMode(3, INPUT);
  int pot = 0;
  Serial.begin(9600);
  int val = 0;
  
}

void loop() {
  float val = (exp(sin(millis() / 2000.0 * PI)) - 0.36787944) * 108.0;
  int sponge = 3;

  switch (sponge)
  {
    case 0:
      super(100, 0xff0000); 
      FastLED.show();
      break;
    case 1:
      //Breathing color change
      super(val, myColorWheel.next());
      FastLED.show();
      delay(20);
      FastLED.show();
      break;
    //    Shooting BLINKS
    case 2:
      fill_color(0xff0000);
      delay(200);
      FastLED.show();
      fill_color(0x000000);
      delay(200);
      FastLED.show();

      break;
    //    Climbing Blinky
    case 3:

      int climb;
      {
        for (climb = 255; climb > 0; climb--)
        { //Start out RED and fade to nothing
          super(climb, 0xff0000);
          delay(5);
          FastLED.show();
        }
        for (climb = 0; climb < 255; climb++)
        { //Start at nothing and build to ORANGE
          super(climb, 0xff3600);
          delay(5);
          FastLED.show();
        }
        for (climb = 255; climb > 0; climb--)
        { //Start at ORANGE and fade to nothing
          super(climb, 0xff3600);
          delay(5);
          FastLED.show();
        }
        for (climb = 0; climb < 255; climb++)
        { //Start at nothing and build to YELLOW
          super(climb, 0xffff00);
          delay(5);
          FastLED.show();
        }
        for (climb = 255; climb > 0; climb--)
        { //Start at YELLOW and fade to nothing
          super(climb, 0xffff00);
          delay(5);
          FastLED.show();
        }
        for (climb = 0; climb < 255; climb++)
        { //Start at nothing and build to RED
          super(climb, 0xff0000);
          delay(5);
          FastLED.show();
        }
      }
      break;
  case 4:
    //Indicator Solid
    super(255, 0x00ff00);
    FastLED.show();
    delay(100);
  break;  
  
  case 5:
    //Indicator Solid
    super(255, 0x00ff00);
    FastLED.show();
    delay(1000);
    super(128, 0x000000);
    FastLED.show();
    delay(1000);
  break; 
  
  }
super(128, 0xff0000);
FastLED.show();
delay(1);
Serial.println(3);


}


