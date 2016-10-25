/*
 * Thermistor.cpp
 *
 * Created: 25.10.2016 12.05.04
 *  Author: pusan
 */ 

 #include "Thermistor.h"
 #include "Arduino.h"

 int voltageValues[32] = {
	 250,
	 275,
	 300,
	 325,
	 350,
	 375,
	 400,
	 425,
	 450,
	 475,
	 500,
	 525,
	 550,
	 575,
	 600,
	 625,
	 650,
	 675,
	 700,
	 725,
	 750,
	 775,
	 800,
	 825,
	 850,
	 875,
	 900,
	 925,
	 950,
	 975,
	 1000
 };

 float temperatureValues[32] = {
	 1.4,
	 4.0,
	 6.4,
	 8.8,
	 11.1,
	 13.4,
	 15.6,
	 17.8,
	 20.0,
	 22.2,
	 24.4,
	 26.7,
	 29.0,
	 31.3,
	 33.7,
	 36.1,
	 38.7,
	 41.3,
	 44.1,
	 47.1,
	 50.2,
	 53.7,
	 55.0,
	 61.5,
	 66.2,
	 71.5,
	 77.9,
	 85.7,
	 90.3,
	 96.0,
	 111.2,
	 139.5
 };

 Thermistor::Thermistor(char thermistorPinn)
 {
	 this->thermistorPin = thermistorPinn;
	 pinMode(thermistorPin, INPUT);
 }


 Thermistor::~Thermistor()
 {
 }

 float Thermistor::convertValueToCelcius(int value) {
	 if (value <= voltageValues[0]) return temperatureValues[0];
	 if (value >= voltageValues[30]) return temperatureValues[31];
	 for (int i = 0; i < 32; i++) {
		 if (value == voltageValues[i]) {
			 return temperatureValues[i];
		 }
		 if (value < voltageValues[i]) {
			 int diff = voltageValues[i] - voltageValues[i-1];
			 float tempDiff = temperatureValues[i] - temperatureValues[i - 1];
			 float tempStep = tempDiff / diff;
			 return temperatureValues[i - 1] + tempStep * (value - voltageValues[i - 1]);

		 }
	 }
 }

 int Thermistor::getValue() {
	 return 0;
 }

 float Thermistor::getCelciusF() {
	int val = digitalRead(thermistorPin);
	 return convertValueToCelcius(val);
 }

int Thermistor::getCelciusC() {
int val = analogRead(thermistorPin);
	return convertValueToCelcius(val);
 }
