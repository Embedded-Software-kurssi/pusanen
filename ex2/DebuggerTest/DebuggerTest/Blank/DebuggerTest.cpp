/*
 * DebuggerTest.cpp
 *
 * Author: Sanna
 * This is a test program for learning how to use Atmel ICE debugger
 */ 

 #include <Arduino.h>

 int dashCounter = 0;

 int BlinkThreeDashes() {

 	for (int i = 0; i < 3; i++) {

	 	digitalWrite(13, HIGH);
	 	delay(1000);
	 	digitalWrite(13, LOW);
	 	delay(500);

		dashCounter = dashCounter + 1;

 	}
	
	return dashCounter;
 }