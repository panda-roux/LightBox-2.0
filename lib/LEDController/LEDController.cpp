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
