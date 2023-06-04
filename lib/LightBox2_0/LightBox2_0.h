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
    void DEBUG_mode();
    void db_Potentiometer();
  private:
    unsigned long _startTime;
};

#endif
