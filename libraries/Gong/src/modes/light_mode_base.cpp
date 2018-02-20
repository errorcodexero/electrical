#include "light_mode_base.h"
#include "assert.h"

void Light_mode_base::clear(Lights* lights, unsigned strips[]){
	for(unsigned i = 0; i < 
		fill_solid(lights -> get(strips[i]), lights -> length(strips[i]), CRGB::Black);
		FastLED.show();
	}
}