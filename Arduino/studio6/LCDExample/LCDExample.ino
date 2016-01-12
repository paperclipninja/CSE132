/***************************************************************************************************************/
// Created from example code from Arduino Playground ( http://playground.arduino.cc/Code/LCD )
//    LCD_ST7036_v1.2.0.zip ( https://bitbucket.org/fmalpartida/st7036-display-driver/wiki/Home )
// Extract .zip file to the arduinosketchfolder/libraries/ folder. You may need to create the libraries subfolder
// if its your first library. Restart the IDE. You can set the arduinosketchfolder under File -> Preferences
// Changed ST7036 object instantiation to (2,16,0x7c) for our display (2x16 with I2C address = 0x7c)
/***************************************************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );
int incomingByte=0;
void setup ()
{
  Serial.begin(9600);
  lcd.init ();
  lcd.setContrast(0);
 // lcd.clear

  }

int i = 0 ;
int cont=0;
char array [16];
void loop ()
{
  if(Serial.available()>0){
if( cont<2){
    Serial.readBytes(array, 16);
    lcd.setContrast(i % 32);
    lcd.print (array);
    cont+=1;
    lcd.setCursor (cont,0);
    memset(array,0,16);
  
  }
  else{
    lcd.clear ();
    cont=0;
     Serial.readBytes(array, 16);
    lcd.setContrast(i % 32);
    lcd.print (array);
    cont+=1;
    lcd.setCursor (cont,0);
      memset(array,0,16);

  }
  
  }


}



