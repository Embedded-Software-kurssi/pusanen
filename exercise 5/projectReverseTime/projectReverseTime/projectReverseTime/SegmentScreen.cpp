/*
 * SegmenScreen.cpp
 *
 * Created: 13.10.2016 12.51.24
 *  Author: pusan
 */ 


 #include "SegmentScreen.h"

 #include <stdio.h>
 #include <string.h>

 #include <Arduino.h>

 unsigned char numbers[10] = {
	 254, // 0
	 176, // 1
	 237, // 2
	 249, // 3
	 179, // 4
	 219, // 5
	 159,  // 6
	 240, // 7
	 255, // 8
	 243, // 9
 };

 #define BIT8 128
 #define BIT7 64
 #define BIT6 32
 #define BIT5 16
 #define BIT4 8
 #define BIT3 4
 #define BIT2 2
 #define BIT1 1

 SegmentCounter::SegmentCounter(SegmentLayout *layout) {
	this->layout = layout;
 }

 SegmentCounter::~SegmentCounter() {

 }

 void SegmentCounter::refresh() {
	long currentTime = millis();
	if (currentTime-lastSwitch > delay) {
		index++;
		if (index > length) index = 0;
		volatile char c = this->stringSeq[0][0];
		layout->setText(stringSeq[index]);
		lastSwitch = currentTime;
	}
 }

 void SegmentCounter::setText(String *stringSeq, int length) {
 
	this->stringSeq = stringSeq;
	volatile char a = this->stringSeq[0][0];
	this->length = length;
	this->index = 0;
	lastSwitch = millis();
 }

 void SegmentScreen::bitAction(char b, char pin) {
	 if (!b) {
		 digitalWrite(pin, HIGH);
	 }
	 else {
		 digitalWrite(pin, LOW);
	 }
 }

 SegmentScreen::SegmentScreen(char cathodePins[7], char anodePin) {
	this->cathodePins = cathodePins;
	this->anodePin = anodePin;
 }

 SegmentScreen::~SegmentScreen() {

 }

 void SegmentScreen::clear() {

 }

void SegmentScreen::turnOn() {
	digitalWrite(anodePin, HIGH);
}

void SegmentScreen::turnOff() {
	digitalWrite(anodePin, LOW);
}

void SegmentScreen::init() {
	for (int i = 0; i < 7; i++) {
		volatile int p = cathodePins[i];
		pinMode(cathodePins[i], OUTPUT);
		digitalWrite(cathodePins[i], HIGH);
	}
	pinMode(anodePin, OUTPUT);
	digitalWrite(anodePin, HIGH);
}

 void SegmentScreen::show(char c) {
	 if (c > 47 && c < 58) {
		 bitAction(BIT7 & numbers[c - 48], 4);
		 bitAction(BIT6 & numbers[c - 48], 5);
		 bitAction(BIT5 & numbers[c - 48], 6);
		 bitAction(BIT4 & numbers[c - 48], 7);
		 bitAction(BIT3 & numbers[c - 48], 8);
		 bitAction(BIT2 & numbers[c - 48], 9);
		 bitAction(BIT1 & numbers[c - 48], 10);
	 }
 }

 SegmentLayout::SegmentLayout(SegmentScreen *segmentScreens[], int count) {
	 this->segmentScreens = segmentScreens;
	 this->count = count;
 }

 SegmentLayout::~SegmentLayout() {

 }

 void SegmentLayout::setText(String text) {
	this->text = text;
	//currentSegementScreen = 0;
	//currentSlideIndex = 0;
 }

 void SegmentLayout::refresh() {
	for (int i = 0; i < count; i++) {
		if (currentSegementScreen == i) {
			segmentScreens[currentSegementScreen]->turnOn();
			segmentScreens[currentSegementScreen]->show(text[currentSegementScreen]);
		} else {
			segmentScreens[i]->turnOff();
		}
	}
	long currentTime = millis();
	if (currentTime -lastRefresh > minRefreshDelay) {
		lastRefresh = currentTime;
		currentSegementScreen++;
		if (currentSegementScreen >= count) currentSegementScreen = 0;
	}	
 }

 void SegmentLayout::init() {
	for (int i = 0; i < count; i++) {
		segmentScreens[i]->init();
	}
 }

 void SegmentLayout::setMinRefreshDuration(int duration) {
	this->minRefreshDelay = duration;
 }