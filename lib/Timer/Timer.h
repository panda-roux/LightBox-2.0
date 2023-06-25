#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

class Timer
{
  public:
    Timer(unsigned long interval);
    void reset();
    bool check();
    unsigned long getInterval();
  private:
    unsigned long _interval;
    unsigned long _previousMillis;
};

#endif
