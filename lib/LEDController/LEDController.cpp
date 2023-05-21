// LEDController.cpp
#include "LEDController.h"

LEDController::LEDController(LEDStrip& ledStrip)
    : _ledStrip(ledStrip)
{}

void LEDController::updateLEDs(int changedPins[MAX_CHANGES], uint8_t numChanges) {
    for (uint8_t i = 0; i < numChanges; i++) {
        int ledNumber = changedPins[i]; // Map pin number to LED number
        // Update the LED color based on the pin state
        // Here, you would add your logic for setting the LED colors
        // For example: _ledStrip.setLEDColor(ledNumber, RED, GREEN, BLUE);
    }
}

void LEDController::printActivations(int changedPins[MAX_CHANGES], uint8_t numChanges) {
    for (uint8_t i = 0; i < numChanges; i++) {
        Serial.print("Pin ");
        Serial.print(changedPins[i]);
        Serial.println(" activated");
    }
}
