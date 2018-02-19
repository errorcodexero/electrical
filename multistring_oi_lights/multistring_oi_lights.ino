#include <FastLED.h>
#include <Blinky.h>
#include <Math.h>

int percent = 0;

CRGB leds[13]; //13 blinkys for all once got to actual strip

ColorWheel ColorWheelA(39);
ColorWheel ColorWheelB(260);
ColorWheel ColorWheelC(7);
ColorWheel ColorWheelD(260);
ColorWheel ColorWheelE(260);



void fill_color(CRGB color)
{

  int i;
  for (i = 0; i < 12; i++)
  {
    leds[i] = color;
  }
}

void bright(int k)
{
  int i;
  for (i = 0; i < 13; i++)
  {
    leds[i] %= k;
  }
}

void step_right()
{
  int i;
  for (i = 13; i > 0; i--)
  {

    leds[i] = leds[i - 1];

  }
}

void super(int percent, CRGB color)
{
  int i;
  for (i = 13; i > 0; i--)
  {

    leds[i] = leds[i - 1];

  }
  leds[0] = color;
  leds[0] %= percent;
}

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds <WS2812, 11, GRB>(leds, 13);
  FastLED.addLeds <WS2812, 12, GRB>(leds, 13);
  FastLED.addLeds <WS2812, 13, GRB>(leds, 13);
  Serial.begin(9600);
  int val = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot = analogRead(7);
  int bright = (pot / 102.4);
  Serial.print(pot);
  Serial.print("          ");
  Serial.println(bright);
  float val = (exp(sin(millis() / 2000.0 * PI)) - 0.36787944) * 108.0;

  int reloj = 0;
  switch (bright)
  {
    case 0:
      super(200, ColorWheelB.next());
      FastLED.show();
      delay(20);
      break;
    case 1:
      super(200, ColorWheelA.next());
      FastLED.show();
      delay(500);
      break;
    case 2:
      super(val, ColorWheelB.next());
      FastLED.show();
      delay(20);
      break;
    case 3:
      super(255, ColorWheelA.next());
      FastLED.show();
      delay(20);
      break;
    case 4:
      super(255, 0xff0000);
      FastLED.show();
      delay(10);
      break;
    case 5:
    super(255, 0xff3600);
      FastLED.show();
      delay(10);
      break;
    case 6:
    super(255, 0xffff00);
      FastLED.show();
      delay(10);
      break;
    case 7:
    int climb;
    for (climb = 0; climb < 255; climb++) {
    super(climb, ColorWheelB.next());
    FastLED.show();
    delay(5);
    }
    for (climb = 255; climb > 0; climb--) {
    super(climb, ColorWheelB.next());
    FastLED.show();
    delay(5);
    }
      break;
    case 8:
      break;
    case 9:
    super(0,0x000000);
    FastLED.show();
    delay(10);
      break;

  }
}
