#define DATA 8
#define LATCH 9
#define CLOCK 10
int pot=A0;
byte number[] = {0b00000000,
                 0b00000001,
                 0b00000011,
                 0b00000111,
                 0b00001110,
                 0b00011100,
                 0b00111000,
                 0b01110000,
                 0b11100000,
                 0b11000000,
                 0b10000000,
                 0b00000000,             
                };
void setup() {
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(pot,INPUT);
}
void loop() {
  int potvalue = analogRead(pot);
  potvalue=  map(potvalue,0,1023,0,11);
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, number[potvalue]);
  digitalWrite(LATCH, HIGH);  
}
