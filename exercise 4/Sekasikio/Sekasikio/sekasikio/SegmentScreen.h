/*
 * SegmentScreen.h
 *
 * Created: 13.10.2016 12.51.48
 *  Author: Teemu Pusa Jarmo Pesonen
 */ 


#ifndef SEGMENTSCREEN_H_
#define SEGMENTSCREEN_H_

#include "Arduino.h"

class SegmentScreen
{
	private:
	char *cathodePins;
	int anodePin = 0;
	
	void bitAction(char b, char pin);

	public:
	SegmentScreen(char cathodePins[7], char anodePin);
	~SegmentScreen();

	void clear();
	void show(char c);
	void turnOn();
	void turnOff();
	void init();
};

class SegmentLayout
{
	private:
	SegmentScreen **segmentScreens;

	String text;

	int count;
	char currentSegementScreen = 0;
	int slideDelay;
	int currentSlideIndex = 0;

	char minRefreshDelay = 2;
	long lastRefresh = 0;

	public:
	SegmentLayout(SegmentScreen *segmentScreens[], int count);
	~SegmentLayout();

	void setText(String text);
	void refresh();
	void init();
};

#endif /* SEGMENTSCREEN_H_ */