#include "Arduino.h"
#include "Timer.h"

Timer::Timer(unsigned long interval)
{
  _interval = interval;
}

void Timer::reset()
{
  _previousMillis = millis();
}

bool Timer::check()
{
  unsigned long currentMillis = millis();
  if(currentMillis - _previousMillis >= _interval) {
    _previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}

unsigned long Timer::getInterval()
{
  return _interval;
}
