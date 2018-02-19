void setup() {
  Serial.begin (9600) ;
  pinMode (11,OUTPUT) ;
  pinMode (13, OUTPUT) ;
  pinMode (10, OUTPUT) ;
  digitalWrite (11, LOW) ;
  digitalWrite (13, LOW) ;
  digitalWrite (10, LOW) ;

}

int bit=0 ;
void loop(){
for(int i=0;i <8;i++){
digitalWrite (11, bit) ;
digitalWrite (13, HIGH) ;
delay (100) ;
digitalWrite (13, LOW) ;
delay (100) ;
bit= !bit ;
}
digitalWrite (10, HIGH) ;
delay (1) ;
digitalWrite (10, LOW) ;
delay (3000) ;
bit= !bit ;
}
