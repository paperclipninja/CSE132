/**************************************************************************
 * steps
 **************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();
ST7036 lcd = ST7036 ( 2, 16, 0x7c );
uint8_t currentOrientation;
int array[3];
int steps=0;
void setup(void) {
  Serial.begin(115200);
  
  Serial.println("Adafruit MMA8451 test!");
 // array={0,0,0}

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  // You might like this, you might want to change it
  mma.setRange(MMA8451_RANGE_8_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  // Feel free to use the LCD as you choose
  lcd.init ();
  lcd.setContrast(0);  
  currentOrientation=mma.getOrientation();
}

void loop() {
  //Serial.println("MAYBE WORKING?");
  lcd.clear();
  mma.read();
   sensors_event_t event; 
   mma.getEvent(&event);
      //  Serial.println(event.acceleration.z);
   if(!(abs(event.acceleration.z-1)<.05))
  {
  lcd.print("put lcd up");
    //Serial.println(event.acceleration.z);
  }
  else{
    lcd.clear();
    delay(10);
    int sum=0;
    for(int a=0; a<20; a++)
    {
      
      sum+=event.acceleration.z;
    }
  int point=sum/20;

  for(int b=0; b<2; b++)
  {
    array[b]=array[b+1];
  }
  array[2]=point;

  if((array[1])>(array[0]+.5) && (array[1])>(array[2]+.5)) 
  {
   steps++; 
  Serial.print("Steps=");
  Serial.println(steps);
  }
  
  }
  //lcd.print(steps);

//  delay(90);
  // Put your code here

  
}
