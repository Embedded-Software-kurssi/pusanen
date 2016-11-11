/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

const char ledYellow=11;
const char ledRed=13;
const char ledGreen=12;

const char nappi=A0;

int fibonacci(int x);

void setup() {
	pinMode(ledYellow, OUTPUT);
	pinMode(ledRed, OUTPUT);
	pinMode(ledGreen, OUTPUT);
	pinMode(nappi, INPUT);
	digitalWrite(ledRed, HIGH);
	digitalWrite(ledGreen, LOW);
	digitalWrite(ledYellow, LOW);
}

void loop() {
	while (!digitalRead(nappi));
	while (digitalRead(nappi));
	digitalWrite(ledGreen, HIGH);
	digitalWrite(ledRed, LOW);
	volatile int b = fibonacci(11);
	while (!digitalRead(nappi));
	while (digitalRead(nappi));
}

int fibonacci(int x) {
	int a = 0;
	int b = 0;
	for (int i = 0; i < x; i++) {
		int temp = b;
		b = a + temp;
		a = temp;
		if (b == 0) b = 1;
	}
	return b;
}
