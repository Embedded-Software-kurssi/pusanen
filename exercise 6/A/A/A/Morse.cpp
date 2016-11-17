/*
 * Morse.cpp
 *
 * Created: 17.11.2016 9.06.13
 *  Author: jaska
 */ 
 

  #include <Arduino.h>
  #include "morse.h"

  #define BIT5 16
  #define BIT4 8
  #define BIT3 4
  #define BIT2 2
  #define BIT1 1

  #define LED_PIN 13

  char characters[] = {
	  37, //A
	  56, //B
	  58, //C
	  22, //D
	  34, //E
	  50, //F
	  46, //G
	  63, //H
	  36, //I
	  55, //J
	  45, //K
	  52, //L
	  39, //M
	  38, //N
	  47, //O
	  54, //P
	  61, //Q
	  42, //R
	  40, //S
	  35, //T
	  49  //U
  };

  void bitAction(char b) {
	  if (b > 0) {
		  digitalWrite(LED_PIN, HIGH);
		  delay(500);
		  digitalWrite(LED_PIN, LOW);
		  delay(400);
		  } else {
		  digitalWrite(LED_PIN, HIGH);
		  delay(200);
		  digitalWrite(LED_PIN, LOW);
		  delay(400);
	  }
  }

int showText(String text) {
	int count = 0;
	  for (int i = 0; i < text.length(); i++) {
		  char merkki = characters[text[i] - 65];
		  if (merkki & BIT5) {
			  bitAction(merkki & BIT4);
			  bitAction(merkki & BIT3);
			  bitAction(merkki & BIT2);
			  bitAction(merkki & BIT1);
			  count += 4;
		  }
		  else if (merkki & BIT4) {
			  bitAction(merkki & BIT3);
			  bitAction(merkki & BIT2);
			  bitAction(merkki & BIT1);
			  count += 3;
		  }
		  else if (merkki & BIT3) {
			  bitAction(merkki & BIT2);
			  bitAction(merkki & BIT1);
			  count += 2;
		  }
		  else if (merkki & BIT2) {
			  bitAction(merkki & BIT1);
			  count += 1;
		  }
	  }
	  return count;
  }