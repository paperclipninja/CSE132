/*
 * stoplight
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );
const int fredLED=4;
const int fyeLED=3;
const int fgrLED=2;
const int sredLED=11;
const int syeLED=10;
const int sgrLED=9;

const int dely=1000;
int pin=0;
void setup ()
{
  lcd.init ();
  lcd.setContrast(0);
   Serial.begin(9600);
  pinMode(fredLED,OUTPUT);
  pinMode(fyeLED,OUTPUT);
  pinMode(fgrLED,OUTPUT);
    pinMode(sredLED,OUTPUT);
  pinMode(syeLED,OUTPUT);
  pinMode(sgrLED,OUTPUT);
  digitalWrite(fgrLED,LOW);
}

void loop() {
  
  lcd.clear();
  switch(pin){
    case 0: 
      digitalWrite(fredLED,HIGH);
      digitalWrite(fyeLED,LOW);
      digitalWrite(fgrLED,LOW);
      
      digitalWrite(sredLED,LOW);
      digitalWrite(syeLED,LOW);
      digitalWrite(sgrLED,HIGH);
      delay(dely);
      pin++;
      break;
    case 1:
    Serial.println("1");
      digitalWrite(fredLED,HIGH);
      digitalWrite(fyeLED,LOW);
      digitalWrite(fgrLED,LOW);
      
      digitalWrite(sredLED,LOW);
      digitalWrite(syeLED,HIGH);
      digitalWrite(sgrLED,LOW);
      delay(dely);
      pin++;
      break;
    case 2:
     Serial.println("2");
      digitalWrite(fredLED,HIGH);
      digitalWrite(fyeLED,LOW);
      digitalWrite(fgrLED,LOW);
      
      digitalWrite(sredLED,HIGH);
      digitalWrite(syeLED,LOW);
      digitalWrite(sgrLED,LOW);
      delay(dely);
      pin++;
      break;
    case 3:
    Serial.println("3");
      digitalWrite(fredLED,LOW);
      digitalWrite(fyeLED,LOW);
      digitalWrite(fgrLED,HIGH);
      
      digitalWrite(sredLED,HIGH);
      digitalWrite(syeLED,LOW);
      digitalWrite(sgrLED,LOW);
      delay(dely);
      pin++;
      break;
   case 4:
    Serial.println("4");
      digitalWrite(fredLED,LOW);
      digitalWrite(fyeLED,HIGH);
      digitalWrite(fgrLED,LOW);
      
      digitalWrite(sredLED,HIGH);
      digitalWrite(syeLED,LOW);
      digitalWrite(sgrLED,LOW);
      delay(dely);
      pin++;
      break;
 case 5:
 Serial.println("5");
      digitalWrite(fredLED,HIGH);
      digitalWrite(fyeLED,LOW);
      digitalWrite(fgrLED,LOW);
      
      digitalWrite(sredLED,HIGH);
      digitalWrite(syeLED,LOW);
      digitalWrite(sgrLED,LOW);
      delay(dely);
      pin=0;
      break;
  }
  
  // put your main code here, to run repeatedly:
  /*digitalWrite(fredLED,HIGH);
  digitalWrite(fyeLED,HIGH);
  digitalWrite(fgrLED,HIGH);
  digitalWrite(sredLED,HIGH);
  digitalWrite(syeLED,LOW);
  digitalWrite(sgrLED,HIGH);
*/
}
