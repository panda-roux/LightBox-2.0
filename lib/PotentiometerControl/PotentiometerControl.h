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

PotentiometerControl::PotentiometerControl(int pin) {
  _pin = pin;
}

void PotentiometerControl::begin() {
  pinMode(_pin, INPUT);
}

int PotentiometerControl::getValue() {
  _value = analogRead(_pin);
  return _value;
}

int PotentiometerControl::getMappedValue() {
  _value = map(analogRead(_pin), 0, 1023, 0, 100);
  return _value;
}

#endif
