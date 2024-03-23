
void display_time_elapsed_on_LCD() {
  lcd.setCursor(0, 1);  //Column starting at 0, Row 0 for top and 1 for bottom

  if (hours < 10) {  // if hours is less than 10, print a leading zero
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");

  if (minutes < 10) {  // if minutes is less than 10, print a leading zero
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");

  if (seconds < 10) {  // if seconds is less than 10, print a leading zero
    lcd.print("0");
  }
  lcd.print(seconds);
}