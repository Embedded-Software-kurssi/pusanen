#include <Arduino.h>
#include "SegmentScreen.h"
#include "Thermistor.h"

char cathodePins[8] = {
	4, 5, 6, 7, 8, 9, 10
};

SegmentScreen *screens[] = {
	new SegmentScreen(cathodePins, 2),
	new SegmentScreen(cathodePins, 3)
};

SegmentLayout layout(screens, 2);

Thermistor thermistor(A0);

void setup() {
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);

	digitalWrite(2, HIGH);
	digitalWrite(3, HIGH);

	digitalWrite(4, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(8, HIGH);
	digitalWrite(9, HIGH);
	digitalWrite(10, HIGH);	
}

void loop() {
	String str = String(thermistor.getCelciusC());
	layout.setText(str);
 	layout.refresh();
}