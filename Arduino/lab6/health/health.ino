/* health
      PROTOCOL CHANGES
      
    0x01 Not Used
    0x02 temperature (in degrees C)
    0x03 Steps
    0x04 Time
    0x05 Not used
    0x06 debugging string (Not used)
    0x07 index value (e.g., for indexing data values) 


 */
#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>


const int tempPin =A0;
int index=0;
float filterTemp[10];
int tempCont;



Adafruit_MMA8451 mma=Adafruit_MMA8451();
uint8_t currentOrientation;
int stepArray[3];
int steps=0;

ST7036 lcd = ST7036 ( 2, 16, 0x7c ); //COMMENT OUT TO USE THE SERIAL PORT

void setup() {
//  Serial.begin(9600);

  lcd.init();
  lcd.setContrast(0);
  //COMMENT OUT TO USE SERIAL

  if (!mma.begin()){
  lcd.print("ERROR");
  while(1);
}
mma.setRange(MMA8451_RANGE_8_G);
currentOrientation=mma.getOrientation();

  analogReference(INTERNAL);
 // int filterTemp[10];
//  Serial.println("IS THIS WORKING?");
// printArray(filterTemp);

}

void loop() {
//***GET THE TEMPERATURE
    float tempRead=(float)(analogRead(tempPin))*100*1.1/1023-50;
   shiftArray(filterTemp, 10);
   filterTemp[9]=tempRead;
   int tempSum=0;
   for(int y=0; y<10; y++){
    tempSum+=filterTemp[y];
   }
   float temperature=tempSum/10;
//***END OF GETTING TEMPERATURE

//****STEPS
  mma.read();
  sensors_event_t event;
  mma.getEvent(&event);
  if(!(abs(event.acceleration.z-1<.05)) ) {
    lcd.print("put lcd up");
  }
  else{
    delay(10);
    int sum=0;
  for(int a=0; a<20; a++)      { 
        sum+=event.acceleration.z;
      }
    int point=sum/20;
    for(int b=0; b<2; b++)  {
      stepArray[b]=stepArray[b+1];
   }
    stepArray[2]=point;
    if((stepArray[1])>(stepArray[0]+.1) && (stepArray[1])>(stepArray[2]+.1)) {
     steps++; 
    }
   }
//***END OF STEPS

//***SENDING THE INFO TO JAVA

//***NOTE: So I don't really know how serial.write will work if we're also using
//         the LCD. Maybe the ports overlap? Hopefully they don't. If they do I guess we can ask
//         the TA's about it?
//         Also, I don't think I have the final version of Lab4
//         Im just going to write the pseudo code for this <sorry>
/*int time =getTime()
 *   Serial.write( @ 0x07 time index 0x0d );
 *   Serial write (@ 0x02 time temperature 0x0d);
 *   Serial.write(@ 0x03 time steps 0x0d);
 * 
 * 
 */


//***END OF DATA SENDING


   
//***START OF PRINTING OUT THE FORMAT
  String tempString= "temp: ";
  tempString+=(String)temperature;
  String stepString="Steps: ";
  stepString+=(String) steps;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(tempString);
  lcd.print(stepString);
//***END OF PRINTING FORMAT
}



void shiftArray(float array[], int leng)
{
  for(int a=1; a<leng; a++)
  {
    array[a-1]=array[a];
   // printArray(array);
  }
  //eturn array;
}
void printArray(int arr[], int leng)
{
  Serial.println("PRINTING ARRAY");
  for(int x=0; x<leng; x++)
  {
    Serial.print(arr[x]);
    Serial.print(", ");
  }
  Serial.println("");
}
