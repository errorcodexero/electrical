#ifndef UTIL_H
#define UTIL_H

#include "FastLED.h"
#include "robot_info.h"

void shift_leds(const CRGB, CRGB*, const unsigned LEN);

CRGB alliance_to_color(const Robot_info::Alliance);

#endif
