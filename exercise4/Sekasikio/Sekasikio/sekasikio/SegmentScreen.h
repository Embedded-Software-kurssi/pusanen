/*
 * SegmentScreen.h
 *
 * Created: 13.10.2016 12.51.48
 *  Author: pusan
 */ 


#ifndef SEGMENTSCREEN_H_
#define SEGMENTSCREEN_H_

#include "Arduino.h"

class IHardware
{
	private:

	public:
	virtual void showSegment(char o) = 0;
	virtual void delay(int d) = 0;
};

class SegmentScreen
{
	private:
	char *cathodePins;
	int AdnodePin = 0;

	IHardware *hardware;
	
	void bitAction(char b, char pin);

	public:
	SegmentScreen(char *cathodePins, char anodePin);
	~SegmentScreen();

	void clear();
	void show(char c);
	void turnOn();
	void turnOff();
};

class SegmentLayout
{
	private:
	SegmentScreen **segmentScreens;

	IHardware *hardware;

	String text;

	int count;
	char currentSegementScreen = 0;
	int slideDelay;
	int currentSlideIndex = 0;

	char minRefreshDelay = 10;
	long lastRefresh = 0;

	public:
	SegmentLayout(SegmentScreen *segmentScreens[], int count);
	~SegmentLayout();

	void setText(String text);
	void refresh();
};



#endif /* SEGMENTSCREEN_H_ */