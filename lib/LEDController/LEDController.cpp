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

void LEDController::clockTick(){
  _timerHigh.reset();
  _timerLow.reset();
}

void LEDController::clockTock(){
  _timerHigh.tock();
  _timerLow.tock();

}

void LEDController::blinkUninterruptibleR(int ledIndex, unsigned long intervalHigh, unsigned long intervalLow) {
  if (!_isHigh && _timerLow.check()) {
    _strip.setLEDColor(ledIndex, 0, 0, 0);  // Turn off the LED
    _timerLow.reset();  // Reset the timer
    _timerLow.setInterval(intervalLow);  // Set the interval for the LOW state
    _isHigh = true;
  }
  else if (_isHigh && _timerHigh.check()) {
    _strip.setBrightness(ledIndex, 255, 0, 0, _potentiometer.getMappedValue());  // Turn on the LED
    _timerHigh.reset();  // Reset the timer
    _timerHigh.setInterval(intervalHigh);  // Set the interval for the HIGH state
    _isHigh = false;
  }
}

  void LEDController::blinkUninterruptibleG(int ledIndex, unsigned long intervalHigh, unsigned long intervalLow) {
  if (!_isHigh && _timerLow.check()) {
    _strip.setLEDColor(ledIndex, 0, 0, 0);  // Turn off the LED
    _timerLow.reset();  // Reset the timer
    _timerLow.setInterval(intervalLow);  // Set the interval for the LOW state
    _isHigh = true;
  }
  else if (_isHigh && _timerHigh.check()) {
    _strip.setBrightness(ledIndex, 0, 255, 0, _potentiometer.getMappedValue());  // Turn on the LED
    _timerHigh.reset();  // Reset the timer
    _timerHigh.setInterval(intervalHigh);  // Set the interval for the HIGH state
    _isHigh = false;
  }
  }

  void LEDController::blinkUninterruptibleB(int ledIndex, unsigned long intervalHigh, unsigned long intervalLow) {
  if (!_isHigh && _timerLow.check()) {
    _strip.setLEDColor(ledIndex, 0, 0, 0);  // Turn off the LED
    _timerLow.reset();  // Reset the timer
    _timerLow.setInterval(intervalLow);  // Set the interval for the LOW state
    _isHigh = true;
  }
  else if (_isHigh && _timerHigh.check()) {
    _strip.setBrightness(ledIndex, 0, 0, 255, _potentiometer.getMappedValue());  // Turn on the LED
    _timerHigh.reset();  // Reset the timer
    _timerHigh.setInterval(intervalHigh);  // Set the interval for the HIGH state
    _isHigh = false;
  }
}

