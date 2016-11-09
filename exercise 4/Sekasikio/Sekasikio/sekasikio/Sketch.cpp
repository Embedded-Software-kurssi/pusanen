#include <Arduino.h>
#include "SegmentScreen.h"
#include "Thermistor.h"
#include "Morse.h"

char cathodePins[7] = {
	4, 5, 6, 7, 8, 9, 10
};

SegmentScreen *screens[] = {
	new SegmentScreen(cathodePins, 2),
	new SegmentScreen(cathodePins, 3),	
	new SegmentScreen(cathodePins, 1),
	new SegmentScreen(cathodePins, 0)	
};

SegmentLayout layout(screens, 4);

Thermistor thermistor(A0);

Morse morse(11);

void setup() {	
	layout.init();
	morse.setText("I LOVE EMBENDED");
}

void loop() {
	// Prints temperature two digit(two 7 segment screen)
	layout.setText(String(thermistor.getCelciusI()));
	// This switchs screen with delay specifid in library.
 	layout.refresh();
	morse.refresh();
}