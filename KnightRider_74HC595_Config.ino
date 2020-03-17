#define LATCH 9
#define CLOCK 10
#define DATA 8
static int led = 0;
byte number[23] = {0b00000000,
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
                 0b10000000,
                 0b11000000,
                 0b11100000,
                 0b01110000,
                 0b00111000,
                 0b00011100,
                 0b00001110,
                 0b00000111,
                 0b00000011,
                 0b00000001,
                 0b00000000
                };
void setup() {
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
}
void loop() {
  static unsigned long time = millis();
  if (millis() - time >= 80 && led <= 22) {
    time = millis();
    led++;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, number[led]);
    digitalWrite(LATCH, HIGH);
  }
  if (led == 22) {
    led = 0;
  }
}
