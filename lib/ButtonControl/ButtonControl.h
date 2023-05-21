#ifndef ButtonControl_h
#define ButtonControl_h

#include <Arduino.h>

class ButtonControl {
public:
  ButtonControl(int pin);
  void begin();
  bool isPressed();
  
private:
  int _pin;
};

ButtonControl::ButtonControl(int pin) {
  _pin = pin;
}

void ButtonControl::begin() {
  pinMode(_pin, INPUT_PULLUP);
}

bool ButtonControl::isPressed() {
  return digitalRead(_pin) == LOW;
}

#endif
