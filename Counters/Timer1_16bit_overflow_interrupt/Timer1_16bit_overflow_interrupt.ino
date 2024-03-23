/* 
Example 16-bit Timer1 Interrupt, Flashes LED approx every second
16Mhz clock, divided by 256, divided by (65535 - 34286 = 31249) = 2Hz
so the ledPin value toggles every 500mS which equates to a period of 1s
*/

const int ledPin = 13; //digital pin 13, or D13, or Port B5
                       //The const keyword stands for constant. It is a variable qualifier that modifies the behavior
                       //of the variable, making it "read-only".  Preferred to #define method.
int timer1_counter;    //a variable used to pre-load the timer/counter

void setup()
{
  pinMode(ledPin, OUTPUT);

  //initialize timer1 
  noInterrupts(); // disable all interrupts
  TCCR1A = 0; //Timer 1 Control Register A, clear all bits, set to normal mode, max count = 0xFFFF, Overflow Interrupt on max.
  TCCR1B = 0; //Timer 1 Control Register B, clear all bits, no clock source (Timer/Counter stopped).

  //Set timer1_counter to the correct value for our interrupt interval
  timer1_counter = 34286;   //set variable to counter pre-load value
  
  TCNT1 = timer1_counter;   //preload timer
  TCCR1B |= (1 << CS12);    //Set CS12 bit to 1 in Timer 1 Control Register B i.e. divide by 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   //Bit 0 of TIMSK2 (Timer 1 Interrupt Mask register)
                            //TOIE: Timer/Counter1, Overflow Interrupt Enable
  interrupts();             //enable all interrupts
}

ISR(TIMER1_OVF_vect)        //ISR triggered when Timer/Counter1 overflows
{
  TCNT1 = timer1_counter;   //preload timer again ready for next count up to max
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1); //toggle ledPin state
}

void loop()
{
  delay(10000); //delay 10s to prove that delay() can be interrupted
}
