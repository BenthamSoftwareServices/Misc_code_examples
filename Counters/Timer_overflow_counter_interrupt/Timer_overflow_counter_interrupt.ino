/* a sketch that blinks the on-board LED (the one tied to D13) on the Arduino UNO using timer overflow. 
 * I adjusted the overflow frequency because 1 millisecond would be too fast for our eyes to see. 
 * To slow down the timer, we need to increase the divisor value, this is done by writing to the TCCR2B register.
 * With a 16Mhz clock, 2^8 or 256 timer counts & a divisor of 1024 the overflow time is 16.384mS
 * so as the ledPin state cycle is two overflow periods or 33.668mS the LED flashes at 29.7Hz i.e. quite visible
*/
const int ledPin = 13; //digital pin 13, or D13, or Port B5
                       //The const keyword stands for constant. It is a variable qualifier that modifies the behavior
                       //of the variable, making it "read-only".  Preferred to #define method.
volatile byte state = LOW; //volatile stores state in SRAM not a CPU register
 
void setup() {
   pinMode(ledPin, OUTPUT);
   TIMSK2 = (TIMSK2 & B11111110) | 0x01; //Bit 0 of TIMSK2 (Timer 2 Interrupt Mask register)
                                         //TOIE: Timer/Counter2, Overflow Interrupt Enable
                                         //use mask so that only the least significant bit is affected
                                         
   TCCR2B = (TCCR2B & B11111000) | 0x07; //Bits 2:0 – CS2[2:0]: Clock Select of TCCR2B (Timer 2 Control Register B) 
                                         //use mask so that only the least three significant bits
                                         //are affected. 0x07 = clkI/O/1024 (From prescaler)
                                         
}
 
void loop() {
   digitalWrite(ledPin, state); //write state to ledPin
}
 
ISR(TIMER2_OVF_vect){  //ISR triggered when Timer/Counter2 overflows
   state = !state;     //toggle variable state
}
