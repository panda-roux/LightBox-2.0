// LEDController.cpp
#include "LEDController.h"
#include <PotentiometerControl.h>
#include <Timer.h>

LEDController::LEDController(LEDStrip& ledStrip,PotentiometerControl& Pod)
    : _strip(ledStrip), _potentiometer(Pod)
{}

void LEDController::red_high_reg(int i){
  _strip.setBrightness(i, 255, 0, 0, _potentiometer.getMappedValue());

}

void LEDController::green_high_reg(int i){
  _strip.setBrightness(i, 0, 255, 0, _potentiometer.getMappedValue());

}

void LEDController::blue_high_reg(int i){
  _strip.setBrightness(i, 0, 0, 255, _potentiometer.getMappedValue());

}

void LEDController::led_off (int i){
  _strip.setLEDColor(i, 0, 0, 0);

}


void LEDController::updateLEDs(int changedPins[MAX_CHANGES], uint8_t numChanges) {
  for (uint8_t i = 0; i < numChanges; i++) {
    int ledNumber = changedPins[i]; // Map pin number to LED number
    // Update the LED color based on the pin state
    if (digitalRead(ledNumber) == HIGH) {
      _strip.setLEDColor(ledNumber, 255, 0, 0); // Set the LED to red when the pin is HIGH
    } else {
      _strip.setLEDColor(ledNumber, 0, 0, 0); // Set the LED to off when the pin is LOW
    }
  }
}

