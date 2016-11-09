
#include <Arduino.h>

#include "Morse.h"


void buttonPressed();

char buttonState = 0;

void setup() {
	pinMode(A1, INPUT);
	pinMode(12, OUTPUT);
	showText("SOS");
}

void loop() {
	buttonState = digitalRead(12);
	if (buttonState) {
		showText("I LOVE EMBENDDED");
		showText("SOS");
		buttonState = 0;
	}
}