#include "Arduino.h"
#include "Timer.h"

Timer::Timer()
{
  tock();
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

void Timer::tick(){
  _tickValue = millis();

}

void Timer::setInterval(unsigned long interval) {
  _interval = interval;
}


unsigned long Timer::tock(){
  _now = millis();
  _cycleTime = _now - _tickValue;

  return _cycleTime;

}
