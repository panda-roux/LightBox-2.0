#ifndef PotentiometerControl_h
#define PotentiometerControl_h
#include <Arduino.h>

class PotentiometerControl {
public:
 PotentiometerControl(int pin);
 void begin();
 int getValue();
 int getMappedValue();
 
private:
 int _pin;
 int _value;
};

#endif
