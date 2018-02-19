
//Is paired with roboRIO and reads pwm values to pick a blinky lights mode

#include "assert.h"

const int PWM_PIN = 5; // the PWM input pin number
const int DECIMALS_TO_KEEP = 1; //the number of decimals to keep when the value is scaled up and converted to an integer
 
void setup() {
  pinMode(PWM_PIN, INPUT);
  Serial.begin(115200);
}
 
void loop() {
  assert(DECIMALS_TO_KEEP > 0);
  double pwm_value = pulseIn(PWM_PIN, HIGH);
  double value = (pwm_value - 1504.0) / 504.0; //converts values we want to a number between -1.0 and 1.0
  int scaled = (int)round(value * pow(10,DECIMALS_TO_KEEP ));
  const int DISABLED_THRESHOLD = 1; //if the value is greater than this, then the robot's disabled
  bool disabled = scaled  > DISABLED_THRESHOLD;
  Serial.println((String)pwm_value + "   " + (String)value + "   " + (String)scaled);
}

