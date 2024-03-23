
/* This sketch is designed for the ATMega 32A development board, which has a green LED on Port A0 (Pin 40 on the chip)so 
 * don't use for other CPUs as they may not have a Port A.
 */

void setup() {
    
  DDRA = DDRA | B00000001;  // this is safer as it sets port A pin 1 as an output using the bitwise OR operator
                            // without changing the value of pins 2 to 8 
}

void loop() {
  
  PORTA = PORTA | B00000001; // sets port A pin 1 to HIGH using the bitwise OR operator
  delay(100);
  PORTA = PORTA & B11111110; // sets port A pin 1 to LOW using the bitwise AND operator
  delay(1100);

}
