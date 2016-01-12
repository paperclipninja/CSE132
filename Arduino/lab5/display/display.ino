/*
 * display
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include "font.h"
ST7036 lcd = ST7036 ( 2, 16, 0x7c );
int count=16;
int leftBut=12;
int rightBut=15;
int r0 = 0;
int r1 = 1;
int r2 = 2;
int r3 = 3;
int r4 = 4;
int r5 = 5;
int r6 = 6;
int c7 = 7;
int c8 = 8;
int c9 = 9;
int c10 = 10;
int c11 = 11;

int row[] = {r0, r1, r2, r3, r4, r5, r6};
int col[] = {c7, c8, c9, c10, c11};

int buttonState;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;

void setup ()
{
  //Serial.begin(9600);
  lcd.init ();
  lcd.setContrast(0);


  for (int i = 0; i < 7; i++)
  {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
  }

  //  pinMode(row[0],OUTPUT);
  for (int i = 0; i < 5; i++)
  {
    pinMode(col[i], OUTPUT);
  }
  //pins are from 0-11 for LED display
  // insert code here as needed

pinMode(rightBut, INPUT_PULLUP);
//pinMode(leftBut, INPUT_PULLUP);


}
//0-6 are the rows
//7-11 are columns
//when column is high, set row that you want on to be high

void loop ()
{
  lcd.print(count);
/*int reading=digitalRead(rightBut);
if(reading!=lastButtonState){
  lastDebounceTime=millis();
}
if((millis()-lastDebounceTime)>debounceDelay){
  if(reading!=buttonState){
    buttonState=reading;
    if(buttonState==LOW){
      
      count++;
      lcd.print("count");
      
      if(count>=sizeof(font_5x7))
      {
        count=0;
      }
    }
    else{
        lcd.print("BANAN");
      }
  }
}*/
if(digitalRead(rightBut)==LOW)
{
  count++;
  if(count>=96)
  {
    count==0;
  }
  delay(300);
}


  // digitalWrite(row[1], LOW);
  for (int a = 0; a < 5; a++)
  {
    //cycle through the columns
    //int num = (font_5x7[c][a]);

    digitalWrite(col[a], HIGH);
    for (int n = 0; n < 7; n++)
    {
      if (bitRead(font_5x7[count][a], n+1) == 1) {
        digitalWrite(row[6-n], LOW);
      }
      else {
        digitalWrite(row[6-n], HIGH);
      }



    }
    delay(1);
    digitalWrite(col[a], LOW);
//    delay(1);
  }


  lcd.clear ();
  // insert code here as needed





}
