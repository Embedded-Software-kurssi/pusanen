#ifndef CodeLock_h
#define CodeLock_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

bool Compare(const char* code1, const char* code2, int len);

class CodeLock {
public:
  CodeLock();

  void Set_code(const char *code);
  void Insert_code(const char* character);
  bool isSuccess();

  void Set_max_password_length(int len);
private:

  //void String_append(const char* character, const char* str);

  int maxPasswordLength;
  int guessCodeIndex = 0;
  int *buttonPins;
  int greenLed;
  int redLed;

  bool rightCode;

  char *lockCode;
  char *guessCode;
  int codeLenght;
};

#endif
