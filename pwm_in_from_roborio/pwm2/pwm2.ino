long pulseWidth0 = 0;
long pulseWidth1 = 0;
int delayVal = 100;
int ledPin = 13;
int inputPin = 12;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop(){
  pulseWidth0 = micros();
  if(digitalRead(inputPin) == 1){
    while(digitalRead(inputPin) == 1){
      delayMicroseconds(10);
     }
    pulseWidth1 = micros();
    if ((pulseWidth1 - pulseWidth0)<1100){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, LOW);
    }
  }
}
