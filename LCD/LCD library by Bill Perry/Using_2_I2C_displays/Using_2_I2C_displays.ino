/*   16 character 2 line I2C Display
 *   Uses Bill Perry's HD44780 Library, which can be installed from the Arduino Library Manager
 *   See Bills documentation: https://github.com/duinoWitchery/hd44780
 *   See the "API Summary" section.  Use "lcd" in front like lcdbegin(cols, rows)
 *   
 *   LCD Display Blue or Yellow: I2C/TWI "Backpack" Interface
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
#include <hd44780.h>                        // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h>  // i2c expander i/o class header

/*-----( Declare Constants )-----*/
// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

/*-----( Declare objects )-----*/
//hd44780_I2Cexp lcd;  // declare lcd object: auto locate & auto config expander chip
 hd44780_I2Cexp lcd1(0x26); //declare lcd1 object at I2C address 0x26
 hd44780_I2Cexp lcd2(0x27); //declare lcd1 object at I2C address 0x27
 
/*-----( Declare Variables )-----*/
int status;

void setup() /*----( SETUP: RUNS ONCE )----*/
{
  pinMode(13, OUTPUT);   //set pin 13 to be an output
  
  status = lcd1.begin(LCD_COLS, LCD_ROWS);
  if (status)  // non zero status means it was unsuccesful
  {
    // hd44780 has a fatalError() routine that blinks an led if possible
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status);  // does not return
  }

  status = lcd2.begin(LCD_COLS, LCD_ROWS);
  if (status)  // non zero status means it was unsuccesful
  {
    // hd44780 has a fatalError() routine that blinks an led if possible
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status);  // does not return
  }

  // Print a message to the LCD.
  lcd1.clear();
  delay(1500);
  lcd1.setCursor(0, 0);
  lcd1.print("LCD 1 at 0x26");
  delay(1500);
  lcd1.setCursor(0, 1);
  lcd1.print("Display");

  lcd2.clear();
  delay(1500);
  lcd2.setCursor(0, 0);
  lcd2.print("LCD 2 at 0x27");
  delay(1500);
  lcd2.setCursor(0, 1);
  lcd2.print("Display");

} /*--(end setup )---*/

void loop() /*----( LOOP: RUNS CONSTANTLY )----*/
{

} /* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/

/* ( THE END ) */
