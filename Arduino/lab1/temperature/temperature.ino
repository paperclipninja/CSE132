/* temperature
 *
 * read temperature from TMP36 sensor
 *
 */
const int analogInPin = A0;  // Analog input pin
const int filterSize = 10; //change filter size so it modifies stuff
int x=0;
void setup() {
  // put your setup code here, to run once:
  //int[] array= new int[filterSize];
  analogReference(INTERNAL);
  Serial.begin(9600);
    //0-1023 is RANGE of inputs
  //top range voltage is 1.1v
  //at 0v, temp= -50
  //100 is increase in temp for increase voltage
}

void loop() {
  while(x<12){
  double num=0;
  for(int i=0; i<filterSize; i++){
  //float base=(float)(analogRead(analogInPin));
  float temps=(float)(analogRead(analogInPin))*100*1.1/1023-50;
 int temp= (int) temps;
  Serial.print(temp);
  Serial.print( "\t" );
  num+=temp;
  delay(250);
  }
  float avg=(float)(num/filterSize);

   x++;

  Serial.println(avg);
 // Serial.println(temp);
  // put your main code here, to run repeatedly:
  }
}
