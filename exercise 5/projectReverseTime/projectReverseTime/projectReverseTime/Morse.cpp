/*
 * Morse.cpp
 *
 * Created: 25.10.2016 11.52.06
 *  Author: Teemu Pusa
 */ 

#include "Morse.h"

 #define BIT5 16
 #define BIT4 8
 #define BIT3 4
 #define BIT2 2
 #define BIT1 1

const char BITS[4] = {
  8,
  4,
  2,
  1
};

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

Morse::Morse(char ledPin) {
  this->ledPin = ledPin;
  pinMode(ledPin, OUTPUT);
}

Morse::~Morse() {

}

void Morse::next() {
    digitalWrite(ledPin, LOW);
    ledOn = 0;
    bitIndex++;
    if (bitIndex >= maxBits) {
      charIndex++;
      maxBits = 0;
      if (text.length() <= charIndex) {
        charIndex = 0;
        repeatDelayOn = 1;
      }
      bitIndex = 0;
    }
}

void Morse::setText(String text) {
  this->text = text;
}

void Morse::refresh() {
  long currentTime = millis();
  if (ledOn) {
    char c = characters[text[charIndex]-65];
    if (c & BITS[bitIndex+4-maxBits]) {
      if (currentTime - ledOnDuration > dashDelay) {
        next();
        ledOffDuration = currentTime;
      }
    } else {
      if (currentTime - ledOnDuration > dotDelay) {
        next();
        ledOffDuration = currentTime;
      }
    }
  } else {
    if (repeatDelayOn) {
      if (currentTime - ledOffDuration > repeatDelay) {
         repeatDelayOn = 0;
      }      
    } else {
    if (currentTime - ledOffDuration > blinkDelay) {
      if (maxBits == 0) {
        char c = characters[text[charIndex]-65];
        if (c & BIT5) {
          maxBits = 4;
        }
        else if (c & BIT4) {
          maxBits = 3;
        }
        else if (c & BIT3) {
          maxBits = 2;
        }
        else if (c & BIT2) {
          maxBits = 1;
        }
      }
      ledOnDuration = currentTime;
      digitalWrite(ledPin, HIGH); 
      ledOn = 1;       
    }
    }
  }
}