#ifndef LightBox2_0_h
#define LightBox2_0_h

#include "Arduino.h"

class LightBox2_0 {
  public:
    LightBox2_0();
    void setup();
    void loop();
    void checkSerial();
    void present();
    void past();
  private:
    unsigned long _startTime;
};

#endif
