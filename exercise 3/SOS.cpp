/*
 * SOS.cpp
 *
 * Author: Sanna
 * This is a test program for learning how to reuse code
 */ 

 #include <Arduino.h>

 void BlinkThreeDashes() {

 	for (int i = 0; i < 3; i++) {

	 	digitalWrite(13, HIGH);
	 	delay(1000);
	 	digitalWrite(13, LOW);
	 	delay(500);

	}
 }
 void BlinkThreeDots() {
	 
	 for (int i = 0; i < 3; i++) {

		 digitalWrite(13, HIGH);
		 delay(500);
		 digitalWrite(13, LOW);
		 delay(500);
		 
	 }
 }