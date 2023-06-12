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
    void db_mode();
    
    void LigthBox_one();
    void tick();
    void tock();
    
  private:
    unsigned long _startTime;
    unsigned long _tickIn;
    unsigned long _tockOut;
    
    

};

#endif
