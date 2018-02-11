#ifndef LIGHTS_H
#define LIGHTS_H

#include "robot_info.h"
#include "countdown_timer.h"
#include "FastLED.h" // http://fastled.io/docs/3.1/group___colorutils.html

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

class Lights{
  public:
  enum Mode{
    RECENTLY_ENABLED = 0, //flashes alliance color at beginning of match
    AUTONOMOUS = 1, 
    LIFTER_HEIGHT = 2,
    CLIMBING = 3,
    FLAME = 4, //colors a flame slowing from the base
    RANDOMIZED = 5, //sets rgb values randomly 
    FADE = 6, //fades in and out of red and blue
    RAINBOW_CHASE = 7 //colors lights in rainbow and shifts through colors throughout
  };
  
  private: 
  Robot_info last_robot_info;
  Mode mode;
  
  void color_recently_enabled(const Robot_info::Alliance);
  void color_autonomous();
  void color_lifter_height(const unsigned);
  void color_climbing();
  void color_flame();
  void color_randomized();
  void color_fade();
  void color_rainbow_chase();

  Countdown_timer wait_timer;
  
  public: 
  static const unsigned NUMBER_OF_LEDS = 24;
  static const unsigned LED_STRIP_DATA_PIN = 7;
  static const byte MAX_BRIGHTNESS = 50;
  static constexpr double LEDS_PER_INCH = 0.812799561;
    
  CRGB leds[NUMBER_OF_LEDS];

  void set_leds(Robot_info const&,const long);

  void setup();

  Lights();
};

#endif
