
void serial_print() {
  Serial.print("Time since start: ");  // print a message
  Serial.print(hours);                 // print hours
  Serial.print(":");
  Serial.print(minutes);  // print minutes
  Serial.print(":");
  Serial.println(seconds);  // print seconds
}
