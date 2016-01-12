const int fredLED = 4;
const int fyeLED = 3;
const int fgrLED = 2;
const int sredLED = 11;
const int syeLED = 10;
const int sgrLED = 9;

const int dely = 1000;
const int walkL = 7;
const int dWalk = 8;
const int button = 12;
int walk = 0;
int pin = 0;
int d=1000;
int buttonState;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(walk, OUTPUT);
  pinMode(dWalk, OUTPUT);
  pinMode(fredLED, OUTPUT);
  pinMode(fyeLED, OUTPUT);
  pinMode(fgrLED, OUTPUT);
  pinMode(sredLED, OUTPUT);
  pinMode(syeLED, OUTPUT);
  pinMode(sgrLED, OUTPUT);
  digitalWrite(dWalk, HIGH);
  digitalWrite(walkL, LOW);
}

void loop() {
 /* int reading=digitalRead(button);
  if (reading!=lastButtonState){
    lastDebounceTime=millis();
  }
  if((millis()-lastDebounceTime)>debounceDelay){
    if(reading!=buttonState){
      buttonState=reading;
      if(buttonState==HIGH){
            Serial.println("BUTTON PRESSED");
    walk = 1;
      }
    }
  }*/

  if(  millis()>d){
    if(digitalRead(button)==0)
    {
                  Serial.println("BUTTON PRESSED");
    walk = 1;
    }
  switch (pin) {
    case 0:
      Serial.println("0");
      digitalWrite(dWalk, HIGH);
      digitalWrite(walkL, LOW);
      digitalWrite(fredLED, HIGH);
      digitalWrite(fyeLED, LOW);
      digitalWrite(fgrLED, LOW);

      digitalWrite(sredLED, LOW);
      digitalWrite(syeLED, LOW);
      digitalWrite(sgrLED, HIGH);
      pin++;
      break;
    case 1:
      Serial.println("1");
      digitalWrite(dWalk, HIGH);
      digitalWrite(walkL, LOW);
      digitalWrite(fredLED, HIGH);
      digitalWrite(fyeLED, LOW);
      digitalWrite(fgrLED, LOW);

      digitalWrite(sredLED, LOW);
      digitalWrite(syeLED, HIGH);
      digitalWrite(sgrLED, LOW);

      pin++;
      break;
    case 2:
      Serial.println("2");
      digitalWrite(dWalk, HIGH);
      digitalWrite(walkL, LOW);
      digitalWrite(fredLED, HIGH);
      digitalWrite(fyeLED, LOW);
      digitalWrite(fgrLED, LOW);

      digitalWrite(sredLED, HIGH);
      digitalWrite(syeLED, LOW);
      digitalWrite(sgrLED, LOW);

      pin++;
      break;
    case 3:
      Serial.println("3");
      digitalWrite(dWalk, HIGH);
      digitalWrite(walkL, LOW);
      digitalWrite(fredLED, LOW);
      digitalWrite(fyeLED, LOW);
      digitalWrite(fgrLED, HIGH);

      digitalWrite(sredLED, HIGH);
      digitalWrite(syeLED, LOW);
      digitalWrite(sgrLED, LOW);
      pin++;
      break;
    case 4:
      Serial.println("4");
      digitalWrite(dWalk, HIGH);
      digitalWrite(walkL, LOW);
      digitalWrite(fredLED, LOW);
      digitalWrite(fyeLED, HIGH);
      digitalWrite(fgrLED, LOW);

      digitalWrite(sredLED, HIGH);
      digitalWrite(syeLED, LOW);
      digitalWrite(sgrLED, LOW);
      pin++;
      break;
    case 5:
      Serial.println("5");
      digitalWrite(dWalk, HIGH);
      digitalWrite(walkL, LOW);
      digitalWrite(fredLED, HIGH);
      digitalWrite(fyeLED, LOW);
      digitalWrite(fgrLED, LOW);

      digitalWrite(sredLED, HIGH);
      digitalWrite(syeLED, LOW);
      digitalWrite(sgrLED, LOW);
      if (walk == 1) {
        pin++;
        Serial.println("GOING TO CASE 6");
        walk = 0;
      }
      else {
        pin = 0;
      }
      break;
    case 6:
      Serial.println("6");
      digitalWrite(dWalk, LOW);
      digitalWrite(walkL, HIGH);
      digitalWrite(fredLED, HIGH);
      digitalWrite(fyeLED, LOW);
      digitalWrite(fgrLED, LOW);

      digitalWrite(sredLED, HIGH);
      digitalWrite(syeLED, LOW);
      digitalWrite(sgrLED, LOW);
      pin = 0;
      break;
  }
  
    d+=dely;
 }
  // put your main code here, to run repeatedly:

}
