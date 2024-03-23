#include <EEPROM.h>
static float f_val = 1823.6794; //Declare floating point variable and set initial value
static float f_prt = 423.4567; //Declare floating point variable and set initial value
static char valstr[10]; //Create a character array with ten elements, index nine is the last element, should be greater than StringLengthIncDecimalPoint
static char prtstr[10]; //Create a character array with ten elements, index nine is the last element, should be greater than StringLengthIncDecimalPoint

void setup() {
//initialize the default Arduino LED pin as an output.
  pinMode(13, OUTPUT);

//Clear all EEPROM locations to 0, which is not necessary and just used for initial testing
//  for (int i = 0 ; i < EEPROM.length(); i++)
//  {
//    EEPROM.write(i, 0); //Clear all EEPROM locations to 0
//  }
//    delay(10); //wait 10mS for final EEPROM clear to complete
    
//Write 4-byte floating point variable f_val to EEPROM location 0, 1, 2 & 3 starting at 0
    EEPROM.put(0, f_val);  //.put is OK for any data type .write is only for bytes!
    delay(10); //wait 10mS for write to EEPROM to complete
    
//Convert f_val, a floating point number, to a string and writes to the 10 element array valstr
    dtostrf(f_val,8, 3, valstr);
    
  // dtostrf(floatvar, StringLengthIncDecimalPoint, numVarsAfterDecimal, charbuf);
  // where:
  // floatvar is the float variable
  // StringLengthIncDecimalPoint is the length of the string that will be created and should be >= number of digits plus decimal point
  // in the converted string e,g, should be 8 for 1823.679 or 7 for 423.457, values bigger than necessary just add leading blank spaces
  // numVarsAfterDecimal is the number of digits after the deimal point to print
  // charbuf is the array to store the results

  Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission
  Serial.println(valstr); //print character array valstr

    EEPROM.get(0, f_prt); // Read EEPROM location 0 to variable prtstr, comment out to print starting value of F_prt, otherwise reads
    //back F_val stored in EEPROM

//Convert f_prt, a floating point number, to an 8 character string and writes to the 10 element array prtstr
  dtostrf(f_prt,8, 3, prtstr);  //Converts a floating point number (double) to a string
  Serial.println(prtstr);

//Convert f_prt, a floating point number, to an 7 character string and writes to the 10 element array prtstr
  dtostrf(f_prt,7, 3, prtstr);  //Converts a floating point number (double) to a string
  Serial.println(prtstr);

  // turn the LED on when we're done
  digitalWrite(13, HIGH);
  
}
//do nothing
void loop(){
  delay(10);
}
