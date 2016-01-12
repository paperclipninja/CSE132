void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
}
    int key=0x02;
  int index=1;
  int value=5;
void loop() {
  // put your main code here, to run repeatedly:

  Serial.write(0x64);
  Serial.write(key);
  Serial.write(millis());
  Serial.write(index);
  Serial.write(value);
  Serial.write(0x0d);
}
