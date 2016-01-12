/*
 * mirror
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd =ST7036 ( 2, 16, 0x7c );
int cont=0;
int buttPin=12;
int currentState=1;
void setup ()
{
  Serial.begin(9600);
  lcd.init ();
  lcd.setContrast(0);
  pinMode(buttPin, INPUT_PULLUP);
  // insert code here as needed
}

void loop ()
{
  delay(250);

  int a=digitalRead(buttPin);
  if(a==0 and a!=currentState){
      lcd.clear ();
    cont++;
    lcd.print(cont);
    
  }
  currentState=a;
  //count number of times button is pressed
  //print the thing to the 
  // insert code here as needed



}
