/* dm
 *
 * data manipulation in assembly language
 *
 * the assembly language code goes in the file dm.S, in the libraries directory
 */

#include <dm.h>

extern "C" {
 void printRegs(void); //function prototype
}

int m;
int n;
int p;

void setup() {
  Serial.begin(9600);

  //invoke the assembly language code
  dm();

  //you can put Serial.print() or Serial.println() calls here:


}

void loop() {
}
