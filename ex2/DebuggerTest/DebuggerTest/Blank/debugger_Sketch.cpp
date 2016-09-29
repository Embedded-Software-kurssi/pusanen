/* Main_sketch.cpp
Author: Sanna
This is a test program for learning how to use Atmel ICE debugger
*/

#include <Arduino.h>
#include "DebuggerTest.h"

int countingDots = 0;
int countingDashes = 0;
void BlinkThreeDots();


void setup() {
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);
}


void loop() {

	BlinkThreeDots();
	countingDashes = BlinkThreeDashes();
	BlinkThreeDots();
	delay(1000);

}

void BlinkThreeDots() {
	
	for (int i = 0; i < 3; i++) {

		digitalWrite(13, HIGH);
		delay(500);
		digitalWrite(13, LOW);
		delay(500);
		
		countingDots = countingDots + 1;

	}
}