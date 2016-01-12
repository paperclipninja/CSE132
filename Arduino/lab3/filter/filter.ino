/* filter
 *
 * FIR filter in assembly language
 *
 * the assembly language code goes in the file filter.S, in the libraries directory
 */

#include <filter.h>
#include "fir1.h"
#include "input1.h"

int output[NUM_SAMPS];

extern "C" {              //function prototypes
 void printRegs(void);
 int q15mpy(int, int);
}


void setup() {
  Serial.begin(9600);

  //invoke the assembly language code
  filter();

  //you can put Serial.print() or Serial.println() calls here:


}

void loop() {
}

/*
 * q15mpy - multiply routine for Q15 data format
 */

extern "C" {
 int q15mpy(int x, int y) {
  return (((long int) x * (long int) y) >> 15);
 }
}
