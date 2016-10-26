// Author: Teemu Pusa Jarmo Pesonen

#ifndef MORSE_H_
#define MORSE_H_

#include "Arduino.h"

class Morse {
	char ledPin = 0;
	int dotDelay = 400;
	int dashDelay = 800;
	int letterDelay = 400;
	int blinkDelay = 600;
	int repeatDelay = 2000;
	
	char repeatDelayOn = 0;
	char ledOn = 0;

	long ledOnDuration = 0;
	long ledOffDuration = 0;

	char bitType = 0;

	int charIndex = 0;
	int bitIndex = 0;
	int maxBits = 0;

	String text;

	void next();
	void bitAction(char b);
	public:
	Morse(char ledPin);
	~Morse();

	void setText(String text);
	void refresh();
};



#endif /* MORSE_H_ */