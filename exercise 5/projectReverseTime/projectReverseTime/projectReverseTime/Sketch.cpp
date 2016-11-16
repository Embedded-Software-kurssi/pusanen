
#include <Arduino.h>
#include "SegmentScreen.h"
#include "Thermistor.h"
#include "Morse.h"

const char buttonPin1 = A1;
const char buttonPin2 = A2;
const char buttonPin3 = A3;

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

int hours = 15;
int minutes = 30;
int seconds = 0;

char button1State = 0;
char button2State = 0;
char button3State = 0;

char mode = 0;

Morse morse(11);

void initTimer();


void setup() {
	layout.init();
	pinMode(buttonPin1, INPUT);
	pinMode(buttonPin2, INPUT);
	pinMode(buttonPin3, INPUT);
	initTimer();
}

void loop() {
	button1State = digitalRead(buttonPin1);
	button2State = digitalRead(buttonPin2);
	button3State = digitalRead(buttonPin3);
	if (button1State) {
		hours++;
		if (hours > 59) hours = 0;
		button1State = 0;
	}
	if (button2State) {
		minutes++;
		if (minutes > 59) minutes = 0;
		button2State = 0;
	}
	if (button3State) {
		mode = !mode;
		button3State = 0;
	}
	if (mode) {
		layout.setText(String(thermistor.getCelciusI()));
	} else {
		layout.setText(String(hours) + String(minutes));
		morse.setText(String(hours) + String(minutes));
	}
	layout.refresh();
	morse.refresh();
}

void initTimer() {
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);	
}


ISR(TIMER1_COMPA_vect){
	seconds++;
	if (seconds > 59) {
		seconds = 0;
		minutes++;		
		if (minutes > 59) {
			minutes = 0;
			hours++;
			if (hours > 23) {
				hours = 0;
			}
		}
	}
}