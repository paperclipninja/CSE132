void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void sendMess(int key, int val)
{
  Serial.write('@');
  Serial.write(key>>8);
  Serial.write(key);  
 int milli=millis();
  Serial.write(milli>>24);
  Serial.write(milli>>16);
  Serial.write(milli>>8);
  Serial.write(milli);
  Serial.write(val>>8);
  Serial.write(val);
 Serial.write(0x00);
}
void loop() {
  // put your main code here, to run repeatedly:
  //7<index 4<randval> 5
  int index=24;
  int ind = 7;
sendMess(ind, randVal);
}
  long milli=millis();
  int b = 0x04;
  //KEY TIME VALUE
sendMess(ind,index);
 delay(50);
ind=4;
int randVal=2000;
   //KEY TIME VALUE
