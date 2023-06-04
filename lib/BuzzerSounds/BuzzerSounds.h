#ifndef BuzzerSounds_h
#define BuzzerSounds_h

#include "Arduino.h"

class BuzzerSounds
{
  public:
    BuzzerSounds(int pin);
    void lowFrequencyBeep();
    void playMarioCoin();
    void playR2D2();
  private:
    int _pin;
};

#endif
