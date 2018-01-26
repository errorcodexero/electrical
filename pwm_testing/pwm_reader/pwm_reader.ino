unsigned input_pin = 9;

void setup(){
  Serial.begin(9600);
  pinMode(input_pin, INPUT);
}

double calculate_duty_cycle(unsigned input_pin){//reads the pwm value of an input
  unsigned long high_time = pulseIn(input_pin, HIGH);
  unsigned long low_time = pulseIn(input_pin, LOW);
  unsigned long cycle_time = high_time  + low_time;
  double duty_cycle = (double)high_time / (double)cycle_time;
  return duty_cycle;
}

void loop(){
  double duty_cycle = calculate_duty_cycle(input_pin);
  double value = duty_cycle * 255;// multiply by 255 since analogWrite maps a 0-255 value to a 0-1
  Serial.println(value);
}
