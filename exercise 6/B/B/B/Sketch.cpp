#include <Arduino.h>

const char ledYellow = 11;
const char ledRed = 13;
const char ledGreen = 12;
const char nappi=A0;

void BlinkRed();
void BlinkYellow();
void BlinkGreen();

void setup() {
	pinMode(ledGreen, OUTPUT);
	pinMode(ledRed, OUTPUT);
	pinMode(ledYellow, OUTPUT);
	pinMode(nappi, INPUT);

	if (digitalRead(nappi)) {
		BlinkRed();
	} else {
		BlinkYellow();
	}

	for (int i = 0; i < 5; i++)
	{
		BlinkGreen();
	}
}

void loop() {

}

void BlinkRed() {
	digitalWrite(ledRed, HIGH);
	delay(1000);
	digitalWrite(ledRed, LOW);
	delay(300);
}

void BlinkYellow() {
	digitalWrite(ledYellow, HIGH);
	delay(1000);
	digitalWrite(ledYellow, LOW);
	delay(300);
}

void BlinkGreen() {
	digitalWrite(ledGreen, HIGH);
	delay(300);
	digitalWrite(ledGreen, LOW);
	delay(300);
}