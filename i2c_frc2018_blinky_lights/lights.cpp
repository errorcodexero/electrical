#include "lights.h"
#include <assert.h>

Lights::Lights():mode(RANDOMIZED){}

void Lights::setup(){
  FastLED.addLeds<LED_CONTROLLER,LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
  FastLED.setBrightness(MAX_BRIGHTNESS);
}

void Lights::color_recently_enabled(const Robot_info::Alliance ALLIANCE){
  if(wait_timer.get_now() % 2 == 0){//flash color
    fill_solid(leds, NUMBER_OF_LEDS, CRGB::Black);
    return;
  }
  switch(ALLIANCE){//pick color to flash
    case Robot_info::Alliance::RED:
      fill_solid(leds, NUMBER_OF_LEDS, CRGB::Red);
      return;
    case Robot_info::Alliance::BLUE:
      fill_solid(leds, NUMBER_OF_LEDS, CRGB::Blue);
      return;
    default:
      ;//nothing
  }
}

void Lights::color_autonomous(){
  
}

void Lights::color_lifter_height(const unsigned LIFTER_HEIGHT){
  int led_height = LIFTER_HEIGHT * LEDS_PER_INCH;
  fill_solid(leds, min(led_height, NUMBER_OF_LEDS), CRGB::Blue);
}

void Lights::color_climbing(){
  
}

void Lights::color_flame(){
  CRGB last_leds[NUMBER_OF_LEDS];
  for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
    last_leds[i] = leds[i];
  }
  for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
    unsigned red = random(10, 255);
    unsigned green = random(0, red / 2);
    CRGB new_led = (random(0,3) != 0) ? CRGB(red,green,0) : leds[i];
    leds[i] = ((int)i - 1 >= 0) ? last_leds[i - 1] : new_led;
    leds[i].fadeToBlackBy(MAX_BRIGHTNESS / NUMBER_OF_LEDS);
  }
  /*
  double green_segment_size = random(3, 5);
  for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
    unsigned red = (255 / NUMBER_OF_LEDS) * (NUMBER_OF_LEDS - i);
    if(random(0,20) == 0){
      red *= 0.5;
    }
    unsigned green = [=]{
      if(i < NUMBER_OF_LEDS * (1.0 / green_segment_size)){
        return random(0, red / 7);
      }
      if(i < NUMBER_OF_LEDS * (2.0 / green_segment_size)){
        return random(0, red / 4);
      }
      return random(0, red / 2);
    }();
    leds[i] = CRGB(red, green, 0);
  }
  */
}

void Lights::color_randomized(){
  randomSeed(wait_timer.get_now());
  
  for(CRGB& led: leds){
    int r = random(0,255);
    int g = random(0,255);
    int b = random(0,255);
    led = CRGB(r, g, b);
    
    delay(5);//TODO
  }
}

void Lights::color_fade(){
  const double UPDATE_DELAY = .1;//slows the color changing by this percent

  const unsigned COLORS = 2;
  const unsigned COLOR_RANGE = 255 * 2;//255 per color, times two to fade in and out

  unsigned blue = [=]{
    unsigned color_picker = (int)(wait_timer.get_now() * UPDATE_DELAY) % (COLOR_RANGE * COLORS);
    if(color_picker > 0 * COLOR_RANGE && color_picker < 1 * COLOR_RANGE){
      unsigned remainder = color_picker % COLOR_RANGE;
      if(remainder < 256){
       return remainder % 256;
      }
      return (COLOR_RANGE - remainder) % 256;
    }
    return (unsigned)0;
  }();
  unsigned red = [=]{
    unsigned color_picker = (int)(wait_timer.get_now() * UPDATE_DELAY) % (COLOR_RANGE * COLORS);
    if(color_picker > 1 * COLOR_RANGE && color_picker < 2 * COLOR_RANGE){
      unsigned remainder = color_picker % COLOR_RANGE;
      if(remainder < 256){
       return remainder % 256;
      }
      return (COLOR_RANGE - remainder) % 256;
    }
    return (unsigned)0;
  }();
  fill_solid(leds,NUMBER_OF_LEDS,CRGB(red,0,blue));
}

void Lights::color_rainbow_chase(){
  const double UPDATE_DELAY = .1;//slows the color chaning by this percent

  unsigned hue = [=]{
   int remainder = (int)(wait_timer.get_now() * UPDATE_DELAY) % 512;
   if(remainder  < 256){
     return remainder ;
   } 
   return 512 - remainder ;
  }();
  const unsigned HUE_DELTA = 5;
  fill_rainbow(leds,NUMBER_OF_LEDS,hue,HUE_DELTA);
}

void Lights::set_leds(Robot_info const& ROBOT_INFO, const long T){
  wait_timer.update(T);

  Mode last_mode = mode;
  mode = [=]{
    if((last_mode == RECENTLY_ENABLED && !wait_timer.done()) || (ROBOT_INFO.enabled && !last_robot_info.enabled)){
      if(last_mode != RECENTLY_ENABLED){
        wait_timer.set(2000);
      }
      return RECENTLY_ENABLED;
    }
    if(ROBOT_INFO.climbing){
      return CLIMBING;
    }
    if(ROBOT_INFO.autonomous){
      return AUTONOMOUS;
    }
    return FLAME;//TODO: cycle through other modes at regular intervals
  }();
  
  switch(mode){
    case RECENTLY_ENABLED: 
      color_recently_enabled(ROBOT_INFO.alliance);
      break;
    case AUTONOMOUS:
      color_autonomous();
      break;
    case LIFTER_HEIGHT:
      color_lifter_height(ROBOT_INFO.lifter_height);
      break;
    case CLIMBING:
      color_climbing();
      break;
    case FLAME:
      color_flame();
      break;
    case RANDOMIZED:
      color_randomized();
      break;
    case FADE:
      color_fade();//s
      break;
    case RAINBOW_CHASE:
      color_rainbow_chase();
      break;
    default:
      ;//nothing
  }

  FastLED.show();
  
  last_robot_info = ROBOT_INFO;
}

