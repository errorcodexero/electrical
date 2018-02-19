#include <FastLED.h>
int pattern = 0;
int light = 0;
int location = 0;
CRGB leds[4];

void setup() 
{
  // put your setup code here, to run once
  FastLED.addLeds<WS2812, 4, GRB>(leds, 4);


/*
 int i;
  for (i=0; i<5; i++)
  {
     leds[i] = (0xffffff);
  }
  FastLED.show();
 */ 
}

void fill_color(CRGB color)
{
   int i;
  for (i=0; i<5; i++)
  {
     leds[i] = color;
  }
  FastLED.show();
}

void colour(int led, CRGB color)
{
  leds[led] = (color);   
  FastLED.show();   
}

void step_right()
{
  int i;
  for (i=4; i<0; i--)
  {
    leds[i] = (0xffffff);
    leds[i] = leds[i-1];
    
  }
}
void loop() 
{
  /*
    switch (pattern) 
  {
    case 0:
    fill_color (0xff0000);
    pattern = 1;
    break;
   
    case 1:
    fill_color (0x00ff00);
    pattern = 2;
    break;

    case 2:
    fill_color (0x0000ff);
    pattern = 3;
    break;

    case 3:
    fill_color (0xffff00);
    pattern = 4;
    break;

    case 4:
    fill_color (0x00ffff);
    pattern = 0;
    break;
  }
  FastLED.show();
  delay (1000);
  */
  //Testing the light integer switch
  /*
   switch (light)
 {
  case 0:
  colour (0, 0xff0000);
  light = 1;
  break;

  case 1:
  colour (0, 0x00ff00);
  light = 2;
  break;

  case 2:
  colour (0, 0x0000ff);
  light = 0;
  break;
  
 }
 FastLED.show(); 
 delay (1000);
 */
  /*
  switch (location)
  
  {
    case 0:
    colour (0, 0xff0000);
    colour (3, 0x000000);
    location = 1;
    break;

    case 1:
    colour (1, 0xff0000);
    colour (0, 0x000000);
    location = 2;
    break;

    case 2:
    colour (2, 0xff0000);
    colour (1, 0x000000);
    location = 3;
    break;

    case 3:
    colour (3, 0xff0000);
    colour (2, 0x000000);
    location = 0;
    break;
    
  }
  FastLED.show();
  delay (1000);
  */
//Attempt at easy color change.

    
  int i = 0;
  while (i<4)
  {
    colour (i, 0xff0000);
    delay (500);
    colour (i--, 0xff4500);
    colour (i--, 0xffff00);
    colour (i--, 0x000000);
    colour (i--, 0x000000);
    i = i + 5;
    //delay (500);
  }
  
  //Attempt at 2 led train
  /*  
    int i = 0;
  while (i<4)
  {
    colour (i, 0xff0000);
    delay (500);
    colour (i--, 0xff4500);
    //colour (i--, 0xffff00);
    colour (i--, 0x000000);
    i = i + 3;
    //delay (500);
  }
  */


}

