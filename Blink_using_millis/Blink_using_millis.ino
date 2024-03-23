/*  This example uses the millis() function to read the mS count each pass through main loop and check if more than
 *  a predefined interval has elapsed, if it has the state of a LED is inverted
 *  (note not precisely accurate as each count is 1.024mS which is corrected by software when drift approaches 1mS)
*/
#define INTERVAL 350  // {mS]

byte led; //onboard led, status 0=off, 1=on

unsigned long time_for_action;

void setup() {
  pinMode(13, OUTPUT);   //set pin 13 to be an output
}

void loop() {
  // put your main code here, to run repeatedly:

    if (millis() > time_for_action) {
    time_for_action = millis() + (unsigned long)INTERVAL;
    led = !led; //invert the value of led_1
    }

  digitalWrite(13,led); //write the value of led_1 to pin 13

}
