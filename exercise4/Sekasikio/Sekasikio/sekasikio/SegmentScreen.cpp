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


 //unsigned char numbers[10] = {
	 //255, // 0
	 //192, // 1
	 //218, // 2
	 //242, // 3
	 //102, // 4
	 //182, // 5
	 //62,  // 6
	 //224, // 7
	 //254, // 8
	 //230, // 9
 //};

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

 void SegmentScreen::bitAction(char b, char pin) {
	 if (!b) {
		 digitalWrite(pin, HIGH);
	 }
	 else {
		 digitalWrite(pin, LOW);
	 }
 }

 SegmentScreen::SegmentScreen(char *cathodePins, char anodePin) {
	this->cathodePins = cathodePins;
	this->AdnodePin = anodePin;
 }

 SegmentScreen::~SegmentScreen() {

 }

 void SegmentScreen::clear() {

 }

void SegmentScreen::turnOn() {
	digitalWrite(AdnodePin, HIGH);
}

void SegmentScreen::turnOff() {
	digitalWrite(AdnodePin, LOW);
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