unsigned int input[3]={65535, 0, 9999};
void setup() {
  // put your setup code here, to run once:
   for(int i=0; i < 3; i++){
       Serial.print(input[i]!=0);
       Serial.print(" , ");
       Serial.print((~input[i]) != 0);
       Serial.print(" , ");
       Serial.print((0b1111111100000000^input[i])!=0);
      Serial.print(" , ");
       Serial.print((0b0000000011111111^input[i]) !=0);
       Serial.print(" , ");
       Serial.println((input[i]>>15) ==1);
       }
   }


void loop() {
  // put your main code here, to run repeatedly:
   for(int i=0; i < 3; i++){
       Serial.print(input[i]!=0);
       Serial.print(" , ");
       Serial.print((~input[i]) != 0);
       Serial.print(" , ");
       Serial.print((0b1111111100000000^input[i])!=0);
      Serial.print(" , ");
       Serial.print((0b0000000011111111^input[i]) !=0);
       Serial.print(" , ");
       Serial.println((input[i]>>15) ==1);
       }
}
