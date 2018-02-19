#include "FastLED.h"
#define DATA_PIN1    9
//#define DATA_PIN2    5
#define BRIGHTNESS   64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    10
#define COLOR_RED 0xff4f00

CRGB leds[NUM_LEDS];
//CRGB leds[10][NUM_LEDS];
const int  buttonPin = 3;    // the pin that the pushbutton is attached to
//const int ledPin = 9;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN1, COLOR_ORDER>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE, DATA_PIN1, COLOR_ORDER>(leds[0], NUM_LEDS);
  //FastLED.addLeds<LED_TYPE, DATA_PIN2, COLOR_ORDER>(leds[1], NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
//  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(0);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  int i;
  int j;
  
  if (buttonState != lastButtonState) {
    if (buttonState == 1) {
      buttonPushCounter++;
      Serial.println("1");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    }
  }
    else {
    Serial.println (3);
  }
  lastButtonState = buttonState;

  //if (buttonPushCounter % 2 == 0) {
 //   digitalWrite(ledPin, NUM_LEDS);
    for (j = 0; j < 4; j++) {
      if (j == 0) {
        for (i = 0; i < NUM_LEDS; i++) {
          //leds[0][i] = 0xff8100;
          leds[i]= 0xff8100;
          FastLED.show();
          //delay(100);
          //leds[1][i] = 0xff8100;
          FastLED.show();
          delay(10);
        }
      }
    }
    /*
  }
  else if  (buttonPushCounter % 2 == 1) {
        for (j = 0; j < 4; j++) {
      if (j == 0) {
        for (i = 0; i < NUM_LEDS; i++) {
          leds[0][i] = COLOR_RED;
          FastLED.show();
          //delay(100);
          leds[1][i] = COLOR_RED;
          FastLED.show();
          delay(10);
        }
      }
    }
  }
  */
}
