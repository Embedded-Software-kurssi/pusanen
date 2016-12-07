
#include <Arduino.h>
#include "EnableInterrupt.h"
#include "SegmentScreen.h"
#include "Thermistor.h"

void startTimer2();
void stopTimer2();
void initTimer2();

void initTimer();
void startTimer();
void stopTimer();

void buttonPressed();

int button1pin = A0;
int button2pin = A1;
int button3pin = A2;

bool BUTTON1_PRESSED = false;
bool BUTTON2_PRESSED = false;
bool BUTTON3_PRESSED = false;

char PROGRAM_MODE = 0;

char cathodePins[7] = {
	4, 5, 6, 7, 8, 9, 10
};

SegmentScreen *screens[] = {
	new SegmentScreen(cathodePins, 2),
	new SegmentScreen(cathodePins, 3),
	new SegmentScreen(cathodePins, 11),
	new SegmentScreen(cathodePins, 12),
};

SegmentLayout layout(screens, 4);

Thermistor t(A3);

int hours = 15;
int minutes = 30;
int seconds = 0;

char mode = 0;

void setup() {
	pinMode(button1pin, INPUT);
	pinMode(button2pin, INPUT);
	pinMode(button3pin, INPUT);
	enableInterrupt(button1pin, buttonPressed, RISING);
	enableInterrupt(button2pin, buttonPressed, RISING);
	enableInterrupt(button3pin, buttonPressed, RISING);
	layout.init();
	initTimer();
	initTimer2();
	startTimer();
}

void loop() {	
	if (BUTTON1_PRESSED) {
		hours+= 1;
		if (hours > 23) hours = 0;
		BUTTON1_PRESSED = false;				
	}
	if (BUTTON2_PRESSED) {
		minutes+= 1;
		if (minutes > 59) minutes = 0;
		BUTTON2_PRESSED = false;
	}
	if (BUTTON3_PRESSED) {
		PROGRAM_MODE = !PROGRAM_MODE;
		BUTTON3_PRESSED = false;
	}
	if (PROGRAM_MODE == 0) {
		String h, m, s;
		if (hours < 10) h = String('0') + String(hours);
		else h = String(hours);
		if (minutes < 10) m = String('0') + String(minutes);
		else m = String(minutes);
		if (seconds < 10) s = String('0') + String(seconds);
		else s = String(seconds);
		layout.setText(h+m+s);
	} else {
		volatile int i = t.getCelciusI();
		volatile String s = String(i);
		layout.setText(String(t.getCelciusI()));
	}
	layout.refresh();
}

void buttonPressed() {
	startTimer2();
}

ISR(TIMER2_COMPA_vect) {
	stopTimer2();
	BUTTON1_PRESSED = digitalRead(button1pin);
	BUTTON2_PRESSED = digitalRead(button2pin);
	BUTTON3_PRESSED = digitalRead(button3pin);
}

void startTimer2() {
	TCNT2  = 0;
	TIMSK2 |= (1 << OCIE2A);
}

void stopTimer2() {
	TIMSK2 &= ~(1 << OCIE2A);
}

void initTimer2() {
	//set timer0 interrupt at 500Hz
	TCCR2A = 0;// set entire TCCR0A register to 0
	TCCR2B = 0;// same for TCCR0B
	TCNT2  = 0;//initialize counter value to 0
	// set compare match register for 500Hz increments
	OCR2A = 46;// = (16*10^6) / (500*64) - 1 (must be <256)
	// turn on CTC mode
	TCCR2A |= (1 << WGM21);
	// Set CS02 for 256 prescaler
	TCCR2B |= (1 << CS12) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK2 &= ~(1 << OCIE2A);
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

void startTimer() {
	TCNT1  = 0;
	TIMSK1 |= (1 << OCIE2A);
}

void stopTimer() {
	TIMSK1 &= ~(1 << OCIE2A);
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