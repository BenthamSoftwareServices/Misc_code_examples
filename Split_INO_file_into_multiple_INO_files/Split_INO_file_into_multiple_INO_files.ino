/*
An example of using the Hangul LCD library
Uses copy of Hangul LCD library in sketch folder, which does not auto-update, use double quotes not angle brackets
The library must be removed from the installed folder at E:\Users\Steven\Documents\GitHub\Arduino_2\libraries or else the compiler may use either.
Uses tabs to split large amounts of code into smaller modules, see: https://www.youtube.com/watch?v=HtYlQXt14zU
*/

#include "LiquidCrystal_I2C_Hangul.h"
#include <Wire.h>

const uint8_t LCD_ADDRESS = 0x27;
const uint8_t LCD_COLUMNS = 16;
const uint8_t LCD_ROWS = 2;

unsigned long seconds;
unsigned long minutes;
unsigned long hours;
unsigned long currentMillis;

//prototypes for functions to avoid rare compilation errors, see https://arduino.github.io/arduino-cli/0.20/sketch-build-process/
void calculate_elapsed_time();
void serial_print();
void display_time_elapsed_on_LCD();

LiquidCrystal_I2C_Hangul lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  delay(1000);
  lcd.setCursor(0, 0);  //Column starting at 0, Row 0 for top and 1 for bottom
  lcd.print("Time since start");
  delay(1000);
  Serial.println("Setup complete");
}

void loop() {
  calculate_elapsed_time(); //code in tab with same name
  serial_print(); //code in tab with same name
  delay(1000);
  display_time_elapsed_on_LCD(); //code in tab with same name
}
