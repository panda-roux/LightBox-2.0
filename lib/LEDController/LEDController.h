// LEDController.h
#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>
#include <LEDStrip.h> // Replace with the actual name of your LED class

#define MAX_CHANGES 16

class LEDController {
public:
    LEDController(LEDStrip& ledStrip);
    void updateLEDs(int changedPins[MAX_CHANGES], uint8_t numChanges);
    void printActivations(int changedPins[MAX_CHANGES], uint8_t numChanges);

private:
    LEDStrip& _ledStrip;
};

#endif
