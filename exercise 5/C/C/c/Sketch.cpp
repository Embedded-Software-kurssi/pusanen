/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "Morse.h"

const char ledYellow=11; 
const char ledRed=12;
const char ledGreen=13;
const char nappi=A0;

char buttonWasPressed = 0;

void setup() {
pinMode(ledYellow, OUTPUT);
pinMode(ledRed, OUTPUT);
pinMode(ledGreen, OUTPUT);
pinMode(nappi, INPUT);
 
 digitalWrite(ledGreen, HIGH);
}

char buttonPressed = 0;
char state = 0;
char sosUsed = 0;

void loop() {
	buttonPressed = digitalRead(nappi);
	if (!digitalRead(nappi)) {
		//showText("SO");
		showText("SOS");
	}
	while(!digitalRead(nappi));
		digitalWrite(ledYellow, LOW);
		digitalWrite(ledRed, LOW);
		digitalWrite(ledGreen, HIGH);
	while(digitalRead(nappi));
	while(!digitalRead(nappi));
		digitalWrite(ledYellow, HIGH);
		digitalWrite(ledRed, LOW);
		digitalWrite(ledGreen, LOW);
	while(digitalRead(nappi));		
	while(!digitalRead(nappi));	
		digitalWrite(ledYellow, LOW);
		digitalWrite(ledRed, HIGH);
		digitalWrite(ledGreen, LOW);
	while(digitalRead(nappi));
	while(!digitalRead(nappi));
		digitalWrite(ledYellow, LOW);
		digitalWrite(ledRed, LOW);
		digitalWrite(ledGreen, LOW);
	while(digitalRead(nappi));
}
