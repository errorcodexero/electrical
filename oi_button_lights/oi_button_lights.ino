#define IN_LIFTER_A 11
#define IN_LIFTER_B 12
#define IN_LIFTER_C 13
#define IN_COLLECT_OPEN 14
#define IN_COLLECT_CLOSED 15
#define IN_HAS_CUBE 16
#define IN_WING_LOCK_DISABLED 17
#define IN_ENABLED 0
#define INPUTS 8

#define OUT_FLOOR 1
#define OUT_EXCHANGE 2
#define OUT_SWITCH 3
#define OUT_SCALE 4
#define OUT_CLIMB 5
#define OUT_COLLECT_CLOSED 6
#define OUT_COLLECT_OPEN 7
#define OUT_EJECT 8
#define OUT_DROP 9
#define OUT_WING_RELEASE 10
#define OUTPUTS 10

int inputs[INPUTS] = {IN_LIFTER_A, IN_LIFTER_B, IN_LIFTER_C, IN_COLLECT_OPEN, IN_COLLECT_CLOSED, IN_HAS_CUBE, IN_WING_LOCK_DISABLED, IN_ENABLED};
int outputs[OUTPUTS] = {OUT_FLOOR, OUT_EXCHANGE, OUT_SWITCH, OUT_SCALE, OUT_CLIMB, OUT_COLLECT_CLOSED, OUT_COLLECT_OPEN, OUT_EJECT, OUT_DROP, OUT_WING_RELEASE};

bool output_values[OUTPUTS];

void setup() {
  for(int i = 0; i < INPUTS; i++) {
    pinMode(inputs[i], INPUT);
  }
  for(int i = 0; i < OUTPUTS; i++) {
    pinMode(outputs[i], OUTPUT);
    output_values[OUTPUTS] = false;
  }
  output_values[0] = true;
}

void loop() {
  if(digitalRead(IN_ENABLED) == HIGH) {
    int lifter_pos = 0;
    if(digitalRead(IN_LIFTER_A)) lifter_pos += 4;
    if(digitalRead(IN_LIFTER_B)) lifter_pos += 2;
    if(digitalRead(IN_LIFTER_C)) lifter_pos += 1;
    digitalWrite(OUT_FLOOR, lifter_pos == 1 ? HIGH : LOW);
    digitalWrite(OUT_EXCHANGE, lifter_pos == 2 ? HIGH : LOW);
    digitalWrite(OUT_SWITCH, lifter_pos == 3 ? HIGH : LOW);
    digitalWrite(OUT_SCALE, lifter_pos == 4 ? HIGH : LOW);
    digitalWrite(OUT_CLIMB, lifter_pos == 5 ? HIGH : LOW);
    
    digitalWrite(OUT_COLLECT_CLOSED, digitalRead(IN_COLLECT_CLOSED));
    digitalWrite(OUT_COLLECT_OPEN, digitalRead(IN_COLLECT_OPEN));
    
    int has_cube = digitalRead(IN_HAS_CUBE);
    digitalWrite(OUT_EJECT, has_cube);
    digitalWrite(OUT_DROP, has_cube);
    
    digitalWrite(OUT_WING_RELEASE, digitalRead(IN_WING_LOCK_DISABLED));
    
    delay(50);
  } else {
    bool overflowed = output_values[OUTPUTS - 1];
    for(int i = OUTPUTS - 2; i >= 0; i--) {
      if(output_values[i]) {
        output_values[i] = false;
        output_values[i + 1] = true;
      }
    }
    if(overflowed) output_values[0] = true;
    
    for(int i = 0; i < OUTPUTS; i++) {
      digitalWrite(outputs[i], output_values[i] ? HIGH : LOW);
    }
    
    delay(250);
  }
}
