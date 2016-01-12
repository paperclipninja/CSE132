/* temperature
 *
 * read temperature from TMP36 sensor
 *
 */
// #include<SPI.h>
 //File saveFile;
const int analogInPin = A0;  // Analog input pin
const int filterSize = 10; //change filter size so it modifies stuff
int x=0;
int waitTime=1000;
int loopEndTime=0;
int q=0;
int z=0;
    double avg=0;
  double array[filterSize];
  double averg[filterSize*5 -7];
void setup() {
  // put your setup code here, to run once:

  analogReference(INTERNAL);
  Serial.begin(9600);  
  Serial.println("MAYBE THIS WORKS");

  
}

void shiftArray(double arr[])
{
  for( x=1; x<filterSize; x++)
  {
    arr[x-1]=arr[x];
  }
  
}
void printArray(double arr[])
{
  for(int x=0; x<5; x++)
  {
    Serial.print(arr[x]);
    Serial.print(", ");
  }
}
void loop() {
 if(millis()>=loopEndTime){
    double num=0;
  for(int i=0; i<filterSize; i++){
  float base=(float)(analogRead(analogInPin));
  float temp=(float)(analogRead(analogInPin))*100*1.1/1023-50;
  
  Serial.print(temp);
  Serial.print(", ");
  
  //Serial.println("ARRAY");
  //printArray(array);
   array[q]=temp;
  if(q==filterSize){
    for(i=0; i<filterSize; i++)
    {
     
      avg+=array[i];
         // printArray(array);
    }
    avg=avg/filterSize;
    averg[z]=avg;
    Serial.print(" AVG "); 
    Serial.println(averg[z]);
    z++;
    shiftArray(array);
    q=filterSize;
     //Serial.print(avg);
    avg=0;
   }
   else{
    q++;
   }
  // Serial.print(avg);


 
  
  //Serial.print(", ");
  //Serial.print( "\t" );
  num+=temp;
  }
  loopEndTime+=waitTime;
  }
//Serial.println("AVG ARRAY");
//printArray(averg);

  
}
