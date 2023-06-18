#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#include <Arduino.h>
#include <LEDStrip.h> // LED class
#include <PotentiometerControl.h>



#define MAX_CHANGES 16


class LEDController {
public:
 LEDController(LEDStrip& ledStrip,PotentiometerControl& Pod);
 void updateLEDs(int changedPins[MAX_CHANGES], uint8_t numChanges);
 void printActivations(int changedPins[MAX_CHANGES], uint8_t numChanges);
 void red_high_reg(int i);
 void green_high_reg(int i);
 LEDStrip& _strip;
 PotentiometerControl& _potentiometer;
private:
 
};
#endif
