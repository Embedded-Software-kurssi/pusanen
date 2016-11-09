
#include <Arduino.h>

const int RED_LED = 12;
const int GREEN_LED = 11;
const int YELLOW_LED = 13;
const int BUTTON_PIN = A1; 

int buttonPressed = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
}

void loop() {
	buttonPressed = digitalRead(BUTTON_PIN);
	if (buttonPressed) {
		digitalWrite(YELLOW_LED, HIGH);
		delay(2000);
		digitalWrite(GREEN_LED, HIGH);
		digitalWrite(RED_LED, LOW);
		digitalWrite(YELLOW_LED, LOW);
		delay(2000);
		digitalWrite(YELLOW_LED, HIGH);
		digitalWrite(GREEN_LED, LOW);
		digitalWrite(RED_LED, LOW);
		delay(2000);
		digitalWrite(YELLOW_LED, LOW);
		buttonPressed = 0;
	}
	digitalWrite(RED_LED, HIGH);
}
