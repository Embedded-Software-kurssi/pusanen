
#include <Arduino.h>
#include "Morse.h"
#include <math.h>

int BlinkPowers(int power);
void TotalNumberOfBlinks(int x);

const char ledPin = 13;

void setup() {
	pinMode(ledPin, OUTPUT);
	int totalNumberOfBlinks = 0;
	totalNumberOfBlinks += BlinkPowers(4);
	totalNumberOfBlinks += showText("SOS");
	TotalNumberOfBlinks(totalNumberOfBlinks);
}

void loop() {

}

void TotalNumberOfBlinks(int x) {
	for (int i = 0; i < x; i++) {	
		digitalWrite(ledPin, HIGH);
		delay(100);
		digitalWrite(ledPin, LOW);
		delay(100);
	}
}

int BlinkPowers(int power) {
	volatile int b = power;
	volatile float x = pow(2, power);
	volatile int a = (1<<power);
	for (int i = 0; i < x; i++) {	
		digitalWrite(ledPin, HIGH);
		delay(100);
		digitalWrite(ledPin, LOW);
		delay(100);
	}
	return x;
}