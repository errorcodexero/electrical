#include <FastLED.h>
#include <Blinky.h>

CRGB leds[4];

ColorWheel myColorWheel(12);

void fill_color(CRGB color)
{
  int i;
  for (i=0; i<4; i++)
  {
     leds[i] = color;
  }
}

void bright(int k)
{
  int i;
  for (i=0; i<4; i++)
  {
     leds[i] %= k;
  }
}

void setup() {
FastLED.addLeds <WS2812,2,GRB>(leds, 4);
}


void loop() {
  int pot = analogRead(0);
  int speed = (pot / 4);
  fill_color (0xff0000);
  bright (speed);
  
  FastLED.show();


}
