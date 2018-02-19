#include <FastLED.h>
#include <Blinky.h>
ColorWheel myColorWheel(12);
CRGB leds[4];
//int fire = 0;
//int pot = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (A2,INPUT_PULLUP);
  FastLED.addLeds <WS2812,2,GRB>(leds, 4);
  pinMode (A0,INPUT);

}



void fill_color(CRGB color)
{
  int i;
  for (i=0; i<4; i++)
  {
     leds[i] = color;
  }
}

/*
void bright(CRGB color, int k)
{
  int i;
  for (i=0; i<4; i++)
  {
     leds[i] = color;
  }
}
*/

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead (A2) == LOW)
    fill_color (myColorWheel.next());
  else
    fill_color (0xffffff);
  FastLED.show();
  delay(250);

  int pot = analogRead(A0);
  int fire = (pot / 4);
  leds[1] %= fire;
}

