#ifndef SegmentScreen_h
#define SegmentScreen_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class SegmentScreen {
public:
  SegmentScreen();
  void Set_segmentpins(int *vector);
  void Show_text(const char* text, int delayTime);
  void Set_blank();
  void Demo();
private:
  int *segmentPins;

  bool **Set_text(const char* text, int &numberOfChars);
};

#endif
