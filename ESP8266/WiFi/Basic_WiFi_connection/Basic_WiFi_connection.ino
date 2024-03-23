#include <ESP8266WiFi.h>

const char* ssid="mulberry";
const char* password = "robinho0d";

int ledPin = LED_BUILTIN;

void setup() {
  
pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW); //turn on LED

  Serial.begin(74880); //Higher speeds may be used as long as th serial port speed matches, but 74880 seems to
                       //be the default speed after pressing reset button & avoids boot process printing junk
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  digitalWrite( ledPin , HIGH); //turn off LED when connected
  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

}

void loop() {
  // put your main code here, to run repeatedly:

}
