#include <FastLED.h>

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
const unsigned LED_COUNT = 7;
const uint8_t BRIGHTNESS = 255 * 0.4;

const unsigned PIN_IN = 7;
const unsigned PIN_OUT = 6;

CRGB leds[LED_COUNT];

void setup(){
	FastLED.addLeds<LED_TYPE,PIN_OUT,COLOR_ORDER>(leds, LED_COUNT);
	FastLED.setBrightness(BRIGHTNESS);
	pinMode(PIN_IN, INPUT);
	digitalWrite(PIN_IN, HIGH);
}

void loop(){
	if(digitalRead(PIN_IN) == LOW){
		delay(100);
		fill_solid(leds, LED_COUNT, CRGB::Green);
		delay(100);
		fill_solid(leds, LED_COUNT, CRGB::Black);
		delay(100);
		fill_solid(leds, LED_COUNT, CRGB::Green);
	} 
	else {
		fill_solid(leds, LED_COUNT, CRGB::Red);
	}
	FastLED.show();
}
