#include "PotentiometerControl.h"

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
 _value = map(analogRead(_pin), 1, 1022, 0, 100);
 return _value;
}
