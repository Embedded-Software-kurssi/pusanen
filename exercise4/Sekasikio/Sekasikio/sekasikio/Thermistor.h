/*
 * Thermistor.h
 *
 * Created: 25.10.2016 12.04.49
 *  Author: pusan
 */ 


#ifndef THERMISTOR_H_
#define THERMISTOR_H_

class Thermistor
{
	char thermistorPin = 0;

	float convertValueToCelcius(int value);
	public:
	Thermistor(char thermistorPin);
	~Thermistor();

	int getValue();
	float getCelciusF();
	int getCelciusC();
};

#endif /* THERMISTOR_H_ */