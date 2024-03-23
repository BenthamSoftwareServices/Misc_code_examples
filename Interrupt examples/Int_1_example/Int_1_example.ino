// uint8_t may be used instead of byte
// Byte, uint8_t and unsigned char, they are basically the same thing in Arduino. These data types often cause confusions to new programmers.
// So is there any difference in them?

// A byte stores an 8-bit unsigned number, from 0 to 255. For example for the number 0, the binary form is 00000000,
// there are 8 zeros (8 bits in total). for the number 255, the binary form is 11111111.

// A uint8_t data type is basically the same as byte in Arduino. Writers of embedded software often define these types,
// because systems can sometimes define int to be 8 bits, 16 bits or 32 bits long. The issue doesn’t arise in C# or Java,
// because the size of all the basic types is defined by the language.

// An unsigned char data type that occupies 1 byte of memory. It is the same as the byte datatype.
// The unsigned char datatype encodes numbers from 0 to 255. For consistency of Arduino programming style, the byte data type is to be preferred.

const uint8_t pulsePin = 8;  //Single yellow LED on D8 (not on starter board)
const byte ledPin = 9;       //Single green LED on D9 on Nano starter board
const byte interruptPin = 3; // INT1 on Port D3 (connected to the green LED in the Tri-colour LED3 on the Nanao starter board,
                             // so D3 can be shorted to ground with a wire in lieu of a switch, this lights LED3 green but also pulls INT1 low
                             // triggering the Interrupt Service Routine called toggle)
volatile byte state = LOW;   // Directs the compiler to use RAM for the variable and not a CPU register, reccomended for ISRs

void setup() {
  pinMode(pulsePin, OUTPUT); //set pulsePin to be an output
  pinMode(ledPin, OUTPUT); //set ledpin to be an output
  pinMode(interruptPin, INPUT_PULLUP); //set interruptPin to be an input with a pullup to 5v
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggle, FALLING); // call IST toggle when negative edge on interruptPin
}

void loop() {
  // Runs constantly to flash LED on D8, but every HIGH to LOW transition tiggers an interrupt calling ISR toggle
  digitalWrite(pulsePin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                     // wait for 500mS
  digitalWrite(pulsePin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                    // wait for a second
}

void toggle() {
  // Toggle the state of the ledPin
  state = !state; //toggle the value of the variable called state)
  digitalWrite(ledPin, state); //write the value of state to ledpin
}
