
void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
for (int i=0;i<12;i++){
  pinMode(i,OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(0,LOW);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}

