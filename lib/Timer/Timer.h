#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

class Timer
{
  public:
    Timer();
    void reset();
    bool check();
    unsigned long getInterval();
    void tick();
    unsigned long tock();
    void setInterval(unsigned long interval);
  private:
    unsigned long _interval;
    unsigned long _previousMillis;
    unsigned long _now;
    unsigned long _cycleTime;
    unsigned long _tickValue;
};

#endif
