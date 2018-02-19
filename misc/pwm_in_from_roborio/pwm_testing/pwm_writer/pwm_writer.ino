unsigned output_pin = 9;

void setup() {
  Serial.begin(9600);
}

void loop() {
    for(int output = 0; output < 256; output++){ 
      analogWrite(output_pin, output);//writes a 0-255 int to a pwm signal  
      delay(100);
    } 
}
