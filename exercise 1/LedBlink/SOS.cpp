/*
 * SOS.cpp
 *
 * Created: 14.9.2016 13.02.42
 *  Author: Ilmeister
 */ 
 #include<Arduino.h>
 #include "SOS.h"
 void sos()
 {
 blinkFast();
 blinkFast();
 blinkFast();
 blinkLow();
 blinkLow();
 blinkLow();
 blinkFast();
 blinkFast();
 blinkFast();
 brake();
}

void blinkFast()
{
 	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
 	delay(250);              // wait for a second
 	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
 	delay(250);              // wait for a second
}

void blinkLow()
{
 	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
 	delay(1000);              // wait for a second
 	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
 	delay(1000);              // wait for a second
}

void brake()
{delay(2000);                 //Wait for the next sos round
}