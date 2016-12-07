// Sketch.cpp
// Author: Sanna Maatta
// This program demonstrates some interesting things
// (Note that some variables are not consts (or local variables), even if they could be)


#include <Arduino.h>

// Variables for example 1
const double number1 = 20.1;
const double number2 = 20.0;
const double number3 = 0.1;
volatile int result = 0;

// Variables for example 2
float base = 2.00001;
float exponent = 3;
double powerOfDouble = 0;
int powerOfInt = 0;

// Variables for example 3
int first = 8;
int second = 10;

// Variables for example 4
int multiplication = 1;
int division = 1024;


void setup() {
	
}

void loop() {

	// Example 1 starts, why is result not 0 when it should (20.1 - 20.0 - 0.1 = 0)?

	result = (number1 - number2 - number3);

	// Example 1 ends


	// Example 2 starts, why is the powerOfDouble 7,999998 and powerOfInt 7 and not 8?

	powerOfDouble = pow(base, exponent);
	powerOfInt = pow(base, exponent);

	// Example 2 ends


	// Example 3: what does the following code do?

	first = first ^ second;
	second = first ^ second;
	first = first ^ second;

	// Example 3 ends


	// Example 4: what does the code do?

	multiplication = (multiplication << 1);
	division = (division >> 1);

	// Example 4 ends
}
