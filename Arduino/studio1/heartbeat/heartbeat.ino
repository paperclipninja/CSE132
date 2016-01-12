/* heartbeat
 *
 * 1 Hz heartbeat signal
 *
 */
int sec;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sec=0;
}

void loop() {
  delay(1000);
  sec++;
 Serial.println(sec);
  // put your main code here, to run repeatedly:

}
