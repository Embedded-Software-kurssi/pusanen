
#include <Arduino.h>
#include "farenheit.h"
#include "morse.h"
#include "SOS.h"

void assigmentSix();

void setup() {
	pinMode(13, OUTPUT);
}

void loop(){
	showText("SOS");
	assigmentSix();
	BlinkThreeDots();
	BlinkThreeDashes();
	BlinkThreeDots();
}


void assigmentSix() {
// Is Volatile because compiler otherwise optimizes variable away because it is not in use.
// Thus makeing debuging impossiple.
	volatile float lampotila;
	lampotila=toFarenheit (1);
	lampotila=toFarenheit (5.0);
	lampotila=toFarenheit (10);
	lampotila=toFarenheit (25);

	volatile float temperature;
	temperature=toCelsius (1);
	temperature=toCelsius (5);
	temperature=toCelsius (10);
	temperature=toCelsius (25);
}