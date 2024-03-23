/* YourDuino.com Example Software Sketch
 *  _2_Line_I2C_Display_TestV2.ino
 *   16 character 2 line I2C Display
 *   Uses Bill Perry's HD44780 Library, which can be installed from the Arduino Library Manager
 *   See Bills documentation: https://github.com/duinoWitchery/hd44780
 *   See the "API Summary" section.  Use "lcd" in front like lcdbegin(cols, rows)
 *   
 *   LCD Display Blue or Yellow: I2C/TWI "Backpack" Interface
 questions??  terry@yourduino.com 
  
 */
 // ----------------------------------------------------------------------------
/*LiquidCrystal compability:
Since this hd44780 library is LiquidCrystal API compatible, most existing LiquidCrystal
sketches should work with hd44780 hd44780_I2Cexp i/o class once the
includes are changed to use hd44780 and the lcd object constructor is
changed to use the hd44780_I2Cexp i/o class.
*/

/*-----( Import needed libraries )-----*/
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header


/*-----( Declare Constants )-----*/
// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

/*-----( Declare objects )-----*/
hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip  
/*-----( Declare Variables )-----*/
int status;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
    // hd44780 has a fatalError() routine that blinks an led if possible
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }  
  Serial.begin(9600);

  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("2-Line DISPLAY");
  delay(1500);
  lcd.setCursor(0, 1);
  lcd.print("YourDuino: HI!");  
  
  delay(5000);
  lcd.setCursor(0, 0);
  lcd.print("Now YOU Type    ");  
  lcd.setCursor(0, 1);
  lcd.print("On SerialMonitor");    
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
  }

}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/


/* ( THE END ) */
