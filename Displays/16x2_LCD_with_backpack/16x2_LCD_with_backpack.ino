
#include <LiquidCrystal_I2C_Hangul.h>
#include <Wire.h>

LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2);  //LCD at address 0x27, 16 characters and 2 rows

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.backlight();
  delay(2000);  
  lcd.print("Hello Steve!");
  delay(2000);
  lcd.clear();
  lcd.print("Steven Bennett");  
  delay(2000);
  lcd.clear();
  lcd.noBacklight();
  delay(2000);

}
