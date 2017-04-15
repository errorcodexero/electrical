//Is paired with roboRIO and reads pwm values

#include <assert.h>

static const byte PWM_PIN = 6;
static const int DECIMALS_TO_KEEP = 1;
 
void setup() {
  pinMode(PWM_PIN, INPUT);
  Serial.begin(115200);
}
 
void loop() {
  assert(DECIMALS_TO_KEEP > 0);
  double pwm_value = pulseIn(PWM_PIN, HIGH);
  double value = (pwm_value - 1504)/504; //converts pwm to a number between -1.0 and 1.0
  double scaled = round(value * pow(10,DECIMALS_TO_KEEP ));
  Serial.println(scaled);
 // Serial.print("          ");
  //Serial.print(duration);
  //Serial.print("          ");
 // Serial.print(rio);
  //Serial.print("          ");
 // Serial.println(dig);
}
