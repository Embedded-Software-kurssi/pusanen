/*
This program goes through Fibonacci numbers and blinks a LED for one second if the number is a prime number
Author: Sanna
*/


#include <Arduino.h>
#include "FixMe.h"

int x = 0;
int Second_Number = 1;
int NEXTNumber;
int foo = 0;


void setup() {
 
	pinMode(13, OUTPUT);

}

void loop() {
  
  // if foo equals to zero
  if (foo == 0) {
   
	NEXTNumber = x + Second_Number;

	} 
	else 
	{
	NEXTNumber = x + Second_Number;
	x = Second_Number; Second_Number = NEXTNumber;
  
	}
  
	BlinkIfPrime(NEXTNumber);

	foo = foo + 1;
}
