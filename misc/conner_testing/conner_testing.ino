void setup() {
	pinMode(8,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
	digitalWrite(8,HIGH);
	digitalWrite(6,LOW);
	delay(100);
	digitalWrite(8,LOW);
	digitalWrite(7,HIGH);
	delay(100);
	digitalWrite(6,HIGH);
	digitalWrite(7,LOW);
	delay(100);
}
