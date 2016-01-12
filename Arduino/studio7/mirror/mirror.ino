/*
 * mirror
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );
const int buttPin=12;
void setup ()
{
  Serial.begin(9600);
  lcd.init ();
  lcd.setContrast(0);
  // insert code here as needed
  pinMode(buttPin, INPUT_PULLUP);



}

void loop ()
{
  lcd.clear ();
  delay(50);
  if(digitalRead(buttPin)==0){
    Serial.println(0);
  }
  
  // insert code here as needed





}
