#include <SoftwareSerial.h>
#include <IRremote.h>
 
SoftwareSerial BTSerial(2, 3); //Connect HC-06. Use your (TX, RX) settings
int led = 13;

 
void setup()  
{
  Serial.begin(9600);
  Serial.println("Hello!");

  pinMode(led, OUTPUT);
 
  BTSerial.begin(9600);  // set the data rate for the BT port

  // 리모컨 사용
}
 
void loop()
{
  
  // BT –> Data –> Serial
  if (BTSerial.available()) {

    char v = BTSerial.read();
    //Serial.write(v);
    Serial.println()
    digitalWrite(led, HIGH);

    if(v == 'a'){
      digitalWrite(led, HIGH);
    }
    else if(v == 'b'){
      digitalWrite(led, LOW);
    }
  
  }
  // Serial –> Data –> BT
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }

 


  delay(1000);
  
}
