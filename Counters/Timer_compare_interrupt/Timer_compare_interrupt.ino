/*Every time the timer’s count is equal to a value, an interrupt occurs. This is called Timer Compare Interrupt.
  When using timer overflow interrupt, the interrupt triggers after 255 counts.
  In compare mode, the interrupt triggers from any count value that we set!
  Not only that, but you can compare the timer value to two values.
  There are two possible comparisons, A and B. To compare to A, the timer value is compared to the OCRxA register
  where 'x' is the timer number. Thus, for Timer2 the register is OCR2A.
  For example, if I want the interrupt to trigger after 128 counts, this must be the value of OCR2A.
  To compare to B, the value to be compared must be written to the OCR2B register.
  So let’s say I want another interrupt to trigger at count 254, then OCR2B = 254.
  To know if Compare A or Compare B have triggered an interrupt, we refer to their corresponding vectors: TIMER2_COMPA and TIMER2_COMPB.
  Of course, we still need to enable the compare interrupt first. Setting bits OCIEA and OCIEB on the TIMSK2 register does this.
  With a 16Mhz clock, 2^8 or 256 timer counts & a divisor of 1024 the overflow time is 16.384mS, but the LED changes state twice in
  this period so flashes at 61 Hz i.e. quite difficult to see!
*/
const int ledPin = 13; //digital pin 13, or D13, or Port B5
                       //The const keyword stands for constant. It is a variable qualifier that modifies the behavior
                       //of the variable, making it "read-only".  Preferred to #define method.
volatile byte state = LOW; //volatile stores state in SRAM not a CPU register
 
void setup() {
   pinMode(ledPin, OUTPUT);
   TIMSK2 = (TIMSK2 & B11111001) | 0x06; //Bits 2 & 1 of TIMSK2 (Timer 2 Interrupt Mask register)
                                         //Bit 2 – OCIEB: Timer/Counter2, Output Compare B Match Interrupt Enable
                                         //Bit 1 – OCIEA: Timer/Counter2, Output Compare A Match Interrupt Enable
                                         //using a mask to protect other bits
   TCCR2B = (TCCR2B & B11111000) | 0x07; //Bits 2:0 – CS2[2:0]: Clock Select of TCCR2B (Timer 2 Control Register B) 
                                         //use mask so that only the least three significant bits
                                         //are affected. 0x07 = clkI/O/1024 (From prescaler)
   OCR2A = 128; //Bits 7:0 – OCR2A[7:0]: Timer 2 Output Compare register A
   OCR2B = 254; //Bits 7:0 – OCR2B[7:0]: Timer 2 Output Compare register B
}
void loop() {
   digitalWrite(ledPin, state); //write variable state to the LED
}
ISR(TIMER2_COMPA_vect){
   state = LOW; //set the variable state low
}
ISR(TIMER2_COMPB_vect){
   state = HIGH; //set the variable state high
}
