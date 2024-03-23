
int ledPin = 13;
int on_off;  // 1 = On. 0 = Off.

// SETUP *************************************************************************
void setup()
{
  Serial.begin(9600);      // start serial communication at 9600bps
  pinMode(ledPin, OUTPUT);
  Serial.flush();
} // End Setup

// LOOP *************************************************************************
void loop()
{
  Serial.println("Enter LED On=1/Off=0 ...");  //Select On or Off
  while (Serial.available()==0) { // Wait for User to Input Data
}
  on_off = Serial.parseInt();
  Serial.println();
    if (on_off == 1) digitalWrite(ledPin, HIGH); //Select Uno LED On
    else digitalWrite(ledPin, LOW);              //Select Uno LED Off
}  // End Loop.

