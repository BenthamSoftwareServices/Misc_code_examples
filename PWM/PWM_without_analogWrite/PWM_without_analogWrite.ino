// Declarations
// Can just delare a variable, or declare and assign an initial value e.g. int outputValue =0;
int outputValue;
int pot;

void setup() {
  // put your setup code here, to run once:
  TCCR1A = 0xB2;
  TCCR1B = 0x11;  // 11 for Phase Correct, 19 for fast
  ICR1 = 0x01FF;
  DDRB = 0x06;
}

void loop() {
  // put your main code here, to run repeatedly:
  //int pot = analogRead (A5) /2; //Pin 28 on 328P 28-pin PDIP
  pot = analogRead (A5); //Pin 28 on 328P 28-pin PDIP
  outputValue = map(pot, 5, 1000, 0, 511);
  //OCR1A = outputValue;  //Pin15 on 328P 28-pin PDIP
  OCR1A = 256;  //Pin15 on 328P 28-pin PDIP
  OCR1B = pot;  //Pin16 on 328P 28-pin PDIP
}
