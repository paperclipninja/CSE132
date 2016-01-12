#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd =ST7036 ( 2, 16, 0x7c );
int cont=0;
const int buttPin=12;
int ledState=HIGH;
int buttonState;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;

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
  int reading=digitalRead(buttPin);
  if(reading!=lastButtonState){
    lastDebounceTime=millis();
  }
  if((millis()-lastDebounceTime)>debounceDelay){
    if(reading!=buttonState){
      buttonState=reading;
      if(buttonState==HIGH){
  lcd.clear ();
        cont++;
        lcd.print(cont);
      }
    }
  }

  lastButtonState=reading;
  //count number of times button is pressed
  //print the thing to the 
  // insert code here as needed





}
