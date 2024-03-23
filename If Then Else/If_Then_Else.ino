// Declarations
// Can just delare a variable, or declare and assign an initial value e.g. int outputValue =0;
int outputValue = 0;
int inputValue = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay (50); //delay 50mS
  inputValue = analogRead (A5); //Pin 28 on 328P 28-pin PDIP
  if (inputValue <= 300) {
    outputValue++;
  } else {
    outputValue--;
  }
  OCR1A = outputValue;  //Pin15 on 328P 28-pin PDIP = Port B1 (OC1A, PCINT1) NANO Pin D9
  OCR1B = outputValue;  //Pin16 on 328P 28-pin PDIP = Port B2 (/SS, OC1B, PCINT2) NANO Pin D10
}
