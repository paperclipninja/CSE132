  int blue=5;
  int red=6;
  int green=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  int 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int a=0; a<2000; a++)
  {
      digitalWrite(red,HIGH);
        digitalWrite(blue, LOW);
        
  delay(1);
  digitalWrite(blue, HIGH);
    digitalWrite(red,LOW);
  delay(1);
  }  
  
  digitalWrite(blue, HIGH);
  delay(2000);
  
  for(int a=0; a<2000; a++)
  {
      digitalWrite(blue,HIGH);
        digitalWrite(green, LOW);
        
  delay(1);
  digitalWrite(green, HIGH);
    digitalWrite(blue,LOW);
  delay(1);
  }
  digitalWrite(green, HIGH);
  delay(2000);
  
    for(int a=0; a<2000; a++)
  {
      digitalWrite(red,HIGH);
        digitalWrite(green, LOW);
        
  delay(1);
  digitalWrite(green, HIGH);
    digitalWrite(red,LOW);
  delay(1);
  }
  digitalWrite(green,LOW);
    digitalWrite(red, HIGH);
  delay(2000);
  
}
