int leds[] = {2,3,4,5,6,7,8,9};
void setup() 
{
  for(int i=0; i<8; i++) {
    pinMode(leds[i], OUTPUT);
  }
}
void loop() 
{
 for(int i=0; i<7; i++) { 
 digitalWrite(leds[i], HIGH);
 delay(100);
 digitalWrite(leds[i], LOW);
} 
  for(int j=7; j>0; j--) {
 digitalWrite(leds[j], HIGH);
 delay(100);
 digitalWrite(leds[j], LOW);
} 
} 
