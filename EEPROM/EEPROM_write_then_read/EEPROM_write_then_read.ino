// Arduino internal EEPROM demonstration
// This sketch will create random numbers between 0 and 255, store them in the EEPROM, then retrieve and display them on the serial monitor.
// The variable EEsize is the upper limit of your EEPROM size, so (for example) this would be 1024 for an Arduino Uno, or 4096 for a Mega.
 
#include <EEPROM.h>
int zz; //stores value to be written to EEPROM
int yy; //stores value to be read from EEPROM
int EEsize = 1024; // size in bytes of your board's EEPROM
 
void setup()
{
  Serial.begin(9600); //sets speed of serial connection to 9600 baud
  randomSeed(analogRead(0)); //gets a random value to seed the random() function by reading the value of analog pin 0
}
void loop()
{
  Serial.println("Writing random numbers...");
  for (int i = 0; i < EEsize; i++)
  {
    zz=random(255); //set variable zz to a random value
    EEPROM.write(i, zz); //write value of zz variable to EEPROM byte stored in variable i
  }
  Serial.println();
  for (int a=0; a<EEsize; a++)
  {
    yy = EEPROM.read(a); //set yy to the value of the byte pointed to by variable a
    Serial.print("EEPROM byte: ");
    Serial.print(a);
    Serial.print(" contains ");
    Serial.println(yy);
    delay(250); //250 mS before writing next line, not the delay between loops of the whole sketch
  }
}